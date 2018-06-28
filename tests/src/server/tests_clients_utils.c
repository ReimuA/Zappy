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
#include "client.h"

Test(client, init)
{
	client_t client;

	client_init(&client);
	assert(client.fd == -1);
	assert(client.pos_x == 0);
	assert(client.pos_y == 0);
	assert(client.open == true);
	assert(client.buffer == NULL);
	assert(client.team_name == NULL);
	assert(client.graphical == false);
}

Test(client, set_graphical)
{
	client_t client;

	client_init(&client);
	client_set_graphical(&client, "GRAPHIC");
	assert(client.graphical == true);
	assert(strcmp(client.team_name, "GRAPHIC") == 0);
}

Test(client, set_graphical_error)
{
	client_t client;

	client_init(&client);
	client_set_graphical(&client, "GRAPHICdqs");
	assert(client.team_name == NULL);
	assert(client.graphical == false);
}

Test(client, reset)
{
	client_t client;

	client_init(&client);
	client_reset_slot(&client);
	assert(client.fd == -1);
	assert(client.pos_x == 0);
	assert(client.pos_y == 0);
	assert(client.level == 1);
	assert(client.open == true);
	assert(client.buffer == NULL);
	assert(client.team_name == NULL);
	assert(client.graphical == false);
}
