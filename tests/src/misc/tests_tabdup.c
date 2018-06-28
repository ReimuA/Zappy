/*
** EPITECH PROJECT, 2018
** singe
** File description:
** singe
*/

#include <assert.h>
#include <criterion/criterion.h>
#include "misc.h"

Test(tabdup, dup)
{
	char *tab[] = {
		"bonobo",
		"gorille",
		"ouistiti",
		"babouin",
		NULL
	};
	char **copy = tabdup(tab);
	assert(tablen(tab) == 4);
	for (int i = 0; tab[i] != 0; i++)
		assert(strcmp(tab[i], copy[i]) == 0);
}