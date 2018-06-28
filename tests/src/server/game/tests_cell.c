/*
** EPITECH PROJECT, 2018
** singe
** File description:
** singe
*/

#include <stdio.h>
#include <unistd.h>
#include <assert.h>
#include <criterion/criterion.h>
#include "cell.h"

Test(cell, creation)
{
	cell_t cell;

	cell_init(&cell);
	assert(cell.food == 0);
	assert(cell.sibur == 0);
	assert(cell.phiras == 0);
	assert(cell.linemate == 0);
	assert(cell.mendiane == 0);
	assert(cell.thystame == 0);
	assert(cell.deraumere == 0);
}

Test(cell, is_empty)
{
	cell_t cell;

	cell_init(&cell);
	assert(cell_is_empty(&cell));
}

Test(cell, is_empty_)
{
	cell_t cell;

	cell_init(&cell);
	cell.deraumere = 1;
	assert(cell_is_empty(&cell) == false);
}
