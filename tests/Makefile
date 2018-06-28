#
# EPITECH PROJECT 2018
#
# File description : singe
#
#

SRC 		=	../src/
SERVER		=	$(SRC)server/
SERVER_GAME 	=	$(SERVER)game/
SERVER_MDW 	=	$(SERVER)middleware/
SERVER_CMD 	=	$(SERVER)command/
SERVER_AI_CMD 	=	$(SERVER)command/ai_only/
SERVER_GI_CMD 	=	$(SERVER)command/graph_only/
MISC 		=	$(SRC)misc/
TESTS_MISC	=	src/misc/tests_
TESTS_SERVER	=	src/server/tests_
TESTS_MDW	=	src/server/mdw/tests_
TESTS_GAME	=	src/server/game/tests_
TESTS_AI_CMD	=	src/server/ai_only/tests_
TESTS_GRAPH_CMD	=	src/server/graph_only/tests_

SRCS		=						\
		$(TESTS_GAME)win.c				\
		$(TESTS_GAME)cell.c				\
		$(TESTS_GAME)world.c				\
		$(TESTS_GAME)inventory.c			\
		$(TESTS_GAME)materials_event.c			\
		$(TESTS_MISC)tabdup.c				\
		$(TESTS_MISC)tabcpy.c				\
		$(TESTS_MISC)tablen.c				\
		$(TESTS_MISC)explode.c				\
		$(TESTS_SERVER)event.c				\
		$(TESTS_SERVER)flag.c				\
		$(TESTS_SERVER)food_event.c			\
		$(TESTS_SERVER)event_list.c			\
		$(TESTS_SERVER)server_init.c			\
		$(TESTS_SERVER)clients_utils.c 			\
		$(TESTS_GRAPH_CMD)cmd_handler_bct.c		\
		$(TESTS_GRAPH_CMD)cmd_handler_mct.c		\
		$(TESTS_GRAPH_CMD)cmd_handler_msz.c		\
		$(TESTS_GRAPH_CMD)cmd_handler_pin.c		\
		$(TESTS_GRAPH_CMD)cmd_handler_plv.c		\
		$(TESTS_GRAPH_CMD)cmd_handler_ppo.c		\
		$(TESTS_GRAPH_CMD)cmd_handler_sgt.c		\
		$(TESTS_GRAPH_CMD)cmd_handler_stt.c		\
		$(TESTS_GRAPH_CMD)cmd_handler_tna.c		\
		$(TESTS_MDW)mdw_ai_only.c			\
		$(TESTS_MDW)mdw_graph_only.c			\
		$(TESTS_MDW)mdw_list_param.c			\
		$(TESTS_MDW)mdw_check_target.c			\
		$(TESTS_MDW)mdw_request_limiter.c		\
		$(TESTS_AI_CMD)left_callback.c			\
		$(TESTS_AI_CMD)right_callback.c			\
		$(TESTS_AI_CMD)broadcast_utils.c		\
		$(TESTS_AI_CMD)cmd_handler_set.c		\
		$(TESTS_AI_CMD)cmd_handler_left.c		\
		$(TESTS_AI_CMD)cmd_handler_look.c		\
		$(TESTS_AI_CMD)cmd_handler_take.c		\
		$(TESTS_AI_CMD)cmd_handler_eject.c		\
		$(TESTS_AI_CMD)cmd_handler_right.c		\
		$(TESTS_AI_CMD)cmd_handler_forward.c		\
		$(TESTS_SERVER)cmd_handler_unknown.c		\
		$(TESTS_AI_CMD)cmd_handler_inventory.c		\
		$(TESTS_AI_CMD)cmd_handler_connect_nbr.c	\
		$(TESTS_SERVER)server_handle_cmd.c		\
		$(SERVER)flag.c					\
		$(SERVER)event.c 				\
		$(SERVER)event_list.c				\
		$(SERVER)event_list_.c				\
		$(SERVER)server_team.c				\
		$(SERVER)server_init.c				\
		$(SERVER)clients_utils.c			\
		$(SERVER)server_process.c			\
		$(SERVER)server_fd_utils.c			\
		$(SERVER)server_join_team.c			\
		$(SERVER)server_handle_cmd.c			\
		$(SERVER)server_update_game.c			\
		$(SERVER)server_accept_connection.c		\
		$(MISC)tabdup.c					\
		$(MISC)tabcpy.c					\
		$(MISC)tablen.c					\
		$(MISC)explode.c				\
		$(SERVER_GAME)win.c 				\
		$(SERVER_GAME)cell.c 				\
		$(SERVER_GAME)world.c				\
		$(SERVER_GAME)inventory.c			\
		$(SERVER_GAME)inventory_op.c			\
		$(SERVER_GAME)food_event.c			\
		$(SERVER_GAME)materials_event.c			\
		$(SERVER_MDW)mdw_ai_only.c			\
		$(SERVER_MDW)mdw_graph_only.c			\
		$(SERVER_MDW)mdw_list_param.c			\
		$(SERVER_MDW)mdw_check_target.c			\
		$(SERVER_MDW)mdw_request_limiter.c		\
		$(SERVER_CMD)cmd_handler_unknown.c		\
		$(SERVER_AI_CMD)look_utils.c			\
		$(SERVER_AI_CMD)broadcast_utils.c		\
		$(SERVER_AI_CMD)cmd_handler_set.c		\
		$(SERVER_AI_CMD)cmd_handler_take.c		\
		$(SERVER_AI_CMD)cmd_handler_left.c		\
		$(SERVER_AI_CMD)cmd_handler_look.c		\
		$(SERVER_AI_CMD)cmd_handler_fork.c		\
		$(SERVER_AI_CMD)cmd_handler_eject.c		\
		$(SERVER_AI_CMD)cmd_handler_right.c		\
		$(SERVER_AI_CMD)cmd_handler_forward.c		\
		$(SERVER_AI_CMD)cmd_handler_broadcast.c		\
		$(SERVER_AI_CMD)cmd_handler_elevation.c		\
		$(SERVER_AI_CMD)cmd_handler_inventory.c		\
		$(SERVER_AI_CMD)cmd_handler_connect_nbr.c	\
		$(SERVER_GI_CMD)cmd_handler_bct.c		\
		$(SERVER_GI_CMD)cmd_handler_mct.c		\
		$(SERVER_GI_CMD)cmd_handler_msz.c		\
		$(SERVER_GI_CMD)cmd_handler_pin.c		\
		$(SERVER_GI_CMD)cmd_handler_plv.c		\
		$(SERVER_GI_CMD)cmd_handler_ppo.c		\
		$(SERVER_GI_CMD)cmd_handler_sgt.c		\
		$(SERVER_GI_CMD)cmd_handler_sst.c		\
		$(SERVER_GI_CMD)cmd_handler_tna.c		\

