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

Test(mdw_check_target, invalid_parameter_nbr)
{
	int argc = 1;

	assert(mdw_check_target(NULL, 0, argc, NULL) == false);
}

Test(mdw_check_target, invalid_client_nbr)
{
	int argc = 2;
	char **argv2 = malloc(sizeof(char *) * 2);
	char *s = strdup("request");
	char buffer[64];
	char *argv1[] = { "request", "-1" };

	assert(argv2 && s);
	snprintf(buffer, 64, "%d", MAX_CLIENTS);
	argv2[0] = s;
	argv2[1] = buffer;
	assert(mdw_check_target(NULL, 0, argc, argv1) == false);
	assert(mdw_check_target(NULL, 0, argc, argv2) == false);
	free(s);
	free(argv2);
}

Test(mdw_check_target, closed_client_slot)
{
	int argc = 2;
	server_t server;
	char *argv1[] = { "request", "0" };

	server.clients[0].open = false;
	assert(mdw_check_target(&server, 0, argc, argv1) == false);
}

Test(mdw_check_target, invalid_client_type)
{
	int argc = 2;
	server_t server;
	char *argv1[] = { "request", "0" };

	server.clients[0].open = true;
	server.clients[0].graphical = true;
	assert(mdw_check_target(&server, 0, argc, argv1) == false);
}

Test(mdw_check_target, client_without_team)
{
	int argc = 2;
	server_t server;
	char *argv1[] = { "request", "0" };

	server.clients[0].open = false;
	server.clients[0].team_name = NULL;
	server.clients[0].graphical = false;
	assert(mdw_check_target(&server, 0, argc, argv1) == false);
}

Test(mdw_check_target, success)
{
	int argc = 2;
	server_t server;
	char *argv1[] = { "request", "0" };

	server.clients[0].open = false;
	server.clients[0].team_name = ";)";
	server.clients[0].graphical = false;
	assert(mdw_check_target(&server, 0, argc, argv1) == true);
}