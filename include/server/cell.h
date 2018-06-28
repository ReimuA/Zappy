/*
** EPITECH PROJECT, 2018
** singe
** File description:
** singe
*/

#pragma once

#include <stdbool.h>

struct cell_s {
	int food;
	int sibur;
	int phiras;
	int linemate;
	int mendiane;
	int thystame;
	int deraumere;
};
typedef struct cell_s cell_t;

struct cell_helper_s {
	const char *name;
	int offset;
};
typedef struct cell_helper_s cell_helper_t;

int cell_init(cell_t *cell);
bool cell_is_empty(cell_t *cell);