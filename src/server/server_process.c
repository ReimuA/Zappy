/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** loop
*/

#include "server.h"

int server_kick_client(server_t *server, int i)
{
	char buff[64];

	if (server->clients[i].hatched == true)
		snprintf(buff, 64, "edi %d\n", server->clients[i].egg_id);
	else
		snprintf(buff, 64, "pdi %d\n", i);
	server_graphical_broadcast(server, buff);
	write(server->clients[i].fd, "dead\n", strlen("dead\n"));
	event_list_purge(&server->event_list, i);
	client_reset_slot(&server->clients[i]);
	fprintf(stdout, "Client left.\n");
	return 0;
}

void server_graphical_broadcast(server_t *server, const char *s)
{
	for (int i = 0; i < MAX_CLIENTS; i++) {
		if (server->clients[i].open == false &&
			server->clients[i].team_name != NULL &&
			server->clients[i].graphical == true &&
			strcmp(server->clients[i].team_name, "GRAPHIC") == 0) {
			write(server->clients[i].fd, s, strlen(s));
		}
	}
}

static int server_filter_request(server_t *server)
{
	event_list_t *event_list = server->event_list;

	for (int i = 0; i < MAX_CLIENTS; i++) {
		if (server->clients[i].open == true ||
			server->clients[i].buffer == NULL)
			continue;
		if (strchr(server->clients[i].buffer, '\n') != NULL &&
			event_list_nb_client_request(event_list, i) < 2)
			server_handle_clients_cmd(server, i);
	}
	return 0;
}

static int server_handle_clients(server_t *server)
{
	int result;

	for (int i = 0; i < MAX_CLIENTS; i++) {
		if (server->clients[i].open == true)
			continue;
		if (FD_ISSET(server->clients[i].fd, &server->rfds) != true)
			continue;
		result = client_read_chunk(&server->clients[i]);
		if (result == -1)
			server_kick_client(server, i);
	}
	return server_filter_request(server);
}

int server_process(server_t *server)
{
	int fdmax = 0;

	while (game_over(server) == false) {
		server_reset_fds(server);
		fdmax = server_get_fd_max(server);
		if (select(fdmax + 1, &server->rfds, &server->wfds,
			&server->efds, (struct timeval*)0) == -1)
			return -1;
		server_accept_connection(server);
		server_handle_clients(server);
		server_update_game(server);
	}
	return 0;
}
