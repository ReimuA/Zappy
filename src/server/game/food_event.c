/*
** EPITECH PROJECT, 2018
** singe
** File description:
** singe
*/

#include "server.h"
#include "food_event.h"

int food_event_callback(server_t *server, int cli, int argc, char **argv)
{
	client_t *client = &server->clients[cli];
	int pos_x = rand() % server->flag.width;
	int pos_y = rand() % server->flag.height;

	(void)argc;
	(void)argv;
	client->inventory.food -= 1;
	server->world.map[pos_y][pos_x].food += 1;
	food_event_add_callback(server, cli);
	return 0;
}

int food_event_add_callback(server_t *server, int cli)
{
	struct timeval tv;
	suseconds_t ms = 0;
	suseconds_t trigger = 0;
	event_parameter_t param = {
		.argc = 0,
		.argv = NULL,
		.client_nbr = cli
	};

	gettimeofday(&tv, NULL);
	ms = tv.tv_sec * 1000000 + tv.tv_usec;
	trigger = ms + (1000000 / server->flag.freq) * 126;
	event_t *evt = new_event(&param, trigger, food_event_callback);
	event_list_t *node = event_list_node(evt);
	event_list_insert(&server->event_list, node);
	return 0;
}