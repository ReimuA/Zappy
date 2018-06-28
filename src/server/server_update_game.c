/*
** EPITECH PROJECT, 2018
** singe
** File description:
** singe
*/

#include "server.h"

static int server_kick_dead_player(server_t *server)
{
	for (int i = 0; i < MAX_CLIENTS; i++) {
		if (server->clients[i].open == false &&
			server->clients[i].graphical == false &&
			server->clients[i].inventory.food < 0)
			server_kick_client(server, i);
	}
	return 0;
}

int server_update_game(server_t *server)
{
	struct timeval tv;
	suseconds_t actual_date;
	event_list_t *tmp = NULL;
	event_list_t *list = server->event_list;

	gettimeofday(&tv, NULL);
	actual_date = tv.tv_sec * 1000000 + tv.tv_usec;
	while (list != NULL) {
		tmp = list->next;
		if (actual_date >= list->event->trigger_time) {
			event_start_event(list->event, server);
			event_list_unlink(&server->event_list, list);
			list = server->event_list;
		}
		list = tmp;
	}
	server_kick_dead_player(server);
	return 0;
}