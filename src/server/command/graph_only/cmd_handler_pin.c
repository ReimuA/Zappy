/*
** EPITECH PROJECT, 2018
** singe
** File description:
** singe
*/

#include "server.h"

int cmd_handler_pin(server_t *server, int cli, int argc, char **argv)
{
	char buff[256];
	int target = atoi(argv[1]);
	client_t *client = &server->clients[target];
	inventory_t *inv = &client->inventory;

	(void)argc;
	snprintf(buff, 128, "pin %d %d %d %d %d %d %d %d\n", target,
		inv->food,
		inv->linemate,
		inv->deraumere,
		inv->sibur,
		inv->mendiane,
		inv->phiras,
		inv->thystame);
	write(server->clients[cli].fd, buff, strlen(buff));
	return 0;
}