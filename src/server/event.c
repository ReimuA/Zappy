/*
** EPITECH PROJECT, 2018
** singe
** File description:
** singe
*/

#include "misc.h"
#include "event.h"

int event_start_event(event_t *event, struct server_s *server)
{
	return event->callback(server,
		event->parameter.client_nbr,
		event->parameter.argc,
		event->parameter.argv);
}

event_t *new_event(event_parameter_t *parameter,
	suseconds_t trigger_time,
	int (*callback)(struct server_s *, int client_nbr, int ac, char **av))
{
	event_t *new = malloc(sizeof(event_t));

	if (new == NULL)
		return NULL;
	*new = (event_t) {
		.callback = callback,
		.parameter = {
			.argc = parameter->argc,
			.client_nbr = parameter->client_nbr,
			.argv = tabcpy(parameter->argv, parameter->argc)
		},
		.trigger_time = trigger_time
	};
	return new;
}
