/*
** EPITECH PROJECT, 2018
** singe
** File description:
** singe
*/

#pragma once

#include <stdlib.h>
#include <sys/time.h>

struct server_s;

struct event_parameter_s {
	int argc;
	char **argv;
	int client_nbr;
};
typedef struct event_parameter_s event_parameter_t;

struct event_s {
	suseconds_t trigger_time;
	event_parameter_t parameter;
	int (*callback)(struct server_s *, int client_nbr, int ac, char **av);
};
typedef struct event_s event_t;


int event_start_event(event_t *event, struct server_s *server);
event_t *new_event(event_parameter_t *parameter,
	suseconds_t trigger_time,
	int (*callback)(struct server_s *, int client_nbr, int ac, char **av));