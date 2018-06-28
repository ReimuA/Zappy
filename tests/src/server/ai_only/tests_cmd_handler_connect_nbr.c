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

static void setup_test(server_t *server, int fd)
{
	char *tab[] = { "lol", NULL };
	*server = (server_t) { 
		.flag = {
			.freq = 100,
			.team_names = tabdup(tab),
			.max_team_nbr = 10
		},
		.event_list = NULL
	};
	server->clients[0].fd = fd;
	server->clients[0].open = false;
	server->clients[0].team_name = "lol";
	server->clients[1].team_name = "lol";
	server->clients[2].team_name = "lol";
}

Test(cmd_handler_connect_nbr, tests)
{
	int argc = 0;
	int pipe_[2];
	server_t server;
	int client_nbr = 0;
	char **argv = NULL;
	char buff[32] = { 0 };
	char *expected_result = "7\n";

	assert(pipe(pipe_) == 0);
	setup_test(&server, pipe_[1]);
	cmd_handler_connect_nbr(&server, client_nbr, argc, argv);
	assert(server.event_list == NULL);
	read(pipe_[0], buff, 32);
	assert(strcmp(buff, expected_result) == 0);
	close(pipe_[0]);
	close(pipe_[1]);
}
