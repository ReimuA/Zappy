/*
** EPITECH PROJECT, 2018
** singe
** File description:
** singe
*/

#include "server.h"
#include "look_utils.h"

static void look_dump_cell(server_t *s, client_t *client, int x, int y)
{
	cell_t *cell = &s->world.map[y][x];

	look_send_player_nbr(s, client, x, y);
	look_materials(client, cell);
}

static int look_chose_x_increment(server_t *s, client_t *client, int i, int j)
{
	int x = 0;

	if (client->direction == NORTH)
		x = client->pos_x - (i + 1) + j;
	if (client->direction == SOUTH)
		x = client->pos_x + (i + 1) - j;
	if (client->direction == WEST)
		x = client->pos_x + (i + 1);
	if (client->direction == EAST)
		x = client->pos_y - (i + 1);
	x %= s->flag.width;
	if (x < 0)
		x = s->flag.width + x;
	return x;
}

static int look_chose_y_increment(server_t *s, client_t *client, int i, int j)
{
	int y = 0;

	if (client->direction == NORTH)
		y = client->pos_y - (i + 1);
	if (client->direction == SOUTH)
		y = client->pos_y + (i + 1);
	if (client->direction == WEST)
		y = client->pos_y - (i + 1) + j;
	if (client->direction == EAST)
		y = client->pos_y + (i + 1) - j;
	y %= s->flag.height;
	if (y < 0)
		y = s->flag.height + y;
	return y;
}

int cmd_look_callback(server_t *server, int client_nbr, int argc, char **argv)
{
	(void)argc;
	(void)argv;
	client_t *client = &server->clients[client_nbr];
	int pos_x;
	int pos_y;

	write(client->fd, "[ ", 2);
	look_dump_cell(server, client, client->pos_x, client->pos_y);
	write(client->fd, ",", 1);
	for (int i = 0; i < client->level; i++) {
		for (int j = 0; j < (i + 1) * 2 + 1; j++) {
			pos_x = look_chose_x_increment(server, client, i, j);
			pos_y = look_chose_y_increment(server, client, i, j);
			look_dump_cell(server, client, pos_x, pos_y);
			if (!(j == (i + 1) * 2 && i == client->level - 1))
				write(client->fd, ",", 1);
		}
	}
	write(client->fd, "]\n", 2);
	return 0;
}

int cmd_handler_look(server_t *server, int client, int argc, char **argv)
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
	event_t *evt = new_event(&param, trigger_date, cmd_look_callback);
	event_list_t *node = event_list_node(evt);
	event_list_insert(&server->event_list, node);
	return 0;
}
