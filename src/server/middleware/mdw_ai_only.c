/*
** EPITECH PROJECT, 2018
** singe
** File description:
** singe
*/

#include "server.h"

/*
** Limit access to AI.
*/

bool mdw_ai_only(server_t *server, int client, int argc, char **argv)
{
	(void)argc;
	if (server->clients[client].graphical == true) {
		fprintf(stdout,
		"\nCommand \'%s\' from client %d rejected: %s\n",
		argv[0],
		client,
		"Only AI client can access this request.");
		return false;
	}
	return true;
}