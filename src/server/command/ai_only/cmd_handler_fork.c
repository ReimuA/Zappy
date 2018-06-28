/*
** EPITECH PROJECT, 2018
** singe
** File description:
** singe
*/

#include "server.h"
#include "food_event.h"

int fork_egg_hatching(server_t *server, int client_nbr, int argc, char **argv)
{
	int i = 0;
	char buff[64];

	(void)client_nbr;
	for (;server->clients[i].open == false && i < MAX_CLIENTS; i++) {
	}
	if(i == MAX_CLIENTS || argc < 5)
		return -1;
	server->clients[i].fd = -1;
	server->clients[i].open = false;
	server->clients[i].buffer = NULL;
	server->clients[i].hatched = true;
	server->clients[i].pos_x = atoi(argv[2]);
	server->clients[i].pos_y = atoi(argv[3]);
	server->clients[i].egg_id = atoi(argv[4]);
	food_event_add_callback(server, i);
	server->clients[i].team_name = (char *)strtol(argv[1], NULL, 16);
	snprintf(buff, 64, "eht %d\n", atoi(argv[4]));
	server_graphical_broadcast(server, buff);
	return 0;
}

void fork_send_graph_info(server_t *server, int client_nbr, int id)
{
	char buff[512];

	client_t *client = &server->clients[client_nbr];

	snprintf(buff, 512, "enw %d %d %d %d\n",
		id, client_nbr, client->pos_x, client->pos_y);
	server_graphical_broadcast(server, buff);
}

int cmd_fork_callback(server_t *server,
	int client_nbr,
	int __attribute__((__unused__)) argc,
	char __attribute__((__unused__)) **argv)
{
	static int id = 0;
	struct timeval tv;
	client_t *client = &server->clients[client_nbr];
	suseconds_t ms = 0;
	suseconds_t trigger_date = 0;
	char buff[512];
	event_parameter_t param = { .argc = 5, .client_nbr = -1 };

	snprintf(buff, 512, "%s %p %d %d %d", "hatching",
		client->team_name, client->pos_x, client->pos_y, id);
	param.argv = explode(strdup(buff), " ");
	fork_send_graph_info(server, client_nbr, id++);
	gettimeofday(&tv, NULL);
	ms = tv.tv_sec * 1000000 + tv.tv_usec;
	trigger_date = ms + (1000000 / server->flag.freq) * 600;
	event_t *evt = new_event(&param, trigger_date, fork_egg_hatching);
	event_list_t *node = event_list_node(evt);
	event_list_insert(&server->event_list, node);
	write(server->clients[client_nbr].fd, "ok\n", 3);
	return 0;
}

int cmd_handler_fork(server_t *server, int client, int argc, char **argv)
{
	struct timeval tv;
	suseconds_t ms = 0;
	suseconds_t trigger_date = 0;
	event_parameter_t param = {
		.argc = argc,
		.argv = argv,
		.client_nbr = client
	};

	(void)argc;
	(void)argv;
	gettimeofday(&tv, NULL);
	ms = tv.tv_sec * 1000000 + tv.tv_usec;
	trigger_date = ms + (1000000 / server->flag.freq) * 42;
	event_t *evt = new_event(&param, trigger_date, cmd_fork_callback);
	event_list_t *node = event_list_node(evt);
	event_list_insert(&server->event_list, node);
	return 0;
}
