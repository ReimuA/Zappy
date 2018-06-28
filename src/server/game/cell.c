/*
** EPITECH PROJECT, 2018
** singe
** File description:
** singe
*/

#include "cell.h"

int cell_init(cell_t *cell)
{
	*cell = (cell_t) {
		.food = 0,
		.sibur = 0,
		.phiras = 0,
		.linemate = 0,
		.mendiane = 0,
		.thystame = 0,
		.deraumere = 0
	};
	return 0;
}

bool cell_is_empty(cell_t *cell)
{
	if (cell->food != 0 ||
		cell->sibur != 0 ||
		cell->phiras != 0 ||
		cell->linemate != 0 ||
		cell->mendiane != 0 ||
		cell->thystame != 0 ||
		cell->deraumere != 0)
		return false;
	return true;
}
