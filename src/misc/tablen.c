/*
** EPITECH PROJECT, 2018
** singe
** File description:
** singe
*/

#include <stddef.h>

size_t tablen(char **tab)
{
	size_t i = 0;

	while (tab[i] != NULL)
		i++;
	return i;
}