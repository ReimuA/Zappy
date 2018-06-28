/*
** EPITECH PROJECT, 2018
** singe
** File description:
** singe
*/

#pragma once

#include <math.h>

#ifndef M_PI_2
# define M_PI_2 (M_PI / 2)
#endif

#ifndef M_PI_4
# define M_PI_4 (M_PI / 4)
#endif

#ifndef M_PI_8
# define M_PI_8 (M_PI / 8)
#endif

enum sound_direction {
	SOUND_NONE = 0,
	SOUND_EAST = 7,
	SOUND_WEST = 3,
	SOUND_NORTH = 1,
	SOUND_SOUTH = 5,
	SOUND_NORTH_EAST = 8,
	SOUND_NORTH_WEST = 2,
	SOUND_SOUTH_EAST = 6,
	SOUND_SOUTH_WEST = 4
};

struct vector_s {
	int x;
	int y;
};
typedef struct vector_s vector_t;

struct sound_helper_s {
	double minimum;
	double maximum;
	enum sound_direction direction;
};
typedef struct sound_helper_s sound_helper_t;