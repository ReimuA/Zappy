/*
** EPITECH PROJECT, 2018
** singe
** File description:
** singe
*/

#include "server.h"

static void cmd_eject_ejection(server_t *server, int cli, enum direction dir)
{
	client_t *client = &server->clients[cli];

	if (dir == NORTH)
		client->pos_y--;
	if (dir == SOUTH)
		client->pos_y++;
	if (dir == EAST)
		client->pos_x--;
	if (dir == WEST)
		client->pos_x++;
	if (client->pos_y < 0)
		client->pos_y = server->flag.height - 1;
	if (client->pos_x < 0)
		client->pos_x = server->flag.width - 1;
	client->pos_x %= server->flag.width;
	client->pos_y %= server->flag.height;
}

static void cmd_eject_send_info(server_t *server,
	int client,
	enum direction dir)
{
	int i = 0;
	char buff[16];
	enum direction dirs[DIRECTION_SIZE] = {
		NORTH,
		EAST,
		SOUTH,
		WEST
	};

	for (i = 0; i < DIRECTION_SIZE; i++) {
		if (dirs[i] == dir)
			break;
	}
	snprintf(buff, 16, "eject: %d\n", i + 1);
	write(server->clients[client].fd, buff, strlen(buff));
}

static void eject_send_graphical_info(server_t *server, int client_nbr)
{
	char buff[64];

	snprintf(buff, 64, "pex %d\n", client_nbr);
	server_graphical_broadcast(server, buff);
}

int cmd_eject_callback(server_t *server, int client_nbr, int argc, char **argv)
{
	int pos_x = server->clients[client_nbr].pos_x;
	int pos_y = server->clients[client_nbr].pos_y;
	enum direction dir = server->clients[client_nbr].direction;

	(void)argc;
	(void)argv;
	for (int i = 0; i < MAX_CLIENTS; i++) {
		if (i != client_nbr
			&& server->clients[i].open == false
			&& server->clients[i].team_name != NULL
			&& server->clients[i].graphical == false
			&& server->clients[i].pos_x == pos_x
			&& server->clients[i].pos_y == pos_y) {
			cmd_eject_ejection(server, i, dir);
			cmd_eject_send_info(server, i, dir);
		}
	}
	eject_send_graphical_info(server, client_nbr);
	write(server->clients[client_nbr].fd, "ok\n", strlen("ok\n"));
	return 0;
}

int cmd_handler_eject(server_t *server, int client, int argc, char **argv)
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
	event_t *evt = new_event(&param, trigger_date, cmd_eject_callback);
	event_list_t *node = event_list_node(evt);
	event_list_insert(&server->event_list, node);
	return 0;
}