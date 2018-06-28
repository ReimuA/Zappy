/*
** EPITECH PROJECT, 2018
** singe
** File description:
** singe
*/

#include "server.h"

int cmd_handler_unknown(server_t *server, int client, int argc, char **argv)
{
	(void)argc;
	(void)argv;
	write(server->clients[client].fd, "ko\n", 3);
	return 0;
}