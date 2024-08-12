# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rolamber <rolamber@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/12 08:27:52 by rolamber          #+#    #+#              #
#    Updated: 2024/08/12 10:36:49 by rolamber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = cc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -L$(LIB_DIR) -lm
AR = ar rcs

NAME = cub3D

SRC_DIR = srcs/
OBJ_DIR = objs/
INC_DIR = headers/
LIB_DIR = libft/

SRC = $(addsuffix .c, $(addprefix srcs/exec/, $(EXEC))) \
	  $(addsuffix .c, $(addprefix srcs/env/, $(ENV))) \
	  $(addsuffix .c, $(addprefix srcs/tools/, $(TOOLS))) \
	  $(addsuffix .c, $(addprefix srcs/, $(OTHER))) \
	  $(addsuffix .c, $(addprefix srcs/lexer_parser/, $(LEXER_PARSER))) \
	  $(addsuffix .c, $(addprefix srcs/lexer_parser_utils/, $(LEXER_PARSER_UTILS)))


OBJ = $(SRC:.c=.o)
DEP = $(OBJ:.o=.d)

all: $(NAME)


$(NAME): $(OBJ)
	@make -C $(LIB_DIR) > /dev/null
	$(CC) $(LDFLAGS) -o $@ $^ -lft -lncurses -lreadline
	@echo $(LINE1)
	@echo $(LINE2)
	@echo $(LINE3)
	@echo $(LINE4)
	@echo $(LINE5)
	@echo $(LINE6)

%.o: %.c
	$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@ -g3

-include $(DEP)

clean:
	@make clean -C $(LIB_DIR) > /dev/null
	@echo "🧹 ${LIB_DIR}"
	rm -rf $(OBJ)
	rm -rf $(DEP)
	@echo "CLEAN"

fclean: clean
	@make fclean -C $(LIB_DIR) > /dev/null
	@echo "🧹 ${LIB_DIR}"
	@rm -f $(NAME)
	@echo "FCLEAN"

re: fclean all

.PHONY: all clean fclean re
