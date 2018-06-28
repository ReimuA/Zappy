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
	server->clients[1].level = 132;
	server->clients[1].fd = fd;
	return 0;
}

Test(cmd_handler_plv, success)
{
	int argc = 2;
	int pipe_[2];
	server_t server;
	char *argv[] = { "plv", "1" };
	char buffer[512] = { 0 };
	char expected_result[] = "plv 1 132\n";

	assert(pipe(pipe_) == 0);
	setup_success_test(&server, pipe_[1]);
	assert(cmd_handler_plv(&server, 1, argc, argv) == 0);
	read(pipe_[0], buffer, 512);
	assert(strcmp(buffer, expected_result) == 0);
	close(pipe_[0]);
	close(pipe_[1]);
}