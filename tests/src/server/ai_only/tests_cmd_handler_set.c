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

static void setup_test(server_t *server, int client_nbr, int fd)
{
	server->flag.freq = 100;
	server->event_list = NULL;
	server->clients[client_nbr].fd = fd;
}

Test(cmd_handler_set, error_not_enough_arg)
{
	int pipe_[2];
	int argc = 1;
	int client_nbr = 0;
	char buffer[512] = { 0 };
	char *argv[] = { "set" };
	char *expected_result = "ko\n";
	server_t server;

	assert(pipe(pipe_) == 0);
	setup_test(&server, client_nbr, pipe_[1]);
	assert(cmd_handler_set(&server, client_nbr, argc, argv) != 0);
	read(pipe_[0], buffer, 512);
	assert(strcmp(buffer, expected_result) == 0);
	close(pipe_[0]);
	close(pipe_[1]);
}

Test(cmd_handler_set, invalid_res)
{
	int pipe_[2];
	int argc = 2;
	int client_nbr = 0;
	char buffer[512] = { 0 };
	char *argv[] = { "set", "Snoop dog" };
	char *expected_result = "ko\n";
	server_t server;

	assert(pipe(pipe_) == 0);
	setup_test(&server, client_nbr, pipe_[1]);
	assert(cmd_handler_set(&server, client_nbr, argc, argv) != 0);
	read(pipe_[0], buffer, 512);
	assert(strcmp(buffer, expected_result) == 0);
	close(pipe_[0]);
	close(pipe_[1]);
}

Test(cmd_handler_set, success)
{
	int argc = 2;
	server_t server;
	int client_nbr = 0;
	event_parameter_t param;
	char *argv[] = { "set", "sibur" };

	setup_test(&server, client_nbr, STDOUT_FILENO);
	close(STDOUT_FILENO);
	assert(cmd_handler_set(&server, client_nbr, argc, argv) == 0);
	param = server.event_list->event->parameter;
	assert(strcmp(param.argv[0], "set") == 0);
	assert(strcmp(param.argv[1], "sibur") == 0);
	assert(server.event_list->event->parameter.argc == 2);
	assert(server.event_list->event->parameter.client_nbr == 0);
	assert(server.event_list->event->callback == cmd_set_callback);
}

static void init_set_callback_test(client_t *client, int fd, int sibur)
{
	client->pos_x = 1;
	client->pos_y = 1;
	client->fd = fd;
	client->inventory.sibur = sibur;
}

Test(set_callback, success)
{
	int argc = 2;
	int pipe_[2];
	client_t *client;
	int client_nbr = 0;
	char buff[4] = { 0 };
	server_t server = { 0 };
	char *argv[] = { "set", "sibur" };
	char *expected_result = "ok\n";

	assert(pipe(pipe_) == 0);
	client = &server.clients[client_nbr];
	init_set_callback_test(client, pipe_[1], 1);
	world_init(&server.world, 5, 5);
	server.world.map[client->pos_y][client->pos_x].sibur = 0;
	assert(cmd_set_callback(&server, client_nbr, argc, argv) == 0);
	read(pipe_[0], buff, 4);
	assert(client->inventory.sibur == 0);
	assert(server.world.map[client->pos_y][client->pos_x].sibur == 1);
	assert(strcmp(buff, expected_result) == 0);
}

Test(set_callback, error)
{
	int argc = 2;
	int pipe_[2];
	client_t *client;
	int client_nbr = 0;
	char buff[4] = { 0 };
	server_t server = { 0 };
	char *argv[] = { "set", "sibur" };
	char *expected_result = "ko\n";

	assert(pipe(pipe_) == 0);
	client = &server.clients[client_nbr];
	init_set_callback_test(client, pipe_[1], 0);
	world_init(&server.world, 5, 5);
	server.world.map[client->pos_y][client->pos_x].sibur = 0;
	assert(cmd_set_callback(&server, client_nbr, argc, argv) == 0);
	read(pipe_[0], buff, 4);
	assert(client->inventory.sibur == 0);
	assert(server.world.map[client->pos_y][client->pos_x].sibur == 0);
	assert(strcmp(buff, expected_result) == 0);
}