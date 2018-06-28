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

Test(cmd_handler_look, tests)
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

	cmd_handler_look(&server, client_nbr, argc, argv);
	assert(server.event_list->event->parameter.argc == 0);
	assert(server.event_list->event->parameter.argv == NULL);
	assert(server.event_list->event->parameter.client_nbr == 0);
	assert(server.event_list->event->callback == cmd_look_callback);
}
