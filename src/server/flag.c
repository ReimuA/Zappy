/*
** EPITECH PROJECT, 2018
** singe
** File description:
** singe
*/

#include "flag.h"

static const argument_helper_t arg_helper[] = {
	{ "-p", offsetof(flag_t, port),		atoi },
	{ "-f", offsetof(flag_t, freq),		atoi },
	{ "-x", offsetof(flag_t, width),	atoi },
	{ "-y", offsetof(flag_t, height),	atoi },
	{ "-c", offsetof(flag_t, max_team_nbr),	atoi },
	{ NULL, 0,				NULL }
};

static const char *statement[] = {
	"port needs to be strictly positive",
	"freq needs to be strictly positive",
	"width needs to be at least 10",
	"height needs to be at least 10",
	"max team nbr needs to be strictly positive",
	"There should be at least 1 team names specified",
	NULL
};

static const flag_t flag_base = {
	.port = DFL_PORT,
	.freq = DFL_FREQ,
	.width = DFL_WIDTH,
	.height = DFL_HEIGHT,
	.max_team_nbr = DFL_TEAM_NUMBER,
	.team_names = NULL
};

static void flag_dump(flag_t *flag)
{
	char *tmp = NULL;
	int *flag_ptr = NULL;


	fprintf(stdout, "\nStart of flag dump.\n");
	for (int i = 0; arg_helper[i].name != NULL; i++) {
		tmp = (char *)flag + arg_helper[i].offset;
		flag_ptr = (int *)tmp;
		fprintf(stdout, "\t%s = %d\n",arg_helper[i].name, *flag_ptr);
	}
	fprintf(stdout, "\tTeams Name = {\n");
	for (int i = 0; flag->team_names && flag->team_names[i] != NULL; i++)
		fprintf(stdout, "\t\t%s%s\n",
			flag->team_names[i],
			flag->team_names[i + 1] == NULL ? "" : ",");
	fprintf(stdout, "\t}\n");
	fprintf(stdout, "End of flag dump.\n\n");
}

static int flag_retrieve_value(flag_t *flag, int j, const char *s)
{
	char *tmp = (char *)flag + arg_helper[j].offset;
	int *flag_ptr = (int *)tmp;

	for (int i = 0; s[i] != '\0'; i++) {
		if (isdigit(s[i]) == 0) {
			fprintf(stdout,
				"Warning: %s at \"%s\" for \"%s\".\n",
				"non numerical argument", s,
				arg_helper[j].name);
			break;
		}
	}
	*flag_ptr = arg_helper[j].callback(s);
	return 0;
}

static int flag_check_value(flag_t *flag)
{
	int result = 0;
	int assertion[] = {
		flag->port <= 0,
		flag->freq <= 0,
		flag->width < 10,
		flag->height < 10,
		flag->max_team_nbr <= 0,
		flag->team_names == NULL
	};

	for (int i = 0; statement[i] != NULL; i++) {
		if (assertion[i] != 0 && ++result)
			fprintf(stderr, "Error: %s.\n", statement[i]);
	}
	return result;
}

static int flag_retrieve_team_names(flag_t *flag, int i, int argc, char **argv)
{
	int size = 0;
	char *tmp = strdup("");

	if (tmp == NULL)
		return -1;
	for (;i < argc; i++) {
		for (int j = 0; arg_helper[j].name != NULL; j++) {
			if (strcmp(arg_helper[j].name, argv[i]) == 0)
				goto end_of_loop;
		}
		size = sizeof(char) * (strlen(tmp) + strlen(argv[i]) + 3);
		tmp = realloc(tmp, size);
		if (tmp == NULL)
			return -1;
		strcat(tmp, argv[i]);
		strcat(tmp, " ");
	}
	end_of_loop: free(flag->team_names);
	flag->team_names = explode(tmp, " ");
	return 0;
}

int flag_init(flag_t *flag, int argc, char **argv)
{
	*flag = flag_base;
	flag->team_names = explode(strdup("team1 team2 team3 team4"), " ");
	for (int i = 0; i < argc; i++) {
		for (int j = 0; arg_helper[j].name != NULL; j++) {
			if (strcmp(arg_helper[j].name, argv[i]) == 0 &&
				i + 1 < argc)
				flag_retrieve_value(flag, j, argv[++i]);
		}
		if (strcmp("-n", argv[i]) == 0)
			flag_retrieve_team_names(flag, ++i, argc, argv);
	}
	flag_dump(flag);
	return flag_check_value(flag);
}
