/*
** EPITECH PROJECT, 2018
** singe
** File description:
** singe
*/

#include <assert.h>
#include <criterion/criterion.h>
#include "server.h"

static void init_client(client_t *client, int level, const char *s)
{
	*client = (client_t) {
		.level = level,
		.team_name = s,
		.graphical = false
	};
}

Test(gameover, false_)
{
	char *team_names[] = { "Lol", "Mdr", "Xd", NULL };
	server_t server = { 0 };
	
	server.flag.team_names = team_names;
	init_client(&server.clients[0], 1, team_names[0]);
	init_client(&server.clients[1], 2, team_names[2]);
	init_client(&server.clients[2], 7, team_names[0]);
	init_client(&server.clients[3], 7, team_names[1]);
	init_client(&server.clients[4], 7, team_names[1]);
	init_client(&server.clients[5], 7, team_names[1]);
	init_client(&server.clients[6], 7, team_names[1]);
	init_client(&server.clients[7], 3, team_names[1]);
	init_client(&server.clients[8], 7, team_names[1]);
	assert(game_over(&server) == false);
}

Test(gameover, true_)
{
	char *team_names[] = { "Lol", "Mdr", "Xd", NULL };
	server_t server = { 0 };
	
	close(STDOUT_FILENO);
	server.flag.team_names = team_names;
	init_client(&server.clients[0], 1, team_names[0]);
	init_client(&server.clients[1], 2, team_names[0]);
	init_client(&server.clients[2], 7, team_names[0]);
	init_client(&server.clients[3], 7, team_names[1]);
	init_client(&server.clients[4], 7, team_names[1]);
	init_client(&server.clients[5], 7, team_names[1]);
	init_client(&server.clients[6], 7, team_names[1]);
	init_client(&server.clients[7], 7, team_names[1]);
	init_client(&server.clients[8], 7, team_names[1]);
	assert(game_over(&server) == true);
}
