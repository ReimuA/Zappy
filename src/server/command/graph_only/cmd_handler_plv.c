/*
** EPITECH PROJECT, 2018
** singe
** File description:
** singe
*/

#include "server.h"

int cmd_handler_plv(server_t *server, int cli, int argc, char **argv)
{
	char buff[256];
	int target = atoi(argv[1]);
	client_t *client = &server->clients[target];

	(void)argc;
	snprintf(buff, 128, "plv %d %d\n", target, client->level);
	write(server->clients[cli].fd, buff, strlen(buff));
	return 0;
}