/*
** EPITECH PROJECT, 2018
** singe
** File description:
** singe
*/

#include <assert.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "misc.h"

char **tabdup(char **tab)
{
	size_t i = tablen(tab);
	char **new_tab = malloc(sizeof(char *) * (i + 1));

	assert(new_tab);
	for (size_t j = 0; j < i; j++) {
		new_tab[j] = strdup(tab[j]);
		assert(new_tab[j]);
	}
	new_tab[i] = NULL;
	return new_tab;
}