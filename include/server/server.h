/*
** EPITECH PROJECT, 2018
** singe
** File description:
** singe
*/

#pragma once

#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <arpa/inet.h>

#include "misc.h"
#include "flag.h"
#include "world.h"
#include "client.h"
#include "event_list.h"

#undef EXIT_FAILURE
#define EXIT_FAILURE (84)

#undef EXIT_SUCCESS
#define EXIT_SUCCESS (0)

#define MAX_CLIENTS (1024)

/*
** Server's definition.
*/

struct server_s {
	int fd;
	int port;
	flag_t flag;
	fd_set efds;
	fd_set rfds;
	fd_set wfds;
	world_t world;
	const char *bin_name;
	event_list_t *event_list;
	client_t clients[MAX_CLIENTS];
};
typedef struct server_s server_t;


/*
** Command's helper.
*/

#define MAX_MIDDLEWARE_NBR (12)

struct cmd_s {
	const char *name;
	bool (*middleware[MAX_MIDDLEWARE_NBR])(server_t *, int, int, char **);
	int (*callback)(server_t *server, int client, int argc, char **argv);
};
typedef struct cmd_s cmd_t;


/*
** Server's function.
*/

bool game_over(server_t *server);

int server_get_fd_max(server_t *server);
void server_reset_fds(server_t *server);

int broadcast_direction(server_t *server,
	client_t *emitter,
	client_t *target);


int server_process(server_t *server);
int server_update_game(server_t *server);
int server_accept_connection(server_t *server);
int server_kick_client(server_t *server, int i);
int server_get_client_team_name(server_t *server, int i);
int server_init(server_t *server, int argc, char **argv);
int server_handle_clients_cmd(server_t *server, int client);
bool server_is_valid_team_name(server_t *server, const char *s);
void server_graphical_broadcast(server_t *server, const char *s);
int server_get_free_team_slot_nbr(server_t *server, const char *team_names);