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
	server->flag.width = 2;
	server->flag.height = 3;
	server->clients[0].fd = fd;
	return 0;
}

static void setup_execpeted_result(char expected_result[1024])
{
	snprintf(expected_result, 1024,
		"%s\n%s\n%s\n%s\n%s\n%s\n",
		"bct 0 0 0 0 0 0 0 0 0",
		"bct 1 0 0 0 0 0 0 0 0",
		"bct 0 1 0 0 0 0 0 0 0",
		"bct 1 1 0 0 0 0 0 0 0",
		"bct 0 2 0 0 0 0 0 0 0",
		"bct 1 2 0 0 0 0 0 0 0");
}


Test(cmd_handler_mct, success)
{
	int argc = 3;
	int pipe_[2];
	server_t server;
	char *argv[] = { "mct", "2", "3" };
	char buffer[1024] = { 0 };
	char expected_result[1024] = { 0 };

	assert(pipe(pipe_) == 0);
	setup_execpeted_result(expected_result);
	setup_success_test(&server, pipe_[1]);
	world_init(&server.world, server.flag.width, server.flag.height);
	assert(cmd_handler_mct(&server, 0, argc, argv) == 0);
	read(pipe_[0], buffer, 1024);
	assert(strcmp(buffer, expected_result) == 0);
	close(pipe_[0]);
	close(pipe_[1]);
}