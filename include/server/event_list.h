/*
** EPITECH PROJECT, 2018
** singe
** File description:
** singe
*/

#pragma once

#include <stdlib.h>
#include <sys/time.h>

#include "event.h"

struct event_list_s {
	struct event_s *event;
	struct event_list_s *next;
	struct event_list_s *previous;
};
typedef struct event_list_s event_list_t;

int event_list_len(event_list_t *list);
event_list_t *event_list_node(event_t *event);
void event_list_purge(event_list_t **list, int client);
void event_list_insert(event_list_t **, event_list_t *node);
int event_list_nb_client_request(event_list_t *list, int client_nbr);
void event_list_unlink(event_list_t **event_list, event_list_t *node);