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
#include "client.h"
#include "server.h"

Test(server_handle_cmd, graphic)
{
	int argc = 2;
	char *argv[] = { "-n", "team1", NULL };
	server_t server;

	close(STDOUT_FILENO);
	flag_init(&server.flag, argc, argv);
	client_init(&server.clients[0]);
	server.clients[0].buffer = strdup("GRAPHIC\n");
	server.clients[0].team_name = NULL;
	server_handle_clients_cmd(&server, 0);
	assert(server.clients[0].graphical == true);
	assert(strcmp(server.clients[0].buffer, "") == 0);
	assert(strcmp(server.clients[0].team_name, "GRAPHIC") == 0);
}

Test(server_handle_cmd, join_team)
{
	int argc = 2;
	char *argv[] = { "-n", "team1", NULL };
	server_t server;

	memset(&server, '\0', sizeof(server));
	close(STDOUT_FILENO);
	for (int i = 0; i < MAX_CLIENTS; i++)
		server.clients[i].open = true;
	flag_init(&server.flag, argc, argv);
	client_init(&server.clients[0]);
	server.clients[0].team_name = NULL;
	server.clients[0].buffer = strdup("team1\n");
	server_handle_clients_cmd(&server, 0);
	assert(server.clients[0].graphical == false);
	assert(strcmp(server.clients[0].buffer, "") == 0);
	assert(strcmp(server.clients[0].team_name, "team1") == 0);
}

Test(server_handle_cmd, connect_nbr_cmd)
{
	int argc = 2;
	char *argv[] = { "-n", "team1", NULL };
	server_t server;

	close(STDOUT_FILENO);
	memset(&server, '\0', sizeof(server));
	for (int i = 0; i < MAX_CLIENTS; i++)
		server.clients[i].open = true;
	flag_init(&server.flag, argc, argv);
	client_init(&server.clients[0]);
	server.clients[0].team_name = NULL;
	server.clients[0].buffer = strdup("team1\nConnect_nbr\n");
	server_handle_clients_cmd(&server, 0);
	assert(server.clients[0].graphical == false);
	assert(strcmp(server.clients[0].team_name, "team1") == 0);
	assert(strcmp(server.clients[0].buffer, "Connect_nbr\n") == 0);
}
