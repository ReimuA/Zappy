/*
** EPITECH PROJECT, 2018
** singe
** File description:
** singe
*/

#include "server.h"

static const inventory_t elevation_req[] = {
	{ .linemate = 1 },
	{ .linemate = 1, .deraumere = 1, .sibur = 1 },
	{ .linemate = 2, .sibur = 1, .phiras = 2 },
	{ .linemate = 1, .deraumere = 1, .sibur = 2, .phiras = 1 },
	{ .linemate = 1, .deraumere = 2, .sibur = 1, .mendiane = 3 },
	{ .linemate = 1, .deraumere = 2, .sibur = 3, .phiras = 1 },
	{
		.sibur = 2,
		.phiras = 2,
		.linemate = 2,
		.mendiane = 2,
		.thystame = 1,
		.deraumere = 2
	},
	{
		.sibur = 2,
		.phiras = 2,
		.linemate = 2,
		.mendiane = 2,
		.thystame = 1,
		.deraumere = 2
	}
};

static void elevation_send_graph_info(server_t *server,
	int client_nbr,
	int mode)
{
	char buff[512];
	client_t *client = &server->clients[client_nbr];

	if (mode == 0) {
		snprintf(buff, 512, "pic %d %d %d\n",
			client->pos_x, client->pos_y, client->level);
	} else {
		snprintf(buff, 512, "pie %d %d %d\n",
			client->pos_x, client->pos_y, client->level);
	}
	server_graphical_broadcast(server, buff);
}

static bool participant_is_valid(client_t *elev,
	client_t *c)
{
	if (c->graphical == false &&
		c->team_name != NULL &&
		elev->pos_x == c->pos_x &&
		elev->pos_y == c->pos_y)
		return true;
	return false;
}

static bool elevation_check_requirement(server_t *s,
	int lvl,
	int pos_x,
	int pos_y)
{
	int clients = 0;
	inventory_t total_inv = { 0 };
	int clients_req[] = { 1, 2, 2, 4, 4, 6, 6, 6 };

	for (int i = 0; i < MAX_CLIENTS; i++) {
		if (s->clients[i].graphical == false &&
			s->clients[i].team_name != NULL &&
			s->clients[i].pos_x == pos_x &&
			s->clients[i].pos_y == pos_y) {
			inventory_add(&total_inv, &s->clients[i].inventory);
			clients++;
		}
	}
	if (clients_req[lvl - 1] <= clients &&
		inventory_ge_cmp(&total_inv, &elevation_req[lvl - 1]))
		return true;
	return false;
}

int cmd_elevation_callback(server_t *s,
	int client_nbr,
	int __attribute__((__unused__)) ac,
	char __attribute__((__unused__)) **av)
{
	char buff[128];
	client_t c = s->clients[client_nbr];

	if (elevation_check_requirement(s, c.level, c.pos_x, c.pos_y)) {
		for (int i = 0; i < MAX_CLIENTS; i++) {
			if (participant_is_valid(&c, &s->clients[i]) &&
			s->clients[i].level < 8)
				s->clients[i].level += 1;
		}
	}
	elevation_send_graph_info(s, client_nbr, 1);
	for (int i = 0; i < MAX_CLIENTS; i++) {
		if (participant_is_valid(&c, &s->clients[i])) {
			snprintf(buff, 128,
				"current level: %d\n", s->clients[i].level);
			write(s->clients[i].fd, buff, strlen(buff));
		}
	}
	return 0;
}

int cmd_handler_elevation(server_t *server,
	int i,
	int __attribute__((__unused__)) argc,
	char __attribute__((__unused__)) **argv)
{
	struct timeval tv;
	client_t c = server->clients[i];
	suseconds_t ms = 0;
	suseconds_t trigger_date = 0;
	event_parameter_t param = { .argc = argc, .argv = argv, .client_nbr = i
	};

	server->clients[i].inventory.linemate += 1;
	if (!elevation_check_requirement(server, c.level, c.pos_x, c.pos_y)) {
		write(server->clients[i].fd, "ko\n", strlen("ko\n"));
		return -1;
	}
	elevation_send_graph_info(server, i, 0);
	gettimeofday(&tv, NULL);
	ms = tv.tv_sec * 1000000 + tv.tv_usec;
	trigger_date = ms + (1000000 / server->flag.freq) * 300;
	event_t *evt = new_event(&param, trigger_date, cmd_elevation_callback);
	event_list_t *node = event_list_node(evt);
	event_list_insert(&server->event_list, node);
	return 0;
}
