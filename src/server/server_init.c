/*
** EPITECH PROJECT, 2018
** singe
** File description:
** singe
*/

#include "server.h"
#include "materials_event.h"

static int server_init_socket(server_t *server)
{
	struct protoent *pro;

	pro = getprotobyname("TCP");
	if (pro == NULL)
		return -1;
	server->fd = socket(AF_INET, SOCK_STREAM, pro->p_proto);
	return 0;
}

static int server_bind_socket(server_t *server)
{
	int socket_opt = 0;
	struct sockaddr_in sa = {
		.sin_family = AF_INET,
		.sin_addr.s_addr = INADDR_ANY,
		.sin_port = htons((uint16_t)server->port)
	};

	if (setsockopt(server->fd, SOL_SOCKET, SO_REUSEADDR,
		&socket_opt, sizeof(socket_opt)) == -1)
		return -1;
	if (bind(server->fd, (const struct sockaddr *)&sa, sizeof(sa)) == -1)
		return -1;
	if (listen(server->fd, MAX_CLIENTS) == -1)
		return -1;
	fprintf(stdout, "Server is listening on port: %d\n", server->port);
	return 0;
}

static int server_init_clients(server_t *server)
{
	for (int i = 0; i < MAX_CLIENTS; i++)
		client_init(&server->clients[i]);
	return 0;
}

int server_init(server_t *server, int argc, char **argv)
{
	(void)argc;
	server->event_list = NULL;
	server->bin_name = argv[0];
	server->port = server->flag.port;
	if (server_init_socket(server) || server_bind_socket(server)) {
		fprintf(stderr, "%s: Cannot start server.\n",
			server->bin_name);
		return -1;
	}
	server_init_clients(server);
	materials_event_add_callback(server, -1);
	return 0;
}