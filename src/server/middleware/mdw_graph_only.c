/*
** EPITECH PROJECT, 2018
** singe
** File description:
** singe
*/

#include "server.h"

/*
** Limit access to graphical.
*/

bool mdw_graph_only(server_t *server, int client, int argc, char **argv)
{
	(void)argc;
	if (server->clients[client].graphical == false) {
		fprintf(stdout,
		"\nCommand \'%s\' from client %d rejected: %s\n",
		argv[0],
		client,
		"Only graphical client can access this request.");
		return false;
	}
	return true;
}