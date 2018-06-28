/*
** EPITECH PROJECT, 2018
** singe
** File description:
** singe
*/

#include "server.h"

int cmd_forward_callback(server_t *server, int client_nbr, int ac, char **av)
{
	client_t *client = &server->clients[client_nbr];

	(void)ac;
	(void)av;
	if (client->direction == NORTH)
		client->pos_y--;
	if (client->direction == SOUTH)
		client->pos_y++;
	if (client->direction == EAST)
		client->pos_x--;
	if (client->direction == WEST)
		client->pos_x++;
	if (client->pos_y < 0)
		client->pos_y = server->flag.height - 1;
	if (client->pos_x < 0)
		client->pos_x = server->flag.width - 1;
	client->pos_x %= server->flag.width;
	client->pos_y %= server->flag.height;
	write(client->fd, "ok\n", strlen("ok\n"));
	return 0;
}

int cmd_handler_forward(server_t *server, int client, int argc, char **argv)
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
	event_t *evt = new_event(&param, trigger_date, cmd_forward_callback);
	event_list_t *node = event_list_node(evt);
	event_list_insert(&server->event_list, node);
	return 0;
}