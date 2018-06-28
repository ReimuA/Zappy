/*
** EPITECH PROJECT, 2018
** singe
** File description:
** singe
*/

#include <stdio.h>
#include <assert.h>
#include <unistd.h>
#include <criterion/criterion.h>
#include "server.h"
#include "middleware.h"

static const event_parameter_t base_param = {
	.argc = 0,
	.argv = NULL,
	.client_nbr = 23
};

Test(mdw_request_limiter, accept)
{
	int argc = 0;
	server_t server;
	char **argv = NULL;
	event_list_t *list = NULL;
	int client = base_param.client_nbr;
	event_parameter_t param = base_param;

	event_list_insert(&list, event_list_node(new_event(&param, 0, NULL)));
	event_list_insert(&list, event_list_node(new_event(&param, 1, NULL)));
	event_list_insert(&list, event_list_node(new_event(&param, 2, NULL)));
	event_list_insert(&list, event_list_node(new_event(&param, 3, NULL)));
	event_list_insert(&list, event_list_node(new_event(&param, 4, NULL)));
	event_list_insert(&list, event_list_node(new_event(&param, 5, NULL)));
	event_list_insert(&list, event_list_node(new_event(&param, 6, NULL)));
	event_list_insert(&list, event_list_node(new_event(&param, 7, NULL)));
	event_list_insert(&list, event_list_node(new_event(&param, 8, NULL)));
	event_list_insert(&list, event_list_node(new_event(&param, 9, NULL)));
	server.event_list = list;
	assert(mdw_request_limiter(&server, client, argc, argv) == true);
}

Test(mdw_request_limiter, reject)
{
	server_t server;
	event_list_t *list = NULL;
	int client = base_param.client_nbr;
	event_parameter_t param = base_param;

	close(STDOUT_FILENO);
	event_list_insert(&list, event_list_node(new_event(&param, 0, NULL)));
	event_list_insert(&list, event_list_node(new_event(&param, 1, NULL)));
	event_list_insert(&list, event_list_node(new_event(&param, 2, NULL)));
	event_list_insert(&list, event_list_node(new_event(&param, 3, NULL)));
	event_list_insert(&list, event_list_node(new_event(&param, 4, NULL)));
	event_list_insert(&list, event_list_node(new_event(&param, 5, NULL)));
	event_list_insert(&list, event_list_node(new_event(&param, 6, NULL)));
	event_list_insert(&list, event_list_node(new_event(&param, 7, NULL)));
	event_list_insert(&list, event_list_node(new_event(&param, 8, NULL)));
	event_list_insert(&list, event_list_node(new_event(&param, 9, NULL)));
	event_list_insert(&list, event_list_node(new_event(&param, 10, NULL)));
	server.event_list = list;
	assert(mdw_request_limiter(&server, client, 0, NULL) == false);
}
