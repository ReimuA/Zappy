/*
** EPITECH PROJECT, 2018
** singe
** File description:
** singe
*/

#include "server.h"
#include "cmd_handler.h"

int cmd_handler_mct(server_t *server, int cli, int argc, char **argv)
{
	char buff[128];
	int bct_argc = 3;
	char **bct_argv = NULL;

	(void)argc;
	(void)argv;
	for (int j = 0; j < server->flag.height; j++) {
		for (int i = 0; i < server->flag.width; i++) {
			snprintf(buff, 128, "bct %d %d", i, j);
			bct_argv = explode(buff, " ");
			cmd_handler_bct(server, cli, bct_argc, bct_argv);
			free(bct_argv);
		}
	}
	return 0;
}