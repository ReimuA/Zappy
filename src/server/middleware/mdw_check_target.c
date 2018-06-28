/*
** EPITECH PROJECT, 2018
** singe
** File description:
** singe
*/

#include "server.h"

/*
** Check wether the parameter of the command is a valid client.
*/

bool mdw_check_target(server_t *server, int client, int argc, char **argv)
{
	int target;

	(void)client;
	if (argc < 2)
		return false;
	target = atoi(argv[1]);
	if (target < 0 ||
		target >= MAX_CLIENTS ||
		server->clients[target].open == true ||
		server->clients[target].graphical == true ||
		server->clients[target].team_name == NULL) {
		return false;
	}
	return true;
}