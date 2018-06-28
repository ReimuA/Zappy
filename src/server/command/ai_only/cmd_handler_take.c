/*
** EPITECH PROJECT, 2018
** singe
** File description:
** singe
*/

#include "server.h"

static const cell_helper_t cell_helper[] = {
	{ "food",	offsetof(cell_t, food)		},
	{ "sibur",	offsetof(cell_t, sibur)		},
	{ "phiras",	offsetof(cell_t, phiras)	},
	{ "linemate",	offsetof(cell_t, linemate)	},
	{ "mendiane",	offsetof(cell_t, mendiane)	},
	{ "thystame",	offsetof(cell_t, thystame)	},
	{ "deraumere",	offsetof(cell_t, deraumere)	},
	{ NULL,		0				}
};

int cmd_take_exec(server_t *server, int client_nbr, int offset)
{
	char buff[512];
	client_t *client = &server->clients[client_nbr];
	char *inv = (char *)&client->inventory;
	char *cell = (char *)&server->world.map[client->pos_y][client->pos_x];
	int *inv_resources_ptr = (int *)(&inv[offset]);
	int *cell_resources_ptr = (int *)(&cell[offset]);

	if (*cell_resources_ptr == 0)
		return -1;
	*inv_resources_ptr += 1;
	*cell_resources_ptr -= 1;
	snprintf(buff, 512, "pgt %d\n", client_nbr);
	server_graphical_broadcast(server, buff);
	return 0;
}

int cmd_take_callback(server_t *server,
	int client_nbr,
	int __attribute__((__unused__)) argc,
	char __attribute__((__unused__)) **argv)
{
	int i = 0;
	int result;
	char buff[4] = { 0 };

	for (; cell_helper[i].name != NULL; i++) {
		if (strcmp(cell_helper[i].name, argv[1]) == 0)
			break;
	}
	result = cmd_take_exec(server, client_nbr, cell_helper[i].offset);
	snprintf(buff, 4, "%s\n", result == 0 ? "ok" : "ko");
	write(server->clients[client_nbr].fd, buff, strlen(buff));
	return 0;
}

static int cmd_handler_take_error(server_t *server,
	int client,
	int argc,
	char **argv)
{
	int i = 0;

	if (argc < 2) {
		write(server->clients[client].fd, "ko\n", strlen("ko\n"));
		return -1;
	}
	for (; cell_helper[i].name != NULL; i++) {
		if (strcmp(cell_helper[i].name, argv[1]) == 0)
			break;
	}
	if (cell_helper[i].name == NULL) {
		write(server->clients[client].fd, "ko\n", strlen("ko\n"));
		return -1;
	}
	return 0;
}

int cmd_handler_take(server_t *server, int client, int argc, char **argv)
{
	struct timeval tv;
	suseconds_t ms = 0;
	suseconds_t trigger_date = 0;
	event_parameter_t param = {
		.argc = argc,
		.argv = argv,
		.client_nbr = client
	};

	if (cmd_handler_take_error(server, client, argc, argv) != 0)
		return 1;
	gettimeofday(&tv, NULL);
	ms = tv.tv_sec * 1000000 + tv.tv_usec;
	trigger_date = ms + (1000000 / server->flag.freq) * 7;
	event_t *evt = new_event(&param, trigger_date, cmd_take_callback);
	event_list_t *node = event_list_node(evt);
	event_list_insert(&server->event_list, node);
	return 0;
}