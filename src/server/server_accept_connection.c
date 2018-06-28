/*
** EPITECH PROJECT, 2018
** singe
** File description:
** singe
*/

#include "server.h"

static client_t *server_get_open_client_slot(server_t *server)
{
	for (int i = 0; i < MAX_CLIENTS; i++)
		if (server->clients[i].open == true)
			return &server->clients[i];
	return NULL;
}

static int server_init_slot(server_t *server, client_t *client, int fd)
{
	client->fd = fd;
	client->open = false;
	client->buffer = NULL;
	client->direction = NORTH;
	client->pos_x = rand() % server->flag.width;
	client->pos_y = rand() % server->flag.height;
	return 0;
}

static int server_accept_client(server_t *server)
{
	int cfd;
	client_t *new;
	struct sockaddr_in caddr;
	socklen_t csize = sizeof(caddr);

	cfd = accept(server->fd, (struct sockaddr *)&caddr, &csize);
	if (cfd == -1) {
		fprintf(stdout, "Can't accept new client.\n");
		return -1;
	}
	new = server_get_open_client_slot(server);
	if (!new) {
		fprintf(stdout, "Maximum number of client reached.\n");
		close(cfd);
		return -1;
	}
	server_init_slot(server, new, cfd);
	write(new->fd, "Welcome!\n", strlen("Welcome!\n"));
	return 0;
}

int server_accept_connection(server_t *server)
{
	if (FD_ISSET(server->fd, &server->rfds) == 0)
		return 0;
	fprintf(stdout, "New client request.\n");
	if (server_accept_client(server) != 0) {
		fprintf(stdout, "New client rejected.\n");
		return -1;
	}
	fprintf(stdout, "New client accepted.\n");
	return 0;
}