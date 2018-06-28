/*
** EPITECH PROJECT, 2018
** singe
** File description:
** singe
*/

#include "world.h"

int world_init(world_t *world, int size_x, int size_y)
{
	*world = (world_t) {
		.map = NULL,
		.size_x = size_x,
		.size_y = size_y,
	};
	world->map = malloc(sizeof(cell_t *) * (size_y));
	if (world->map == NULL)
		return 1;
	for (int i = 0; i < size_y; i++) {
		world->map[i] = malloc(sizeof(cell_t) * (size_x));
		for (int j = 0; j < size_x; j++)
			cell_init(&world->map[i][j]);
		if (world->map[i] == NULL)
			return 1;
	}
	return 0;
}