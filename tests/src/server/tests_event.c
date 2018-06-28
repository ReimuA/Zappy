/*
** EPITECH PROJECT, 2018
** singe
** File description:
** singe
*/

#include <stdio.h>
#include <unistd.h>
#include <assert.h>
#include <criterion/criterion.h>
#include "event.h"

Test(event, new)
{
	event_parameter_t param = {
		.argc = 0,
		.argv = NULL,
		.client_nbr = 1
	};
	event_t *event = new_event(&param, 23, NULL);

	assert(event->callback == NULL);
	assert(event->trigger_time == 23);
	assert(event->parameter.argc == 0);
	assert(event->parameter.argv == NULL);
	assert(event->parameter.client_nbr == 1);
}
