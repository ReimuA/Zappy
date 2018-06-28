/*
** EPITECH PROJECT, 2018
** singe
** File description:
** singe
*/

#include <assert.h>
#include <unistd.h>
#include <criterion/criterion.h>
#include "server.h"
#include "cmd_handler.h"

static void init_forward_test(server_t *server, enum direction dir)
{
	server->flag = (flag_t) {
		.width = 5,
		.height = 5
	};
	server->clients[0] = (client_t) {
		.fd = 1,
		.direction = dir
	};
	close(STDOUT_FILENO);
}

Test(forward_callback, north)
{
	int argc = 0;
	server_t server;
	char **argv = NULL;
	int client_nbr = 0;

	init_forward_test(&server, NORTH);
	server.clients[0].pos_y = 3;
	server.clients[0].pos_x = 3;
	cmd_forward_callback(&server, client_nbr, argc, argv);
	assert(server.clients[0].pos_x == 3);
	assert(server.clients[0].pos_y == 2);
}

Test(forward_callback, west)
{
	int argc = 0;
	server_t server;
	char **argv = NULL;
	int client_nbr = 0;

	init_forward_test(&server, WEST);
	server.clients[0].pos_y = 3;
	server.clients[0].pos_x = 3;
	cmd_forward_callback(&server, client_nbr, argc, argv);
	assert(server.clients[0].pos_x == 4);
	assert(server.clients[0].pos_y == 3);
}

Test(forward_callback, south)
{
	int argc = 0;
	server_t server;
	char **argv = NULL;
	int client_nbr = 0;

	init_forward_test(&server, SOUTH);
	server.clients[0].pos_y = 3;
	server.clients[0].pos_x = 3;
	cmd_forward_callback(&server, client_nbr, argc, argv);
	assert(server.clients[0].pos_x == 3);
	assert(server.clients[0].pos_y == 4);
}

Test(forward_callback, east)
{
	int argc = 0;
	server_t server;
	char **argv = NULL;
	int client_nbr = 0;

	init_forward_test(&server, EAST);
	server.clients[0].pos_y = 3;
	server.clients[0].pos_x = 3;
	cmd_forward_callback(&server, client_nbr, argc, argv);
	assert(server.clients[0].pos_x == 2);
	assert(server.clients[0].pos_y == 3);
}

Test(forward_callback, north_with_overflow)
{
	int argc = 0;
	server_t server;
	char **argv = NULL;
	int client_nbr = 0;

	init_forward_test(&server, NORTH);
	server.clients[0].pos_y = 0;
	server.clients[0].pos_x = 0;
	cmd_forward_callback(&server, client_nbr, argc, argv);
	assert(server.clients[0].pos_x == 0);
	assert(server.clients[0].pos_y == 4);
}

Test(forward_callback, west_with_overflow)
{
	int argc = 0;
	server_t server;
	char **argv = NULL;
	int client_nbr = 0;

	init_forward_test(&server, WEST);
	server.clients[0].pos_y = 4;
	server.clients[0].pos_x = 4;
	cmd_forward_callback(&server, client_nbr, argc, argv);
	assert(server.clients[0].pos_x == 0);
	assert(server.clients[0].pos_y == 4);
}

Test(forward_callback, south_with_overflow)
{
	int argc = 0;
	server_t server;
	char **argv = NULL;
	int client_nbr = 0;

	init_forward_test(&server, SOUTH);
	server.clients[0].pos_y = 4;
	server.clients[0].pos_x = 4;
	cmd_forward_callback(&server, client_nbr, argc, argv);
	assert(server.clients[0].pos_x == 4);
	assert(server.clients[0].pos_y == 0);
}

Test(forward_callback, east_with_overflow)
{
	int argc = 0;
	server_t server;
	char **argv = NULL;
	int client_nbr = 0;

	init_forward_test(&server, EAST);
	server.clients[0].pos_y = 3;
	server.clients[0].pos_x = 0;
	cmd_forward_callback(&server, client_nbr, argc, argv);
	assert(server.clients[0].pos_x == 4);
	assert(server.clients[0].pos_y == 3);
}

Test(cmd_handler_forward, tests)
{
	int argc = 0;
	int client_nbr = 0;
	char **argv = NULL;
	server_t server = { 
		.flag = {
			.freq = 100
		},
		.event_list = NULL
	};

	cmd_handler_forward(&server, client_nbr, argc, argv);
	assert(server.event_list->event->parameter.argc == 0);
	assert(server.event_list->event->parameter.argv == NULL);
	assert(server.event_list->event->parameter.client_nbr == 0);
	assert(server.event_list->event->callback == cmd_forward_callback);
}
