# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rolamber <rolamber@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/12 08:27:52 by rolamber          #+#    #+#              #
#    Updated: 2024/09/26 08:43:18 by rolamber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -Lmlx_linux -lmlx -L/usr/lib -lXext -lX11 -lm
CC = cc
CFLAGS = -Wall -Wextra -Werror 
LDFLAGS = -Llibft -lft -L. -lgnl -lm -lbsd -Llibmlx -lmlx -lXext -lX11 -g3
AR = ar rcs

NAME = cub3D

SRC_DIR = srcs/
OBJ_DIR = objs/
INC_DIR = headers/
GNL_DIR = gnl/
LIB_DIR = libft/

SRC = $(addsuffix .c, $(addprefix srcs/, $(PARSING) $(RAYCAST) $(DISPLAY)))
PARSING = parsing_routine parsing_routine_bis parsing_tools texture_informations main init_vectors
RAYCAST = ray_cast_utils ray_cast texture_loading
DISPLAY = display_game render movement display_utils utils
OBJ = $(SRC:.c=.o)
DEP = $(OBJ:.o=.d)

GNL = $(addsuffix .c, $(addprefix gnl/, $(GNL_SRCS)))
GNL_SRCS = get_next_line get_next_line_utils
GNL_OBJS = $(GNL:.c=.o)

all: $(NAME)


$(NAME): $(OBJ) $(GNL_OBJS)
	@make -C $(LIB_DIR) > /dev/null
	$(AR) libgnl.a $(GNL_OBJS) 
	$(CC) $(OBJ) $(LDFLAGS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -I $(INC_DIR) -Ilibmlx -c $< -o $@ -g3

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
	@rm -f libgnl.a
	@echo "FCLEAN"

re: fclean all

.PHONY: all clean fclean re
