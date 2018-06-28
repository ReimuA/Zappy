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
#include "world.h"
#include "server.h"
#include "materials_event.h"

Test(materials_event, callback)
{
	server_t server = {
		.flag = {
			.freq = 100,
			.width = 10,
			.height = 10
		}
	};

	world_init(&server.world, 10, 10);
	assert(materials_event_callback(&server, 0, 0, NULL) == 0);
}
