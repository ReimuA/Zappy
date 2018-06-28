/*
** EPITECH PROJECT, 2018
** singe
** File description:
** singe
*/

#include <stdio.h>
#include <unistd.h>
#include <assert.h>
#include <criterion/criterion.h>
#include "server.h"
#include "cmd_handler.h"

static int setup_success_test(server_t *server, int fd)
{
	server->clients[1].fd = fd;
	server->clients[1].pos_x = 12;
	server->clients[1].pos_y = 23;
	return 0;
}

Test(cmd_handler_ppo, success_north)
{
	int argc = 2;
	int pipe_[2];
	server_t server;
	char *argv[] = { "ppo", "1" };
	char buffer[512] = { 0 };
	char expected_result[] = "ppo 1 12 23 1\n";

	assert(pipe(pipe_) == 0);
	setup_success_test(&server, pipe_[1]);
	server.clients[1].direction = NORTH;
	assert(cmd_handler_ppo(&server, 1, argc, argv) == 0);
	read(pipe_[0], buffer, 512);
	assert(strcmp(buffer, expected_result) == 0);
	close(pipe_[0]);
	close(pipe_[1]);
}

Test(cmd_handler_ppo, success_east)
{
	int argc = 2;
	int pipe_[2];
	server_t server;
	char *argv[] = { "ppo", "1" };
	char buffer[512] = { 0 };
	char expected_result[] = "ppo 1 12 23 2\n";

	assert(pipe(pipe_) == 0);
	setup_success_test(&server, pipe_[1]);
	server.clients[1].direction = EAST;
	assert(cmd_handler_ppo(&server, 1, argc, argv) == 0);
	read(pipe_[0], buffer, 512);
	assert(strcmp(buffer, expected_result) == 0);
	close(pipe_[0]);
	close(pipe_[1]);
}

Test(cmd_handler_ppo, success_south)
{
	int argc = 2;
	int pipe_[2];
	server_t server;
	char *argv[] = { "ppo", "1" };
	char buffer[512] = { 0 };
	char expected_result[] = "ppo 1 12 23 3\n";

	assert(pipe(pipe_) == 0);
	setup_success_test(&server, pipe_[1]);
	server.clients[1].direction = SOUTH;
	assert(cmd_handler_ppo(&server, 1, argc, argv) == 0);
	read(pipe_[0], buffer, 512);
	assert(strcmp(buffer, expected_result) == 0);
	close(pipe_[0]);
	close(pipe_[1]);
}

Test(cmd_handler_ppo, success_west)
{
	int argc = 2;
	int pipe_[2];
	server_t server;
	char *argv[] = { "ppo", "1" };
	char buffer[512] = { 0 };
	char expected_result[] = "ppo 1 12 23 4\n";

	assert(pipe(pipe_) == 0);
	setup_success_test(&server, pipe_[1]);
	server.clients[1].direction = WEST;
	assert(cmd_handler_ppo(&server, 1, argc, argv) == 0);
	read(pipe_[0], buffer, 512);
	assert(strcmp(buffer, expected_result) == 0);
	close(pipe_[0]);
	close(pipe_[1]);
}