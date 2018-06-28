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

Test(mdw_graph_only, refused)
{
	int argc = 1;
	int client_nb = 0;
	char *argv[] = { "test", NULL };
	server_t server;

	close(STDOUT_FILENO);
	server.clients[client_nb].graphical = false;
	assert(mdw_graph_only(&server, client_nb, argc, argv) == false);
}

Test(mdw_graph_only, accepted)
{
	int argc = 1;
	int client_nb = 0;
	char *argv[] = { "test", NULL };
	server_t server;

	server.clients[client_nb].graphical = true;
	assert(mdw_graph_only(&server, client_nb, argc, argv) == true);
}
