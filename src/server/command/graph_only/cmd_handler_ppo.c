/*
** EPITECH PROJECT, 2018
** singe
** File description:
** singe
*/

#include "server.h"

int cmd_handler_ppo(server_t *server, int cli, int argc, char **argv)
{
	int dir;
	char buff[256];
	int target = atoi(argv[1]);
	client_t *client = &server->clients[target];
	unsigned int direction[DIRECTION_SIZE] = {
		NORTH, EAST,
		SOUTH, WEST
	};

	(void)argc;
	for (int i = 0; i < DIRECTION_SIZE; i++) {
		if (client->direction == direction[i])
			dir = i + 1;
	}
	snprintf(buff, 256, "ppo %d %d %d %d\n", target, client->pos_x,
		client->pos_y, dir);
	write(server->clients[cli].fd, buff, strlen(buff));
	return 0;
}