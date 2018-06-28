/*
** EPITECH PROJECT, 2018
** singe
** File description:
** singe
*/

#pragma once

#include "inventory.h"

/*
** Client's definition.
*/

enum direction {
	EAST,
	WEST,
	NORTH,
	SOUTH,
	DIRECTION_SIZE
};

struct client_s {
	int fd;
	bool open;
	int pos_y;
	int pos_x;
	int level;
	int egg_id;
	char *buffer;
	bool hatched;
	bool graphical;
	inventory_t inventory;
	const char *team_name;
	enum direction direction;
};
typedef struct client_s client_t;

int client_init(client_t *client);
int client_read_chunk(client_t *client);
void client_reset_slot(client_t *client);
int client_set_graphical(client_t *client, const char *s);