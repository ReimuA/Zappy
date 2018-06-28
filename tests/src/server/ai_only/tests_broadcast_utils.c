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

Test(broadcast_utils, north_close)
{
	server_t server = { 0 };
	client_t emitter = { .pos_x = 5, .pos_y = 5 };
	client_t target = { .pos_x = 5, .pos_y = 5 , .direction = NORTH };

	server.world.size_x = 10;
	server.world.size_y = 10;
	assert(broadcast_direction(&server, &emitter, &target) == 0);
	emitter = (client_t){ .pos_x = 5, .pos_y = 4 };
	assert(broadcast_direction(&server, &emitter, &target) == 1);
	emitter = (client_t){ .pos_x = 6, .pos_y = 4 };
	assert(broadcast_direction(&server, &emitter, &target) == 2);
	emitter = (client_t){ .pos_x = 6, .pos_y = 5 };
	assert(broadcast_direction(&server, &emitter, &target) == 3);
	emitter = (client_t){ .pos_x = 6, .pos_y = 6 };
	assert(broadcast_direction(&server, &emitter, &target) == 4);
	emitter = (client_t){ .pos_x = 5, .pos_y = 6 };
	assert(broadcast_direction(&server, &emitter, &target) == 5);
	emitter = (client_t){ .pos_x = 4, .pos_y = 6 };
	assert(broadcast_direction(&server, &emitter, &target) == 6);
	emitter = (client_t){ .pos_x = 4, .pos_y = 5 };
	assert(broadcast_direction(&server, &emitter, &target) == 7);
	emitter = (client_t){ .pos_x = 4, .pos_y = 4 };
	assert(broadcast_direction(&server, &emitter, &target) == 8);
}

Test(broadcast_utils, east_close)
{
	server_t server = { 0 };
	client_t emitter = { .pos_x = 5, .pos_y = 5 };
	client_t target = { .pos_x = 5, .pos_y = 5 , .direction = EAST };

	server.world.size_x = 10;
	server.world.size_y = 10;
	assert(broadcast_direction(&server, &emitter, &target) == 0);
	emitter = (client_t){ .pos_x = 5, .pos_y = 4 };
	assert(broadcast_direction(&server, &emitter, &target) == 7);
	emitter = (client_t){ .pos_x = 6, .pos_y = 4 };
	assert(broadcast_direction(&server, &emitter, &target) == 8);
	emitter = (client_t){ .pos_x = 6, .pos_y = 5 };
	assert(broadcast_direction(&server, &emitter, &target) == 1);
	emitter = (client_t){ .pos_x = 6, .pos_y = 6 };
	assert(broadcast_direction(&server, &emitter, &target) == 2);
	emitter = (client_t){ .pos_x = 5, .pos_y = 6 };
	assert(broadcast_direction(&server, &emitter, &target) == 3);
	emitter = (client_t){ .pos_x = 4, .pos_y = 6 };
	assert(broadcast_direction(&server, &emitter, &target) == 4);
	emitter = (client_t){ .pos_x = 4, .pos_y = 5 };
	assert(broadcast_direction(&server, &emitter, &target) == 5);
	emitter = (client_t){ .pos_x = 4, .pos_y = 4 };
	assert(broadcast_direction(&server, &emitter, &target) == 6);
}

Test(broadcast_utils, south_close)
{
	server_t server = { 0 };
	client_t emitter = { .pos_x = 5, .pos_y = 5 };
	client_t target = { .pos_x = 5, .pos_y = 5 , .direction = SOUTH };

	server.world.size_x = 10;
	server.world.size_y = 10;
	assert(broadcast_direction(&server, &emitter, &target) == 0);
	emitter = (client_t){ .pos_x = 5, .pos_y = 4 };
	assert(broadcast_direction(&server, &emitter, &target) == 5);
	emitter = (client_t){ .pos_x = 6, .pos_y = 4 };
	assert(broadcast_direction(&server, &emitter, &target) == 6);
	emitter = (client_t){ .pos_x = 6, .pos_y = 5 };
	assert(broadcast_direction(&server, &emitter, &target) == 7);
	emitter = (client_t){ .pos_x = 6, .pos_y = 6 };
	assert(broadcast_direction(&server, &emitter, &target) == 8);
	emitter = (client_t){ .pos_x = 5, .pos_y = 6 };
	assert(broadcast_direction(&server, &emitter, &target) == 1);
	emitter = (client_t){ .pos_x = 4, .pos_y = 6 };
	assert(broadcast_direction(&server, &emitter, &target) == 2);
	emitter = (client_t){ .pos_x = 4, .pos_y = 5 };
	assert(broadcast_direction(&server, &emitter, &target) == 3);
	emitter = (client_t){ .pos_x = 4, .pos_y = 4 };
	assert(broadcast_direction(&server, &emitter, &target) == 4);
}

