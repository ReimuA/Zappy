/*
** EPITECH PROJECT, 2018
** singe
** File description:
** singe
*/

#include <time.h>
#include <signal.h>
#include "server.h"

int main(int argc, char **argv)
{
	server_t server;

	srand(time(NULL));
	signal(SIGPIPE, SIG_IGN);
	if (flag_init(&server.flag, argc, argv) != 0)
		return EXIT_FAILURE;
	if (world_init(&server.world, server.flag.width, server.flag.height))
		return 1;
	if (server_init(&server, argc, argv) != 0)
		return EXIT_FAILURE;
	server_process(&server);
	return EXIT_SUCCESS;
}
