/*
** EPITECH PROJECT, 2018
** singe
** File description:
** singe
*/

#include "sound.h"
#include "server.h"

static const sound_helper_t	sound_helper[] = {
	{
		.minimum = 0 - M_PI_8,
		.maximum = 0 + M_PI_8,
		.direction = SOUND_EAST
	},
	{
		.minimum = M_PI_4 - M_PI_8,
		.maximum = M_PI_4 + M_PI_8,
		.direction = SOUND_NORTH_EAST
	},
	{
		.minimum = M_PI_2 - M_PI_8,
		.maximum = M_PI_2 + M_PI_8,
		.direction = SOUND_NORTH
	},
	{
		.minimum = M_PI_4 * 3 - M_PI_8,
		.maximum = M_PI_4 * 3 + M_PI_8,
		.direction = SOUND_NORTH_WEST
	},
	{
		.minimum = -M_PI_4 * 3 - M_PI_8,
		.maximum = -M_PI_4 * 3 + M_PI_8,
		.direction = SOUND_SOUTH_WEST
	},
	{
		.minimum = -M_PI_2 - M_PI_8,
		.maximum = -M_PI_2 + M_PI_8,
		.direction = SOUND_SOUTH
	},
	{
		.minimum = -M_PI_4 - M_PI_8,
		.maximum = -M_PI_4 + M_PI_8,
		.direction = SOUND_SOUTH_EAST
	}
};


static void shortest_vector(vector_t *v1, int x, int y)
{
	if (sqrt(v1->x * v1->x + v1->y * v1->y) > sqrt(x * x + y * y)) {
		v1->x = x;
		v1->y = y;
	}
}

static void vector_op(vector_t *v, int size_x, int size_y)
{
	vector_t origin = *v;

	shortest_vector(v, origin.x + size_x, origin.y + size_y);
	shortest_vector(v, origin.x + size_x, origin.y - size_y);
	shortest_vector(v, origin.x + size_x, origin.y);
	shortest_vector(v, origin.x - size_x, origin.y + size_y);
	shortest_vector(v, origin.x - size_x, origin.y - size_y);
	shortest_vector(v, origin.x - size_x, origin.y);
	shortest_vector(v, origin.x, origin.y + size_y);
	shortest_vector(v, origin.x, origin.y - size_y);
}

static int relative_sound(int s, enum direction dir)
{
	int sound_size = SOUND_NORTH_EAST;

	if (dir == SOUTH)
		return (s);
	if (dir == EAST)
		return (s + 2 > sound_size ? (s + 2) % sound_size : s + 2);
	if (dir == NORTH)
		return (s + 4 > sound_size ? (s + 4) % sound_size : s + 4);
	if (dir == WEST)
		return (s + 6 > sound_size ? (s + 6) % sound_size : s + 6);
	return SOUND_NONE;
}

int broadcast_direction(server_t *server,
	client_t *emi,
	client_t *tar)
{
	double angle;
	vector_t v = { emi->pos_x - tar->pos_x, emi->pos_y - tar->pos_y };

	vector_op(&v, server->world.size_x, server->world.size_y);
	if (v.x == 0 && v.y == 0)
		return SOUND_NONE;
	if (v.x == 0)
		return (relative_sound(v.y < 0 ? SOUND_SOUTH : SOUND_NORTH,
			tar->direction));
	if (v.y == 0)
		return (relative_sound(v.x < 0 ? SOUND_WEST : SOUND_EAST,
			tar->direction));
	angle = atan2(v.y, v.x);
	for (int i = 0; i < 7; i++) {
		if (angle >= sound_helper[i].minimum &&
			angle <= sound_helper[i].maximum)
			return (relative_sound(sound_helper[i].direction,
				tar->direction));
	}
	return (relative_sound(SOUND_WEST, tar->direction));
}
