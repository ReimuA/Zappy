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

static int setup_error_test(server_t *server)
{
	close(STDOUT_FILENO);
	server->flag.width = 10;
	server->flag.height = 10;
	server->clients[0].fd = STDOUT_FILENO;
	return 0;
}

static int setup_success_test(server_t *server, int fd)
{
	server->flag.width = 10;
	server->flag.height = 10;
	server->clients[0].fd = fd;
	return 0;
}

Test(cmd_handler_bct, error_parameter_nbr)
{
	server_t server;

	setup_error_test(&server);
	assert(cmd_handler_bct(&server, 0, 2, NULL) == 1);
	assert(cmd_handler_bct(&server, 0, 4, NULL) == 1);
}

Test(cmd_handler_bct, error_bad_parameter)
{
	int argc = 3;
	server_t server;
	char *argv1[] = { "bct", "1", "-1" }; 
	char *argv2[] = { "bct", "-1", "1" }; 
	char *argv3[] = { "bct", "1", "10" }; 
	char *argv4[] = { "bct", "10", "1" }; 

	setup_error_test(&server);
	assert(cmd_handler_bct(&server, 0, argc, argv1) == 1);
	assert(cmd_handler_bct(&server, 0, argc, argv2) == 1);
	assert(cmd_handler_bct(&server, 0, argc, argv3) == 1);
	assert(cmd_handler_bct(&server, 0, argc, argv4) == 1);
}

Test(cmd_handler_bct, success)
{
	int argc = 3;
	int pipe_[2];
	server_t server;
	char *argv[] = { "bct", "2", "3" };
	char buffer[512] = { 0 };
	char expected_result[] = "bct 2 3 1 4 7 2 5 3 6\n";

	assert(pipe(pipe_) == 0);
	setup_success_test(&server, pipe_[1]);
	world_init(&server.world, server.flag.width, server.flag.height);
	server.world.map[3][2] = (cell_t) {
		.food = 1, .sibur = 2, .phiras = 3, .linemate = 4,
		.mendiane = 5, .thystame = 6, .deraumere = 7
	};
	assert(cmd_handler_bct(&server, 0, argc, argv) == 0);
	read(pipe_[0], buffer, 512);
	assert(strcmp(buffer, expected_result) == 0);
	close(pipe_[0]);
	close(pipe_[1]);
}