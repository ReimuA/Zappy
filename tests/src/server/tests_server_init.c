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

Test(server_init, invalid_port)
{
	server_t server;
	char *argv[] = { "./zappy", NULL };
	flag_t flag = {
		.port = 1,
	};

	close(STDOUT_FILENO);
	close(STDERR_FILENO);
	server.flag = flag;
	assert(server_init(&server, 1, argv) == -1);
}

Test(server_init, valid_port)
{
	server_t server;
	char *argv[] = { "./zappy", NULL };
	flag_t flag = {
		.port = 4242,
		.freq = 100
	};

	close(STDOUT_FILENO);
	server.event_list = NULL;
	server.flag = flag;
	assert(server_init(&server, 1, argv) == 0);
	close(server.fd);
}