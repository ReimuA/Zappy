/*
** EPITECH PROJECT, 2018
** singe
** File description:
** singe
*/

#include "server.h"

int cmd_inventory_callback(server_t *server,
	int client_nbr,
	int __attribute__((__unused__)) ac,
	char __attribute__((__unused__)) **av)
{
	char buffer[1024] = { 0 };
	inventory_t *inv = &server->clients[client_nbr].inventory;
	const char *res_names[] = {
		"linemate",
		"sibur",
		"deraumere",
		"mendiane",
		"phiras",
		"thystame",
		"food"
	};

	snprintf(buffer, 1024,
		"[ %s %d, %s %d, %s %d, %s %d, %s %d, %s %d, %s %d ]\n",
		res_names[6], inv->food, res_names[0], inv->linemate,
		res_names[2], inv->deraumere, res_names[1], inv->sibur,
		res_names[3], inv->mendiane, res_names[4], inv->phiras,
		res_names[5], inv->thystame);
	write(server->clients[client_nbr].fd, buffer, strlen(buffer));
	return 0;
}

int cmd_handler_inventory(server_t *server, int client, int argc, char **argv)
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
	trigger_date = ms + (1000000 / server->flag.freq);
	event_t *evt = new_event(&param, trigger_date, cmd_inventory_callback);
	event_list_t *node = event_list_node(evt);
	event_list_insert(&server->event_list, node);
	return 0;
}
