##
## EPITECH PROJECT, 2018
## Zapp
## File description:
## Makefile
##

ECHO	=	/bin/echo -e
DEFAULT	=	"\033[00m"
GREEN	=	"\033[0;32m"
TEAL	=	"\033[1;36m"
RED	=	"\033[0;31m"

SERVER	=	zappy_server
CLIENT	=	client
GRAPH 	= 	zappy_graph
AI	=	zappy_ai

MISC_SRC	=	src/misc/
SERVER_SRC	=	src/server/
SERVER_GAME	=	src/server/game/
SERVER_COMMAND	=	src/server/command/
AI_COMMAND	=	src/server/command/ai_only/
GRAPH_COMMAND	=	src/server/command/graph_only/
SERVER_MIDWARE	=	src/server/middleware/
CLIENT_SRC	=	src/client/
SRC_AI		=	src/IA/

CC	=	gcc
CPP	=	g++

CFLAGS	+=	-Wall
CFLAGS	+=	-Wextra
CFLAGS	+=	-Iinclude/misc
CFLAGS	+=	-Iinclude/server
CPPFLAGS	+=	-Iinclude/IA

LDFLAGS = 	-lm

RM 	=	@rm -f

SERVER_SRCS 	=							\
			$(SERVER_SRC)main.c				\
			$(SERVER_SRC)flag.c				\
			$(SERVER_GAME)win.c				\
			$(SERVER_GAME)cell.c				\
			$(SERVER_GAME)world.c				\
			$(SERVER_GAME)inventory.c			\
			$(SERVER_GAME)inventory_op.c			\
			$(SERVER_GAME)food_event.c			\
			$(SERVER_GAME)materials_event.c			\
			$(SERVER_SRC)event.c				\
			$(SERVER_SRC)event_list.c			\
			$(SERVER_SRC)event_list_.c			\
			$(SERVER_SRC)server_team.c			\
			$(SERVER_SRC)server_init.c			\
			$(SERVER_SRC)clients_utils.c			\
			$(SERVER_SRC)server_process.c			\
			$(SERVER_SRC)server_fd_utils.c			\
			$(SERVER_SRC)server_join_team.c			\
			$(SERVER_SRC)server_handle_cmd.c		\
			$(SERVER_SRC)server_update_game.c		\
			$(SERVER_SRC)server_accept_connection.c		\
			$(SERVER_MIDWARE)mdw_ai_only.c			\
			$(SERVER_MIDWARE)mdw_list_param.c		\
			$(SERVER_MIDWARE)mdw_graph_only.c		\
			$(SERVER_MIDWARE)mdw_check_target.c		\
			$(SERVER_MIDWARE)mdw_request_limiter.c		\
			$(AI_COMMAND)look_utils.c			\
			$(AI_COMMAND)broadcast_utils.c			\
			$(AI_COMMAND)cmd_handler_set.c			\
			$(AI_COMMAND)cmd_handler_left.c			\
			$(AI_COMMAND)cmd_handler_look.c			\
			$(AI_COMMAND)cmd_handler_fork.c			\
			$(AI_COMMAND)cmd_handler_take.c			\
			$(AI_COMMAND)cmd_handler_right.c		\
			$(AI_COMMAND)cmd_handler_eject.c		\
			$(AI_COMMAND)cmd_handler_forward.c		\
			$(AI_COMMAND)cmd_handler_broadcast.c		\
			$(AI_COMMAND)cmd_handler_elevation.c		\
			$(AI_COMMAND)cmd_handler_inventory.c		\
			$(AI_COMMAND)cmd_handler_connect_nbr.c		\
			$(GRAPH_COMMAND)cmd_handler_bct.c		\
			$(GRAPH_COMMAND)cmd_handler_mct.c		\
			$(GRAPH_COMMAND)cmd_handler_msz.c		\
			$(GRAPH_COMMAND)cmd_handler_pin.c		\
			$(GRAPH_COMMAND)cmd_handler_plv.c		\
			$(GRAPH_COMMAND)cmd_handler_ppo.c		\
			$(GRAPH_COMMAND)cmd_handler_sgt.c		\
			$(GRAPH_COMMAND)cmd_handler_sst.c		\
			$(GRAPH_COMMAND)cmd_handler_tna.c		\
			$(SERVER_COMMAND)cmd_handler_unknown.c		\
			$(MISC_SRC)tablen.c				\
			$(MISC_SRC)tabcpy.c				\
			$(MISC_SRC)explode.c				\

SERVER_OBJS	=	$(SERVER_SRCS:.c=.o)

all:		$(SERVER)

$(SERVER):	$(SERVER_OBJS)
		@$(CC) -o $(SERVER) $(SERVER_OBJS) $(LDFLAGS)

TAR_CMD		= tar -xvf
TAR_NAME	= tests.tar

test:
	cd ./tests && $(MAKE)

tests_run:
	cd ./tests && $(MAKE) $@

gcov:
	cd ./tests && $(MAKE) $@

lcov:
	cd ./tests && $(MAKE) $@

clean:
		cd ./tests && $(MAKE) $@
		$(RM) $(SERVER_OBJS)
		$(RM) $(CLIENT_OBJS)

fclean:		clean
		cd ./tests && $(MAKE) $@
		$(RM) $(SERVER)
		$(RM) $(CLIENT)
		$(RM) $(AI)

re:		fclean all

.PHONY: all clean fclean re debug debug_flag tests_run gcov test

.c.o:
		@gcc $(CFLAGS) -c $< -o $@ && \
		$(ECHO) $(GREEN) "[ OK ]" $(TEAL) $< $(DEFAULT) || \
		$(ECHO) $(RED) "[ KO ]" $(TEAL) $< $(DEFAULT)
