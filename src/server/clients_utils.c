/*
** EPITECH PROJECT, 2018
** singe
** File description:
** singe
*/

#include "server.h"

static const char *graphic_name = "GRAPHIC";

void client_reset_slot(client_t *client)
{
	close(client->fd);
	free(client->buffer);
	client_init(client);
}

static int client_check_buffer(client_t *client)
{
	int i = 0;
	int ln = 0;

	while (client->buffer != NULL && client->buffer[i] != '\0') {
		if (client->buffer[i] == '\n')
			ln++;
		if (ln >= 10 || i >= 5120)
			return -1;
		i++;
	}
	return 0;
}

int client_read_chunk(client_t *client)
{
	int size = 0;
	char buff[513] = { 0 };

	if (read(client->fd, buff, 512) <= 0)
		return -1;
	if (client->buffer == NULL) {
		client->buffer = strdup(buff);
		return client->buffer == NULL;
	}
	size = sizeof(char) * (2 + strlen(buff) + strlen(client->buffer));
	client->buffer = realloc(client->buffer, size);
	if (client->buffer == NULL)
		return 1;
	strcat(client->buffer, buff);
	return client_check_buffer(client);
}

int client_set_graphical(client_t *client, const char *s)
{
	if (s == NULL)
		return 0;
	if (strcmp(s, "GRAPHIC") == 0) {
		client->team_name = graphic_name;
		client->graphical = true;
	}
	else
		client->graphical = false;
	return 0;
}

int client_init(client_t *client)
{
	*client = (client_t) {
		.fd = -1,
		.pos_y = 0,
		.pos_x = 0,
		.level = 1,
		.egg_id = 0,
		.open = true,
		.buffer = NULL,
		.hatched = false,
		.team_name = NULL,
		.graphical = false,
		.direction = NORTH,
		.inventory = inventory_create(),
	};
	return 0;
}
