/*
** EPITECH PROJECT, 2018
** singe
** File description:
** singe
*/

#include <assert.h>
#include <criterion/criterion.h>
#include "misc.h"

Test(explode, hard)
{
	char **test = explode(strdup(" je test \t mon explode  \n"), " \t\n");

	assert(strcmp(test[0], "je") == 0);
	assert(strcmp(test[1], "test") == 0);
	assert(strcmp(test[2], "mon") == 0);
	assert(strcmp(test[3], "explode") == 0);
	assert(test[4] == NULL);
}