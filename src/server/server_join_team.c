/*
** EPITECH PROJECT, 2018
** singe
** File description:
** singe
*/

#include "server.h"
#include "food_event.h"

static void server_broadcast_new_player(server_t *server, int i)
{
	char buff[64];
	client_t *client = &server->clients[i];

	snprintf(buff, 64, "pnw #%d %d %d %d %d %s\n",
		i, client->pos_x, client->pos_y, 1, client->level,
		client->team_name);
	server_graphical_broadcast(server, buff);
}

static void server_broadcast_egg_connection(server_t *server, int i)
{
	char buff[32];

	snprintf(buff, 32, "ebo %d\n", server->clients[i].egg_id);
	server_graphical_broadcast(server, buff);
}

static void server_join_team(server_t *server, int i, const char *team)
{
	int k = 0;

	for (; k < MAX_CLIENTS; k++) {
		if (server->clients[k].open == false &&
			server->clients[k].hatched == true &&
			strcmp(server->clients[k].team_name, team) == 0)
			break;
	}
	if (k == MAX_CLIENTS) {
		server->clients[i].team_name = team;
		food_event_add_callback(server, i);
		server_broadcast_new_player(server, i);
		return;
	}
	server->clients[k].fd = server->clients[i].fd;
	server->clients[k].hatched = false;
	server->clients[k].buffer = NULL;
	client_init(&server->clients[i]);
	server_broadcast_new_player(server, k);
	server_broadcast_egg_connection(server, k);
}

int server_get_client_team_name(server_t *server, int i)
{
	int j = 0;
	char buff[512] = { 0 };
	char *s = server->clients[i].buffer;
	int slot = server_get_free_team_slot_nbr(server, s);

	for (j = 0; server->flag.team_names[j] != NULL; j++) {
		if (strcmp(server->flag.team_names[j], s) == 0)
			break;
	}
	if (slot <= 0 && strcmp(s, "GRAPHIC") != 0)
		write(server->clients[i].fd, "ko\n", strlen("ko\n"));
	else if (strcmp(s, "GRAPHIC") != 0) {
		snprintf(buff, 512, "%d\n%d %d\n", slot - 1,
			server->flag.width, server->flag.height);
		write(server->clients[i].fd, buff, strlen(buff));
		server_join_team(server, i, server->flag.team_names[j]);
	}
	client_set_graphical(&server->clients[i], s);
	return 0;
}
