/*
** EPITECH PROJECT, 2018
** singe
** File description:
** singe
*/

#include "inventory.h"

inventory_t inventory_create(void)
{
	return (inventory_t) {
		.food = 10,
		.sibur = 0,
		.phiras = 0,
		.linemate = 0,
		.mendiane = 0,
		.thystame = 0,
		.deraumere = 0
	};
}

void inventory_dump(inventory_t *inventory)
{
	fprintf(stdout, "\nStart of inventory dump\n");
	fprintf(stdout, "\tfood = %d\n", inventory->food);
	fprintf(stdout, "\tsibur = %d\n", inventory->sibur);
	fprintf(stdout, "\tphiras = %d\n", inventory->phiras);
	fprintf(stdout, "\tlinemate = %d\n", inventory->linemate);
	fprintf(stdout, "\tmendiane = %d\n", inventory->mendiane);
	fprintf(stdout, "\tthystame = %d\n", inventory->thystame);
	fprintf(stdout, "\tderaumere = %d\n", inventory->deraumere);
	fprintf(stdout, "End of inventory dump\n\n");
}

bool inventory_is_empty(inventory_t *inventory)
{
	return cell_is_empty(inventory);
}

void inventory_init(inventory_t *inventory)
{
	cell_init(inventory);
}
