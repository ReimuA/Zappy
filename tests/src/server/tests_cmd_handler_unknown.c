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

Test(cmd_handler_unknown, success)
{
	int argc = 1;
	int pipe_[2];
	server_t server;
	char *argv[] = { "unknown" };
	char buffer[512] = { 0 };
	char expected_result[] = "ko\n";

	assert(pipe(pipe_) == 0);
	server.clients[0].fd = pipe_[1];
	assert(cmd_handler_unknown(&server, 0, argc, argv) == 0);
	read(pipe_[0], buffer, 512);
	assert(strcmp(buffer, expected_result) == 0);
	close(pipe_[0]);
	close(pipe_[1]);
}