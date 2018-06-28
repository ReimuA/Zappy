/*
** EPITECH PROJECT, 2018
** singe
** File description:
** singe
*/

#include <assert.h>
#include <criterion/criterion.h>
#include "misc.h"

Test(tabcpy, 0_len)
{
	assert(tabcpy(NULL, 0) == NULL);
}

Test(tabcpy, copy)
{
	char *tab[] = {
		"bonobo",
		"gorille",
		"ouistiti",
		"babouin",
		NULL
	};
	char **copy = tabcpy(tab, tablen(tab));
	assert(tablen(tab) == 4);
	for (int i = 0; tab[i] != 0; i++)
		assert(strcmp(tab[i], copy[i]) == 0);
}