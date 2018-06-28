/*
** EPITECH PROJECT, 2018
** singe
** File description:
** singe
*/

#include "server.h"

/*
** Limit pending number of request to 10.
*/

bool mdw_request_limiter(server_t *server, int client, int argc, char **argv)
{
	int i = 0;
	event_list_t *list = server->event_list;

	(void)argc;
	(void)argv;
	while (list != NULL) {
		if (list->event->parameter.client_nbr == client)
			i++;
		if (i > 10) {
			fprintf(stdout, "Client number %d: %s %s\n", client,
				"request was rejected because there is",
				"already 10 pending request.");
			return false;
		}
		list = list->next;
	}
	return true;
}