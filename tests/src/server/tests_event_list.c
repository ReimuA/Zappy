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
#include "event_list.h"

static const event_parameter_t base_param = {
	.argc = 0,
	.argv = NULL,
	.client_nbr = 1
};

Test(event_list, create_node)
{
	event_parameter_t param = base_param;
	event_t *event = new_event(&param, 23, NULL);
	event_list_t *list = event_list_node(event);

	assert(list->next == NULL);
	assert(list->previous == NULL);
	assert(list->event == event);
}

Test(event_list, insert)
{
	event_parameter_t param = base_param;
	event_list_t *list = NULL;
	event_t *event1 = new_event(&param, 23, NULL);
	event_t *event2 = new_event(&param, 23, NULL);
	event_t *event3 = new_event(&param, 23, NULL);
	event_list_t *node1 = event_list_node(event1);
	event_list_t *node2 = event_list_node(event2);
	event_list_t *node3 = event_list_node(event3);

	event_list_insert(&list, node1);
	event_list_insert(&list, node2);
	event_list_insert(&list, node3);
	assert(list->event == event3);
	assert(list->next->event == event2);
	assert(list->next->next->event == event1);
}

Test(event_list, insert_and_unlink)
{
	event_parameter_t param = base_param;
	event_list_t *list = NULL;
	event_t *event1 = new_event(&param, 23, NULL);
	event_t *event2 = new_event(&param, 23, NULL);
	event_t *event3 = new_event(&param, 23, NULL);
	event_list_t *node1 = event_list_node(event1);
	event_list_t *node2 = event_list_node(event2);
	event_list_t *node3 = event_list_node(event3);

	event_list_insert(&list, node1);
	event_list_insert(&list, node2);
	event_list_insert(&list, node3);
	assert(list->event == event3);
	event_list_unlink(&list, node1);
	assert(list->event == event3);
	event_list_unlink(&list, node2);
	assert(list->event == event3);
	event_list_unlink(&list, node3);

}
