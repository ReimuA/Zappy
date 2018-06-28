/*
** EPITECH PROJECT, 2018
** singe
** File description:
** singe
*/

#include "event_list.h"

int event_list_nb_client_request(event_list_t *list, int client_nbr)
{
	int i = 0;

	while (list != NULL) {
		if (list->event->parameter.client_nbr == client_nbr)
			i++;
		list = list->next;
	}
	return i;
}
