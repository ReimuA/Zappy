/*
** EPITECH PROJECT, 2018
** singe
** File description:
** singe
*/

#pragma once

/*
** Command only usable by AI.
*/

int cmd_handler_set(server_t *server, int client, int argc, char **argv);
int cmd_handler_left(server_t *server, int client, int argc, char **argv);
int cmd_handler_look(server_t *server, int client, int argc, char **argv);
int cmd_handler_fork(server_t *server, int client, int argc, char **argv);
int cmd_handler_take(server_t *server, int client, int argc, char **argv);
int cmd_handler_eject(server_t *server, int client, int argc, char **argv);
int cmd_handler_right(server_t *server, int client, int argc, char **argv);
int cmd_handler_forward(server_t *server, int client, int argc, char **argv);
int cmd_handler_unknown(server_t *server, int client, int argc, char **argv);
int cmd_handler_connect_nbr(server_t *server, int cli, int argc, char **argv);
int cmd_handler_elevation(server_t *server, int client, int argc, char **argv);
int cmd_handler_inventory(server_t *server, int client, int argc, char **argv);
int cmd_handler_broadcast(server_t *server, int client, int argc, char **argv);


/*
** Callback from previous set of command (prototype for TU).
*/

int cmd_set_callback(server_t *server, int client, int argc, char **arg);
int cmd_left_callback(server_t *server, int client, int argc, char **arg);
int cmd_look_callback(server_t *server, int client, int argc, char **arg);
int cmd_take_callback(server_t *server, int client, int argc, char **arg);
int cmd_eject_callback(server_t *server, int client, int argc, char **arg);
int cmd_right_callback(server_t *server, int client, int argc, char **arg);
int cmd_forward_callback(server_t *server, int client, int argc, char **arg);
int cmd_inventory_callback(server_t *server, int client, int argc, char **arg);
int cmd_broadcast_callback(server_t *server, int client, int argc, char **arg);

/*
** Command only usable by graphical client.
*/

int cmd_handler_bct(server_t *server, int cli, int argc, char **argv);
int cmd_handler_mct(server_t *server, int cli, int argc, char **argv);
int cmd_handler_msz(server_t *server, int cli, int argc, char **argv);
int cmd_handler_pin(server_t *server, int cli, int argc, char **argv);
int cmd_handler_plv(server_t *server, int cli, int argc, char **argv);
int cmd_handler_ppo(server_t *server, int cli, int argc, char **argv);
int cmd_handler_sgt(server_t *server, int cli, int argc, char **argv);
int cmd_handler_sst(server_t *server, int cli, int argc, char **argv);
int cmd_handler_tna(server_t *server, int cli, int argc, char **argv);