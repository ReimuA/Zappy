/*
** EPITECH PROJECT, 2018
** singe
** File description:
** singe
*/

#include <assert.h>
#include <criterion/criterion.h>
#include "misc.h"

Test(tablen, simple)
{
	char *tab[] = {
		"Lolmdr",
		NULL
	};
	assert(tablen(tab) == 1);
}

Test(tablen, medium)
{
	char *tab[] = {
		"Lolmdr",
		"Lolmdr",
		"Lolmdr",
		"Lolmdr",
		NULL
	};
	assert(tablen(tab) == 4);
}