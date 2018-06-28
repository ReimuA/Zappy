/*
** EPITECH PROJECT, 2018
** singe
** File description:
** singe
*/

#include <string.h>
#include <stdlib.h>

char **explode(char *str, const char *delim)
{
	size_t i = 0;
	char **tab = malloc(sizeof(char *));

	if (tab == NULL)
		return NULL;
	tab[i] = strtok(str, delim);
	while (tab[i] != NULL) {
		i++;
		tab = realloc(tab, sizeof(char *) * (i + 1));
		tab[i] = strtok(NULL, delim);
	}
	return tab;
}