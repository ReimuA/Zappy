/*
** EPITECH PROJECT, 2018
** singe
** File description:
** singe
*/

#include "server.h"

int cmd_left_callback(server_t *server, int client_nbr, int argc, char **argv)
{
	int idx = 0;
	client_t *client = &server->clients[client_nbr];
	unsigned int direction[DIRECTION_SIZE] = {
		NORTH,
		EAST,
		SOUTH,
		WEST
	};

	(void)argc;
	(void)argv;
	for (int i = 0; i < DIRECTION_SIZE; i++) {
		if (direction[i] == client->direction)
			idx = (i + 1) % DIRECTION_SIZE;
	}
	client->direction = direction[idx];
	write(client->fd, "ok\n", strlen("ok\n"));
	return 0;
}

int cmd_handler_left(server_t *server, int client, int argc, char **argv)
{
	struct timeval tv;
	suseconds_t ms = 0;
	suseconds_t trigger_date = 0;
	event_parameter_t param = {
		.argc = argc,
		.argv = argv,
		.client_nbr = client
	};

	(void)argc;
	(void)argv;
	gettimeofday(&tv, NULL);
	ms = tv.tv_sec * 1000000 + tv.tv_usec;
	trigger_date = ms + (1000000 / server->flag.freq) * 7;
	event_t *evt = new_event(&param, trigger_date, cmd_left_callback);
	event_list_t *node = event_list_node(evt);
	event_list_insert(&server->event_list, node);
	return 0;
}