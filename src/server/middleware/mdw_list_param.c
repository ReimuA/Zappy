/*
** EPITECH PROJECT, 2018
** singe
** File description:
** singe
*/

#include "server.h"

/*
** Simply list info.
*/

bool mdw_list_param(server_t *server, int client, int argc, char **argv)
{
	(void)server;
	fprintf(stdout, "\nReceived command \'%s\' from client %d\n",
		argv[0],
		client);
	fprintf(stdout, "\tParam list: {\n");
	for (int i = 1; i < argc; i++)
		fprintf(stdout, "\t\t%s%s\n",
			argv[i],
			i + 1 < argc ? "," : "");
	fprintf(stdout, "\t}\n\n");
	return true;
}
