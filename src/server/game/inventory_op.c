/*
** EPITECH PROJECT, 2018
** singe
** File description:
** singe
*/

#include "inventory.h"

void inventory_add(inventory_t *inv1, inventory_t *inv2)
{
	inv1->food += inv2->food;
	inv1->sibur += inv2->sibur;
	inv1->phiras += inv2->phiras;
	inv1->linemate += inv2->linemate;
	inv1->mendiane += inv2->mendiane;
	inv1->thystame += inv2->thystame;
	inv1->deraumere += inv2->deraumere;
}

bool inventory_ge_cmp(const inventory_t *inv1, const inventory_t *inv2)
{
	if (inv1->food >= inv2->food &&
		inv1->sibur >= inv2->sibur &&
		inv1->phiras >= inv2->phiras &&
		inv1->linemate >= inv2->linemate &&
		inv1->mendiane >= inv2->mendiane &&
		inv1->thystame >= inv2->thystame &&
		inv1->deraumere >= inv2->deraumere)
		return true;
	return false;
}
