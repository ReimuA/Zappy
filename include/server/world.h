/*
** EPITECH PROJECT, 2018
** singe
** File description:
** singe
*/

#pragma once

#include <stdlib.h>

#include "cell.h"

struct world_s {
	int size_x;
	int size_y;
	cell_t **map;
};
typedef struct world_s world_t;

int world_init(world_t *world, int size_x, int size_y);