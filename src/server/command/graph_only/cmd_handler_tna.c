/*
** EPITECH PROJECT, 2018
** singe
** File description:
** singe
*/

#include "server.h"

int cmd_handler_tna(server_t *server, int cli, int argc, char **argv)
{
	char buff[128];

	(void)argc;
	(void)argv;
	for (int j = 0; server->flag.team_names[j] != NULL; j++) {
		snprintf(buff, 128, "tna %s\n", server->flag.team_names[j]);
		write(server->clients[cli].fd, buff, strlen(buff));
	}
	return 0;
}