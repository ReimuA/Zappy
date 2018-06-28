/*
** EPITECH PROJECT, 2018
** singe
** File description:
** singe
*/

#include <assert.h>
#include <criterion/criterion.h>
#include "world.h"

Test(world, creation)
{
	world_t world;

	world_init(&world, 10, 11);
	assert(world.map != NULL);
	assert(world.size_x == 10);
	assert(world.size_y == 11);
}
