/*
** EPITECH PROJECT, 2018
** singe
** File description:
** singe
*/

#include <assert.h>
#include <criterion/criterion.h>
#include "server.h"
#include "cmd_handler.h"

Test(right_callback, north)
{
	server_t server = { 0 };

	client_init(&server.clients[0]);
	server.clients[0].direction = NORTH;
	cmd_right_callback(&server, 0, 0, NULL);
	assert(server.clients[0].direction == WEST);
}

Test(right_callback, west)
{
	server_t server = { 0 };

	client_init(&server.clients[0]);
	server.clients[0].direction = WEST;
	cmd_right_callback(&server, 0, 0, NULL);
	assert(server.clients[0].direction == SOUTH);
}

Test(right_callback, south)
{
	server_t server = { 0 };

	client_init(&server.clients[0]);
	server.clients[0].direction = SOUTH;
	cmd_right_callback(&server, 0, 0, NULL);
	assert(server.clients[0].direction == EAST);
}

Test(right_callback, east)
{
	server_t server = { 0 };

	client_init(&server.clients[0]);
	server.clients[0].direction = EAST;
	cmd_right_callback(&server, 0, 0, NULL);
	assert(server.clients[0].direction == NORTH);
}

Test(right_callback, full_loop)
{
	server_t server = { 0 };
	unsigned int direction[DIRECTION_SIZE] = {
		WEST,
		SOUTH,
		EAST,
		NORTH
	};

	client_init(&server.clients[0]);
	server.clients[0].direction = NORTH;
	for (int i = 0; i < 4; i ++) {
		cmd_right_callback(&server, 0, 0, NULL);
		assert(server.clients[0].direction == direction[i]);
	}
}