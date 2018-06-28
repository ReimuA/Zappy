/*
** EPITECH PROJECT, 2018
** singe
** File description:
** singe
*/

#include "server.h"
#include "materials_event.h"

static const int offset_array[] = {
	offsetof(cell_t, linemate),
	offsetof(cell_t, deraumere),
	offsetof(cell_t, sibur),
	offsetof(cell_t, mendiane),
	offsetof(cell_t, phiras),
	offsetof(cell_t, thystame)
};

int materials_event_callback(server_t *server,
	int __attribute__((__unused__))cli,
	int __attribute__((__unused__))argc,
	char __attribute__((__unused__))**argv)
{
	int i = 0;
	int probs = rand() % 100;
	int pos_x = rand() % server->flag.width;
	int pos_y = rand() % server->flag.height;
	char *cell = (char *)&server->world.map[pos_y][pos_x];
	int *cell_resources_ptr = NULL;
	bool probs_array[] = {
		probs < 25,
		probs < 40,
		probs < 65,
		probs < 80,
		probs < 95,
		probs <= 100
	};

	for (i = 0; probs_array[i] == false; i++);
	cell_resources_ptr = (int *)(&cell[offset_array[i]]);
	*cell_resources_ptr += 1;
	materials_event_add_callback(server, cli);
	return 0;
}

int materials_event_add_callback(server_t *server,
	int __attribute__((__unused__))cli)
{
	struct timeval tv;
	suseconds_t ms = 0;
	suseconds_t trigger = 0;
	event_parameter_t param = {
		.argc = 0,
		.argv = NULL,
		.client_nbr = -1
	};

	gettimeofday(&tv, NULL);
	ms = tv.tv_sec * 1000000 + tv.tv_usec;
	trigger = ms + (1000000 / server->flag.freq) * (126 / 5);
	event_t *evt = new_event(&param, trigger, materials_event_callback);
	event_list_t *node = event_list_node(evt);
	event_list_insert(&server->event_list, node);
	return 0;
}