Test(broadcast_utils, west_close)
{
	server_t server = { 0 };
	client_t emitter = { .pos_x = 5, .pos_y = 5 };
	client_t target = { .pos_x = 5, .pos_y = 5 , .direction = WEST };

	server.world.size_x = 10;
	server.world.size_y = 10;
	assert(broadcast_direction(&server, &emitter, &target) == 0);
	emitter = (client_t){ .pos_x = 5, .pos_y = 4 };
	assert(broadcast_direction(&server, &emitter, &target) == 3);
	emitter = (client_t){ .pos_x = 6, .pos_y = 4 };
	assert(broadcast_direction(&server, &emitter, &target) == 4);
	emitter = (client_t){ .pos_x = 6, .pos_y = 5 };
	assert(broadcast_direction(&server, &emitter, &target) == 5);
	emitter = (client_t){ .pos_x = 6, .pos_y = 6 };
	assert(broadcast_direction(&server, &emitter, &target) == 6);
	emitter = (client_t){ .pos_x = 5, .pos_y = 6 };
	assert(broadcast_direction(&server, &emitter, &target) == 7);
	emitter = (client_t){ .pos_x = 4, .pos_y = 6 };
	assert(broadcast_direction(&server, &emitter, &target) == 8);
	emitter = (client_t){ .pos_x = 4, .pos_y = 5 };
	assert(broadcast_direction(&server, &emitter, &target) == 1);
	emitter = (client_t){ .pos_x = 4, .pos_y = 4 };
	assert(broadcast_direction(&server, &emitter, &target) == 2);
}

Test(broadcast_utils, north_far)
{
	server_t server = { 0 };
	client_t emitter = { .pos_x = 5, .pos_y = 5 };
	client_t target = { .pos_x = 5, .pos_y = 5 , .direction = NORTH };

	server.world.size_x = 10;
	server.world.size_y = 10;
	assert(broadcast_direction(&server, &emitter, &target) == 0);
	emitter = (client_t){ .pos_x = 5, .pos_y = 2 };
	assert(broadcast_direction(&server, &emitter, &target) == 1);
	emitter = (client_t){ .pos_x = 8, .pos_y = 2 };
	assert(broadcast_direction(&server, &emitter, &target) == 2);
	emitter = (client_t){ .pos_x = 8, .pos_y = 5 };
	assert(broadcast_direction(&server, &emitter, &target) == 3);
	emitter = (client_t){ .pos_x = 8, .pos_y = 8 };
	assert(broadcast_direction(&server, &emitter, &target) == 4);
	emitter = (client_t){ .pos_x = 5, .pos_y = 8 };
	assert(broadcast_direction(&server, &emitter, &target) == 5);
	emitter = (client_t){ .pos_x = 3, .pos_y = 8 };
	assert(broadcast_direction(&server, &emitter, &target) == 6);
	emitter = (client_t){ .pos_x = 3, .pos_y = 5 };
	assert(broadcast_direction(&server, &emitter, &target) == 7);
	emitter = (client_t){ .pos_x = 3, .pos_y = 2 };
	assert(broadcast_direction(&server, &emitter, &target) == 8);
}

