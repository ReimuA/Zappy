/*
** EPITECH PROJECT, 2018
** singe
** File description:
** singe
*/

#include "server.h"

static int
cmd_handler_bct_error(server_t *server, int cli, int argc, char **argv)
{
	char buff[64];
	int pos_x;
	int pos_y;

	if (argc != 3) {
		snprintf(buff, 64, "bct ko: need 3 and only 3 parameter.\n");
		write(server->clients[cli].fd, buff, strlen(buff));
		return 1;
	}
	pos_x = atoi(argv[1]);
	pos_y = atoi(argv[2]);
	if (pos_x < 0 || pos_x >= server->flag.width ||
		pos_y < 0 || pos_y >= server->flag.height) {
		snprintf(buff, 64, "bct ko: invalid coordinate.\n");
		write(server->clients[cli].fd, buff, strlen(buff));
		return 1;
	}
	return 0;
}

static int
cmd_handler_bct_send_info(server_t *server, int cli, int argc, char **argv)
{
	char buff[256];
	int pos_x = atoi(argv[1]);
	int pos_y = atoi(argv[2]);
	cell_t *cell = &server->world.map[pos_y][pos_x];

	(void)argc;
	snprintf(buff, 256, "bct %d %d %d %d %d %d %d %d %d\n",
		pos_x,
		pos_y,
		cell->food,
		cell->linemate,
		cell->deraumere,
		cell->sibur,
		cell->mendiane,
		cell->phiras,
		cell->thystame);
	write(server->clients[cli].fd, buff, strlen(buff));
	return 0;
}

int cmd_handler_bct(server_t *server, int cli, int argc, char **argv)
{
	if (cmd_handler_bct_error(server, cli, argc, argv) != 0)
		return 1;
	cmd_handler_bct_send_info(server, cli, argc, argv);
	return 0;
}
