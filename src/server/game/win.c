/*
** EPITECH PROJECT, 2018
** singe
** File description:
** singe
*/

#include "server.h"

bool team_win(server_t *server, const char *team)
{
	int ascended = 0;

	for (int i = 0; i < MAX_CLIENTS; i++) {
		if (server->clients[i].team_name != NULL &&
			server->clients[i].graphical == false &&
			strcmp(team, server->clients[i].team_name) == 0 &&
			server->clients[i].level >= 6)
			ascended++;
	}
	if (ascended >= 6)
		return true;
	return false;
}

bool game_over(server_t *server)
{
	const char *s;
	char buff[512];

	for (int i = 0; server->flag.team_names[i] != NULL; i++) {
		s = server->flag.team_names[i];
		if (team_win(server, s) == true) {
			fprintf(stdout, "%s has won.\n", s);
			snprintf(buff, 512, "seg %s\n", s);
			server_graphical_broadcast(server, buff);
			return true;
		}
	}
	return false;
}