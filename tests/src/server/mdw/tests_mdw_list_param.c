/*
** EPITECH PROJECT, 2018
** singe
** File description:
** singe
*/

#include <stdio.h>
#include <assert.h>
#include <unistd.h>
#include <criterion/criterion.h>
#include "server.h"
#include "middleware.h"

Test(mdw_list_param, accept)
{
	int argc = 2;
	server_t server;
	int client_nb = 0;
	char *argv[] = { "test", "mdr", NULL };

	close(STDOUT_FILENO);
	assert(mdw_list_param(&server, client_nb, argc, argv) == true);
}