Test(broadcast_utils, east_far)
{
	server_t server = { 0 };
	client_t emitter = { .pos_x = 5, .pos_y = 5 };
	client_t target = { .pos_x = 5, .pos_y = 5 , .direction = EAST };

	server.world.size_x = 10;
	server.world.size_y = 10;
	assert(broadcast_direction(&server, &emitter, &target) == 0);
	emitter = (client_t){ .pos_x = 5, .pos_y = 2 };
	assert(broadcast_direction(&server, &emitter, &target) == 7);
	emitter = (client_t){ .pos_x = 8, .pos_y = 2 };
	assert(broadcast_direction(&server, &emitter, &target) == 8);
	emitter = (client_t){ .pos_x = 8, .pos_y = 5 };
	assert(broadcast_direction(&server, &emitter, &target) == 1);
	emitter = (client_t){ .pos_x = 8, .pos_y = 8 };
	assert(broadcast_direction(&server, &emitter, &target) == 2);
	emitter = (client_t){ .pos_x = 5, .pos_y = 8 };
	assert(broadcast_direction(&server, &emitter, &target) == 3);
	emitter = (client_t){ .pos_x = 3, .pos_y = 8 };
	assert(broadcast_direction(&server, &emitter, &target) == 4);
	emitter = (client_t){ .pos_x = 3, .pos_y = 5 };
	assert(broadcast_direction(&server, &emitter, &target) == 5);
	emitter = (client_t){ .pos_x = 3, .pos_y = 2 };
	assert(broadcast_direction(&server, &emitter, &target) == 6);
}

Test(broadcast_utils, south_far)
{
	server_t server = { 0 };
	client_t emitter = { .pos_x = 5, .pos_y = 5 };
	client_t target = { .pos_x = 5, .pos_y = 5 , .direction = SOUTH };

	server.world.size_x = 10;
	server.world.size_y = 10;
	assert(broadcast_direction(&server, &emitter, &target) == 0);
	emitter = (client_t){ .pos_x = 5, .pos_y = 2 };
	assert(broadcast_direction(&server, &emitter, &target) == 5);
	emitter = (client_t){ .pos_x = 8, .pos_y = 2 };
	assert(broadcast_direction(&server, &emitter, &target) == 6);
	emitter = (client_t){ .pos_x = 8, .pos_y = 5 };
	assert(broadcast_direction(&server, &emitter, &target) == 7);
	emitter = (client_t){ .pos_x = 8, .pos_y = 8 };
	assert(broadcast_direction(&server, &emitter, &target) == 8);
	emitter = (client_t){ .pos_x = 5, .pos_y = 8 };
	assert(broadcast_direction(&server, &emitter, &target) == 1);
	emitter = (client_t){ .pos_x = 3, .pos_y = 8 };
	assert(broadcast_direction(&server, &emitter, &target) == 2);
	emitter = (client_t){ .pos_x = 3, .pos_y = 5 };
	assert(broadcast_direction(&server, &emitter, &target) == 3);
	emitter = (client_t){ .pos_x = 3, .pos_y = 2 };
	assert(broadcast_direction(&server, &emitter, &target) == 4);
}

Test(broadcast_utils, west_far)
{
	server_t server = { 0 };
	client_t emitter = { .pos_x = 5, .pos_y = 5 };
	client_t target = { .pos_x = 5, .pos_y = 5 , .direction = WEST };

	server.world.size_x = 10;
	server.world.size_y = 10;
	assert(broadcast_direction(&server, &emitter, &target) == 0);
	emitter = (client_t){ .pos_x = 5, .pos_y = 2 };
	assert(broadcast_direction(&server, &emitter, &target) == 3);
	emitter = (client_t){ .pos_x = 8, .pos_y = 2 };
	assert(broadcast_direction(&server, &emitter, &target) == 4);
	emitter = (client_t){ .pos_x = 8, .pos_y = 5 };
	assert(broadcast_direction(&server, &emitter, &target) == 5);
	emitter = (client_t){ .pos_x = 8, .pos_y = 8 };
	assert(broadcast_direction(&server, &emitter, &target) == 6);
	emitter = (client_t){ .pos_x = 5, .pos_y = 8 };
	assert(broadcast_direction(&server, &emitter, &target) == 7);
	emitter = (client_t){ .pos_x = 3, .pos_y = 8 };
	assert(broadcast_direction(&server, &emitter, &target) == 8);
	emitter = (client_t){ .pos_x = 3, .pos_y = 5 };
	assert(broadcast_direction(&server, &emitter, &target) == 1);
	emitter = (client_t){ .pos_x = 3, .pos_y = 2 };
	assert(broadcast_direction(&server, &emitter, &target) == 2);
}
