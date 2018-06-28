/*
** EPITECH PROJECT, 2018
** singe
** File description:
** singe
*/

#include "server.h"

int cmd_handler_sst(server_t *server, int cli, int argc, char **argv)
{
	char buff[256];
	int new_freq = 0;


	new_freq = argc == 2 ? atoi(argv[1]) : -1;
	if (new_freq > 0)
		server->flag.freq = new_freq;
	snprintf(buff, 128, "sst %d\n", server->flag.freq);
	write(server->clients[cli].fd, buff, strlen(buff));
	return 0;
}
