/*
** EPITECH PROJECT, 2018
** singe
** File description:
** singe
*/

#include <math.h>
#include "server.h"

static void cmd_broadcast_send_info(server_t *server, int cli, const char *s)
{
	size_t len = strlen(s);
	char buff[1024];

	for (int i = 0; i < MAX_CLIENTS; i++) {
		if (i != cli
			&& server->clients[i].open == false
			&& server->clients[i].team_name != false
			&& server->clients[i].graphical == false) {
			snprintf(buff, 1024, "%s %d, ", "message",
				broadcast_direction(server,
					&server->clients[cli],
					&server->clients[i]));
			write(server->clients[i].fd, buff, strlen(buff));
			write(server->clients[i].fd, s, len);
		}
	}
}

static void cmd_broadcast_graphinfo(server_t *server, int cli, const char *s)
{
	char buff[1024];

	snprintf(buff, 1024, "pbc %d %s", cli, s);
	server_graphical_broadcast(server, buff);
}

int cmd_broadcast_callback(server_t *server, int client, int argc, char **argv)
{
	int size = 0;
	char *tmp = strdup("");

	if (tmp == NULL)
		return -1;
	for (int i = 1; i < argc; i++) {
		size = sizeof(char) * (strlen(tmp) + strlen(argv[i]) + 5);
		tmp = realloc(tmp, size);
		if (tmp == NULL)
			return -1;
		strcat(tmp, argv[i]);
		strcat(tmp, " ");
	}
	strcat(tmp, "\n");
	cmd_broadcast_send_info(server, client, tmp);
	cmd_broadcast_graphinfo(server, client, tmp);
	free(tmp);
	write(server->clients[client].fd, "ok\n", strlen("ok\n"));
	return 0;
}

int cmd_handler_broadcast(server_t *server, int client, int argc, char **argv)
{
	struct timeval tv;
	suseconds_t ms = 0;
	suseconds_t trigger_date = 0;
	event_parameter_t param = {
		.argc = argc,
		.argv = argv,
		.client_nbr = client
	};

	(void)argc;
	(void)argv;
	gettimeofday(&tv, NULL);
	ms = tv.tv_sec * 1000000 + tv.tv_usec;
	trigger_date = ms + (1000000 / server->flag.freq) * 7;
	event_t *evt = new_event(&param, trigger_date, cmd_broadcast_callback);
	event_list_t *node = event_list_node(evt);
	event_list_insert(&server->event_list, node);
	return 0;
}
