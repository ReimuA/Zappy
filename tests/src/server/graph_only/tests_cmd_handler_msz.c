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
	server->flag.width = 120;
	server->flag.height = 148;
	server->clients[0].fd = fd;
	return 0;
}

Test(cmd_handler_msz, success)
{
	int argc = 1;
	int pipe_[2];
	server_t server;
	char *argv[] = { "msz" };
	char buffer[512] = { 0 };
	char expected_result[] = "msz 120 148\n";

	assert(pipe(pipe_) == 0);
	setup_success_test(&server, pipe_[1]);
	assert(cmd_handler_msz(&server, 0, argc, argv) == 0);
	read(pipe_[0], buffer, 512);
	assert(strcmp(buffer, expected_result) == 0);
	close(pipe_[0]);
	close(pipe_[1]);
}