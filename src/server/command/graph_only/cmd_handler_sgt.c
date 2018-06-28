/*
** EPITECH PROJECT, 2018
** singe
** File description:
** singe
*/

#include "server.h"

int cmd_handler_sgt(server_t *server, int cli, int argc, char **argv)
{
	char buff[256];

	(void)argc;
	(void)argv;
	(void)cli;
	snprintf(buff, 128, "sgt %d\n", server->flag.freq);
	write(server->clients[cli].fd, buff, strlen(buff));
	return 0;
}