CFLAGS	+=	-g
CFLAGS	+=	-I../include/server
CFLAGS	+=	-I../include/misc
CFLAGS	+=	-Wall -Wextra
CFLAGS	+=	-fprofile-arcs
CFLAGS	+=	-ftest-coverage

LDFLAGS +=	--coverage -lcriterion -lm

OBJ	=	$(SRCS:.c=.o)
GCDA	=	$(SRCS:.c=.gcda)
GCNO	=	$(SRCS:.c=.gcno)

NAME	=	test

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

gcov: tests_run
	gcov $(SRCS)

CGCOV		=	./*.c.gcov
LCOV_DIR	=	../
RAPPORT_DIR	=	../rapport
RAPPORT_NAME	=	../rapport.info
RAPPORT_IDX	=	../rapport/index.html
NAVIGATOR	=	google-chrome

lcov: gcov
	lcov --directory $(LCOV_DIR) -c -o $(RAPPORT_NAME)
	genhtml -o $(RAPPORT_DIR) -t "Zappy TU coverage" $(RAPPORT_NAME)
	$(NAVIGATOR) $(RAPPORT_IDX)

RM	=	@rm -rf

clean:
	$(RM) $(OBJ)
	$(RM) $(GCDA)
	$(RM) $(GCNO)
	$(RM) $(CGCOV)
	$(RM) $(RAPPORT_DIR)
	$(RM) $(RAPPORT_NAME)

fclean: clean
	$(RM) $(NAME)

tests_run: re
	./$(NAME)

re: fclean all

.PHONY: all clean fclean re tests_run gcov
