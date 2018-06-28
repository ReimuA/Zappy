/*
** EPITECH PROJECT, 2018
** singe
** File description:
** singe
*/

#include "server.h"

int cmd_handler_connect_nbr(server_t *server, int cli, int argc, char **argv)
{
	char buff[32];
	const char *s = server->clients[cli].team_name;
	int connect_nbr = server_get_free_team_slot_nbr(server, s);

	(void)argc;
	(void)argv;
	snprintf(buff, 32, "%d\n", connect_nbr);
	write(server->clients[cli].fd, buff, strlen(buff));
	return 0;
}