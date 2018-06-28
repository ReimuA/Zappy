/*
** EPITECH PROJECT, 2018
** singe
** File description:
** singe
*/

#pragma once

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stddef.h>
#include <stdlib.h>

#include "misc.h"

#define DFL_PORT 	(4242)
#define DFL_FREQ 	(100)
#define DFL_WIDTH 	(10)
#define DFL_HEIGHT 	(10)
#define DFL_TEAM_NUMBER (10)

struct flag_s {
	int port;
	int freq;
	int width;
	int height;
	int max_team_nbr;
	char **team_names;
};
typedef struct flag_s flag_t;

struct argument_helper_s {
	const char *name;
	int offset;
	int (*callback)(const char *);
};
typedef struct argument_helper_s argument_helper_t;

int flag_init(flag_t *flag, int argc, char **argv);