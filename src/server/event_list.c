/*
** EPITECH PROJECT, 2018
** singe
** File description:
** singe
*/

#include "event_list.h"

event_list_t *event_list_node(event_t *event)
{
	event_list_t *list = malloc(sizeof(event_list_t));

	if (list == NULL)
		return NULL;
	list->event = event;
	list->next = list->previous = NULL;
	return list;
}

void event_list_insert(event_list_t **list, event_list_t *node)
{
	node->next = NULL;
	node->previous = NULL;
	if (*list != NULL) {
		(*list)->previous = node;
		node->next = *list;
	}
	*list = node;
}

int event_list_lenght(event_list_t *list)
{
	int i = 0;

	while (list != NULL) {
		i++;
		list = list->next;
	}
	return i;
}

void event_list_purge(event_list_t **list, int client)
{
	event_list_t *it = *list;
	event_list_t *tmp = *list;

	while (it != NULL) {
		tmp = it->next;
		if (it->event->parameter.client_nbr == client)
			event_list_unlink(list, it);
		it = tmp;
	}
}

void event_list_unlink(event_list_t **list, event_list_t *node)
{
	if (*list == node)
		*list = node->next;
	if (node->next)
		node->next->previous = node->previous;
	if (node->previous)
		node->previous->next = node->next;
	free(node->event);
	free(node);
}