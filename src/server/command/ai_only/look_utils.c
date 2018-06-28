/*
** EPITECH PROJECT, 2018
** singe
** File description:
** singe
*/

#include "server.h"

void look_send_data(client_t *client, const char *s, int number)
{
	if (number == 0)
		return;
	for (int i = 0; i < number; i++) {
		write(client->fd, s, strlen(s));
		write(client->fd, " ", 1);
	}
}

void look_materials(client_t *client, cell_t *cell)
{
	look_send_data(client, "food", cell->food);
	look_send_data(client, "sibur", cell->sibur);
	look_send_data(client, "phiras", cell->phiras);
	look_send_data(client, "linemate", cell->food);
	look_send_data(client, "mendiane", cell->mendiane);
	look_send_data(client, "thystame", cell->thystame);
	look_send_data(client, "deraumere", cell->deraumere);
}

void look_send_player_nbr(server_t *server, client_t *client, int x, int y)
{
	int player = 0;

	for (int i = 0; i < MAX_CLIENTS; i++) {
		if (server->clients[i].graphical == false &&
			server->clients[i].team_name != NULL &&
			server->clients[i].pos_x == x &&
			server->clients[i].pos_y == y)
			player++;
	}
	look_send_data(client, "player", player);
}
