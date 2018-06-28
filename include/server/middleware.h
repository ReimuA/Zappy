/*
** EPITECH PROJECT, 2018
** singe
** File description:
** singe
*/

#pragma once

/*
** TODO: Find more coherent name for mdw define.
*/

#define NO_MDW { 0 }
#define LIST_AI { mdw_list_param, mdw_ai_only }
#define LIST_GRAPH { mdw_list_param, mdw_graph_only }
#define LIST_GRAPH_TARGET { mdw_list_param, mdw_graph_only, mdw_check_target }

bool mdw_ai_only(server_t *server, int client, int argc, char **argv);
bool mdw_list_param(server_t *server, int client, int argc, char **argv);
bool mdw_graph_only(server_t *server, int client, int argc, char **argv);
bool mdw_check_target(server_t *server, int client, int argc, char **argv);
bool mdw_request_limiter(server_t *server, int client, int argc, char **argv);