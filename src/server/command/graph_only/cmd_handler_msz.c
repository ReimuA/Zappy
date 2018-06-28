/*
** EPITECH PROJECT, 2018
** singe
** File description:
** singe
*/

#include "server.h"

int cmd_handler_msz(server_t *server, int cli, int argc, char **argv)
{
	char buff[128];

	(void)argc;
	(void)argv;
	snprintf(buff, 128, "msz %d %d\n",
		server->flag.width,
		server->flag.height);
	write(server->clients[cli].fd, buff, strlen(buff));
	return 0;
}