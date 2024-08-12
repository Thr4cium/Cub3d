# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rolamber <rolamber@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/12 08:27:52 by rolamber          #+#    #+#              #
#    Updated: 2024/08/12 13:01:55 by rolamber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = cc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -Lmlx_linux -lmlx -L/usr/lib -lXext -lX11 -lm -Llibft -lft -L. -lgnl
AR = ar rcs

NAME = cub3D

SRC_DIR = srcs/
OBJ_DIR = objs/
INC_DIR = headers/
GNL_DIR = gnl/

SRC = $(addsuffix .c, $(addprefix srcs/, $(a completer)))

OBJ = $(SRC:.c=.o)
DEP = $(OBJ:.o=.d)

GNL = get_next_line.c get_next_line_utils.c
GNL_OBJS = $(GNL:.c=.o)

all: $(NAME)


$(NAME): $(OBJ)
	@make -C $(LIB_DIR) > /dev/null
	$(AR) libgnl.a $(GNL_OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@ -g3

-include $(DEP)

clean:
	@make clean -C $(LIB_DIR) > /dev/null
	@echo "🧹 ${LIB_DIR}"
	rm -rf $(OBJ)
	rm -rf $(DEP)
	rm -rf $(GNL_OBJS)
	@echo "CLEAN"

fclean: clean
	@make fclean -C $(LIB_DIR) > /dev/null
	@echo "🧹 ${LIB_DIR}"
	@rm -f $(NAME)
	@echo "FCLEAN"

re: fclean all

.PHONY: all clean fclean re
