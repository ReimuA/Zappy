/*
** EPITECH PROJECT, 2018
** singe
** File description:
** singe
*/

#include <stdio.h>
#include <assert.h>
#include <unistd.h>
#include <criterion/criterion.h>
#include "flag.h"

Test(flag, dfl)
{
	flag_t flag;
	int argc = 0;
	char **argv = NULL;

	close(STDOUT_FILENO);
	close(STDERR_FILENO);
	flag_init(&flag, argc, argv);
	assert(flag.port == DFL_PORT);
	assert(flag.freq == DFL_FREQ);
	assert(flag.width == DFL_WIDTH);
	assert(flag.height == DFL_HEIGHT);
	assert(flag.max_team_nbr == DFL_TEAM_NUMBER);
	assert(strcmp(flag.team_names[0], "team1") == 0);
	assert(strcmp(flag.team_names[1], "team2") == 0);
	assert(strcmp(flag.team_names[2], "team3") == 0);
	assert(strcmp(flag.team_names[3], "team4") == 0);	
}

static char *customized_parameter[] = {
	"-p", "2298",
	"-f", "12",
	"-x", "45",
	"-y", "128",
	"-n", "team1", "team2",
	"-c", "-2", NULL
};

Test(flag, customized_parameter)
{
	flag_t flag;
	int argc = tablen(customized_parameter);

	close(STDOUT_FILENO);
	close(STDERR_FILENO);
	flag_init(&flag, argc, customized_parameter);
	assert(flag.port == 2298);
	assert(flag.freq == 12);
	assert(flag.width == 45);
	assert(flag.height == 128);
	assert(flag.max_team_nbr == -2);
	assert(strcmp(flag.team_names[0], "team1") == 0);
	assert(strcmp(flag.team_names[1], "team2") == 0);
}