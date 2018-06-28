/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** fd
*/

#include "server.h"
#include "middleware.h"
#include "food_event.h"
#include "cmd_handler.h"

static const cmd_t command_helper[] = {
	{ "bct",		LIST_GRAPH,	cmd_handler_bct		},
	{ "msz",		LIST_GRAPH,	cmd_handler_msz		},
	{ "mct",		LIST_GRAPH,	cmd_handler_mct		},
	{ "pin",		LIST_GRAPH_TARGET, cmd_handler_pin	},
	{ "plv",		LIST_GRAPH_TARGET, cmd_handler_plv	},
	{ "ppo",		LIST_GRAPH_TARGET, cmd_handler_ppo	},
	{ "sgt",		LIST_GRAPH,	cmd_handler_sgt		},
	{ "sst",		LIST_GRAPH,	cmd_handler_sst		},
	{ "tna",		LIST_GRAPH,	cmd_handler_tna		},
	{ "Set",		LIST_AI, 	cmd_handler_set		},
	{ "Left",		LIST_AI, 	cmd_handler_left	},
	{ "Look",		LIST_AI, 	cmd_handler_look	},
	{ "Fork",		LIST_AI, 	cmd_handler_fork	},
	{ "Take",		LIST_AI, 	cmd_handler_take	},
	{ "Right",		LIST_AI, 	cmd_handler_right	},
	{ "Eject",		LIST_AI, 	cmd_handler_eject	},
	{ "Forward",		LIST_AI, 	cmd_handler_forward	},
	{ "Elevation",		LIST_AI, 	cmd_handler_elevation	},
	{ "Inventory",		LIST_AI, 	cmd_handler_inventory	},
	{ "Broadcast",		LIST_AI, 	cmd_handler_broadcast	},
	{ "Connect_nbr",	LIST_AI, 	cmd_handler_connect_nbr	},
	{ NULL,			NO_MDW,		cmd_handler_unknown	}
};

static int server_process_clients_cmd(server_t *server, int client, char **cmd)
{
	int i = 0;
	bool (*middleware)(server_t *, int, int, char **);

	for (i = 0; command_helper[i].name != NULL; i++) {
		if (strcmp(command_helper[i].name, cmd[0]) == 0)
			break;
	}
	for (int j = 0; command_helper[i].middleware[j] != NULL; j++) {
		middleware = command_helper[i].middleware[j];
		if (middleware(server, client, tablen(cmd), cmd) != true) {
			cmd_handler_unknown(server, client, tablen(cmd), cmd);
			return -1;
		}
	}
	return command_helper[i].callback(server, client, tablen(cmd), cmd);
}

static int server_start_client_cmd(server_t *server, int i)
{
	char **cmd;
	int result = 0;

	cmd = explode(server->clients[i].buffer, " \t");
	if (cmd != NULL && cmd[0] != NULL)
		result = server_process_clients_cmd(server, i, cmd);
	free(cmd);
	return result;
}

/*
** Loop is now useless.
*/

int server_handle_clients_cmd(server_t *server, int i)
{
	char *idx = strchr(server->clients[i].buffer, '\n');
	char *tmp = server->clients[i].buffer;

	while (idx != NULL) {
		*idx = '\0';
		if (server->clients[i].team_name == NULL)
			server_get_client_team_name(server, i);
		else
			server_start_client_cmd(server, i);
		server->clients[i].buffer = strdup(idx + 1);
		free(tmp);
		tmp = server->clients[i].buffer;
		idx = strchr(server->clients[i].buffer, '\n');
		break;
	}
	return 0;
}
