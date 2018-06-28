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

Test(cmd_handler_inventory, tests)
{
	int argc = 0;
	int client_nbr = 0;
	char **argv = NULL;
	server_t server = { 
		.flag = {
			.freq = 100
		},
		.event_list = NULL
	};

	cmd_handler_inventory(&server, client_nbr, argc, argv);
	assert(server.event_list->event->parameter.argc == 0);
	assert(server.event_list->event->parameter.argv == NULL);
	assert(server.event_list->event->parameter.client_nbr == 0);
	assert(server.event_list->event->callback == cmd_inventory_callback);
}

static void setup_test(inventory_t *inv, char expected_result[1024])
{
	*inv = (inventory_t) {
		.food = 123,
		.linemate = 0,
		.deraumere = 12,
		.sibur = 11,
		.mendiane = 42,
		.phiras = 32,
		.thystame = 666
	};
	snprintf(expected_result, 1024,
		"[ %s %d, %s %d, %s %d, %s %d, %s %d, %s %d, %s %d ]\n",
		"food", inv->food, 
		"linemate", inv->linemate,
		"deraumere", inv->deraumere,
		"sibur", inv->sibur,
		"mendiane", inv->mendiane,
		"phiras", inv->phiras,
		"thystame", inv->thystame);
}

Test(cmd_handler_inventory, callback)
{
	int argc = 0;
	int pipe_[2];
	server_t server;
	int client_nbr = 0;
	char **argv = NULL;
	char buffer[1024] = { 0 };
	char expected_result[1024];

	assert(pipe(pipe_) == 0);
	setup_test(&server.clients[client_nbr].inventory, expected_result);
	server.clients[client_nbr].fd = pipe_[1];
	cmd_inventory_callback(&server, client_nbr, argc, argv);
	read(pipe_[0], buffer, 1024);
	assert(strcmp(buffer, expected_result) == 0);
	close(pipe_[0]);
	close(pipe_[1]);
}
