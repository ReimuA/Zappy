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
#include "food_event.h"

Test(food_event, food_event)
{
	int argc = 0;
	server_t server;
	char **argv = NULL;
	int client_nbr = 0;

	server.flag.freq = 100;
	server.flag.width = 10;
	server.flag.height = 10;
	server.flag.freq = 100;
	server.event_list = NULL;
	server.clients[client_nbr].inventory.food = 1;
	world_init(&server.world, 10, 10);

	food_event_callback(&server, client_nbr, argc, argv);
	assert(server.event_list != NULL);
	assert(server.clients[client_nbr].inventory.food == 0);
	assert(server.event_list->event->callback == food_event_callback);
}