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
#include "inventory.h"

Test(inventory, creation)
{
	inventory_t inventory = inventory_create();

	assert(inventory.food == 10);
	assert(inventory.sibur == 0);
	assert(inventory.phiras == 0);
	assert(inventory.linemate == 0);
	assert(inventory.mendiane == 0);
	assert(inventory.thystame == 0);
	assert(inventory.deraumere == 0);
}

Test(inventory, dump)
{
	inventory_t inventory = inventory_create();

	close(STDOUT_FILENO);
	inventory_dump(&inventory);
}

Test(inventory, init)
{
	inventory_t inventory;

	close(STDOUT_FILENO);
	inventory_init(&inventory);
	assert(inventory.food == 0);
	assert(inventory.sibur == 0);
	assert(inventory.phiras == 0);
	assert(inventory.linemate == 0);
	assert(inventory.mendiane == 0);
	assert(inventory.thystame == 0);
	assert(inventory.deraumere == 0);
}

Test(inventory, empty_test)
{
	inventory_t inventory;

	close(STDOUT_FILENO);
	inventory_init(&inventory);
	assert(inventory_is_empty(&inventory) == true);
	inventory.food++;
	assert(inventory_is_empty(&inventory) == false);
}

Test(inventory, inventory_add)
{
	inventory_t inv1 = { .food = 1, .sibur = 2, .phiras = 3,
		.thystame = 12, .deraumere = 3,
		.linemate = 15, .mendiane = 1 };
	inventory_t inv2 = { .food = 2, .sibur = 4, .phiras = 6,
		.thystame = 3, .deraumere = 12,
		.linemate = 33, .mendiane = 12 };

	inventory_add(&inv1, &inv2);
	assert(inv1.food == 3);
	assert(inv1.sibur == 6);
	assert(inv1.phiras == 9);
	assert(inv1.mendiane == 13);
	assert(inv1.linemate == 48);
	assert(inv1.thystame == 15);
	assert(inv1.deraumere == 15);
}

Test(inventory, inventory_ge_cmp)
{
	inventory_t inv1 = { .food = 1, .sibur = 2, .phiras = 3,
		.thystame = 12, .deraumere = 3,
		.linemate = 15, .mendiane = 1 };
	inventory_t inv2 = { .food = 2, .sibur = 4, .phiras = 6,
		.thystame = 3, .deraumere = 12,
		.linemate = 33, .mendiane = 12 };
	inventory_t inv3 = { .food = 0, .sibur = 0, .phiras = 0,
		.thystame = 0, .deraumere = 0,
		.linemate = 0, .mendiane = 0 };

	assert(inventory_ge_cmp(&inv1, &inv3) == true);
	assert(inventory_ge_cmp(&inv1, &inv2) == false);
}