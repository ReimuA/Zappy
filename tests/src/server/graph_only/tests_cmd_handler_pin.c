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
	server->clients[0].inventory = (inventory_t) {
		.food = 1,
		.sibur = 2,
		.phiras = 3,
		.linemate = 4,
		.mendiane = 5,
		.thystame = 6,
		.deraumere = 7
	};
	server->clients[0].fd = fd;
	return 0;
}

Test(cmd_handler_pin, success)
{
	int argc = 2;
	int pipe_[2];
	server_t server;
	char *argv[] = { "pin", "0" };
	char buffer[512] = { 0 };
	char expected_result[] = "pin 0 1 4 7 2 5 3 6\n";

	assert(pipe(pipe_) == 0);
	setup_success_test(&server, pipe_[1]);
	assert(cmd_handler_pin(&server, 0, argc, argv) == 0);
	read(pipe_[0], buffer, 512);
	assert(strcmp(buffer, expected_result) == 0);
	close(pipe_[0]);
	close(pipe_[1]);
}