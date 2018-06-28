/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** fd
*/

#include "server.h"

int server_get_fd_max(server_t *server)
{
	int fd = server->fd;

	for (int i = 0; i < MAX_CLIENTS; i++)
		fd = server->clients[i].fd > fd ? server->clients[i].fd : fd;
	return fd;

}

void server_reset_fds(server_t *server)
{
	FD_ZERO(&server->rfds);
	FD_ZERO(&server->wfds);
	FD_ZERO(&server->efds);
	FD_SET(server->fd, &server->rfds);
	for (int id = 0; id < MAX_CLIENTS; id++)
		if (server->clients[id].open == false) {
			FD_SET(server->clients[id].fd, &server->rfds);
			FD_SET(server->clients[id].fd, &server->wfds);
		}
}
