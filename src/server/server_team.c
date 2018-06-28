/*
** EPITECH PROJECT, 2018
** singe
** File description:
** singe
*/

#include "server.h"

int server_get_team_member_nbr(server_t *server, const char *team_names)
{
	int count = 0;
	client_t *client;

	for (int i = 0; i < MAX_CLIENTS; i++) {
		client = &server->clients[i];
		if (client->open == false &&
			client->team_name != NULL &&
			strcmp(client->team_name, team_names) == 0)
			count++;
	}
	return count;
}

int server_get_hatched_eggs_nbr(server_t *server, const char *team_names)
{
	int count = 0;
	client_t *client;

	for (int i = 0; i < MAX_CLIENTS; i++) {
		client = &server->clients[i];
		if (client->hatched == true &&
			client->open == false &&
			client->team_name != NULL &&
			strcmp(client->team_name, team_names) == 0)
			count++;
	}
	return count;
}

bool server_is_team_name_valid(server_t *server, const char *s)
{
	if (s == NULL)
		return false;
	for (int i = 0; server->flag.team_names[i] != NULL; i++) {
		if (strcmp(server->flag.team_names[i], s) == 0)
			return true;
	}
	return false;
}

int server_get_free_team_slot_nbr(server_t *server, const char *s)
{
	int actual_team_member;
	int team_hatched_eggs;
	int max_team_member = server->flag.max_team_nbr;

	if (s == NULL || server_is_team_name_valid(server, s) == false)
		return 0;
	actual_team_member = server_get_team_member_nbr(server, s);
	team_hatched_eggs = server_get_hatched_eggs_nbr(server, s);

	return max_team_member - actual_team_member + team_hatched_eggs * 2;
}