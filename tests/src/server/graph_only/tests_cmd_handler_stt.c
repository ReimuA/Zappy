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
	server->flag.freq = 1;
	server->clients[1].fd = fd;
	return 0;
}

Test(cmd_handler_sst, success)
{
	int argc = 2;
	int pipe_[2];
	server_t server;
	char *argv[] = { "sst", "132" };
	char buffer[512] = { 0 };
	char expected_result[] = "sst 132\n";

	assert(pipe(pipe_) == 0);
	setup_success_test(&server, pipe_[1]);
	assert(cmd_handler_sst(&server, 1, argc, argv) == 0);
	read(pipe_[0], buffer, 512);
	assert(strcmp(buffer, expected_result) == 0);
	assert(server.flag.freq == 132);
	close(pipe_[0]);
	close(pipe_[1]);
}

Test(cmd_handler_sst, failure)
{
	int argc = 1;
	int pipe_[2];
	server_t server;
	char *argv[] = { "sst" };
	char buffer[512] = { 0 };
	char expected_result[] = "sst 1\n";

	assert(pipe(pipe_) == 0);
	setup_success_test(&server, pipe_[1]);
	assert(cmd_handler_sst(&server, 1, argc, argv) == 0);
	read(pipe_[0], buffer, 512);
	assert(strcmp(buffer, expected_result) == 0);
	assert(server.flag.freq == 1);
	close(pipe_[0]);
	close(pipe_[1]);
}