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

char **tabcpy(char **tab, int size)
{
	int i = size;
	char **new_tab;

	if (i == 0)
		return NULL;
	new_tab = malloc(sizeof(char *) * (i + 1));
	assert(new_tab);
	for (int j = 0; j < i; j++) {
		new_tab[j] = strdup(tab[j]);
		assert(new_tab[j]);
	}
	new_tab[i] = NULL;
	return new_tab;
}
