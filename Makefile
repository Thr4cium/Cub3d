# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: magrondi <magrondi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/12 08:27:52 by rolamber          #+#    #+#              #
#    Updated: 2024/12/09 19:53:42 by magrondi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME                =   cub3D

LIBFT_AR_PATH       =   ./libft/libft.a
LIBFT               =   libft

OBJS_DIR            =   .objs

MINILIB             =   libmlx

MLX_AR_PATH         =   ./${MINILIB}/libmlx.a

HEADERS             =   ./headers/cub3d.h

CC                  =   cc

PARSING_SRCS        =   ./srcs/parsing/assign_spawn_direction.c \
                        ./srcs/parsing/init_vectors.c \
                        ./srcs/parsing/parsing_edge_case.c \
                        ./srcs/parsing/parsing_routine.c \
                        ./srcs/parsing/parsing_routine_bis.c \
                        ./srcs/parsing/texture_informations.c \
                        ./srcs/parsing/parsing_tools.c \
                        ./srcs/parsing/texture_loading.c \

RAYCASTING_SRCS     =   ./srcs/raycasting/ray_cast.c \
                        ./srcs/raycasting/ray_cast_utils.c \

GAME_SRCS           =   ./srcs/game/display_game.c \
                        ./srcs/game/display_utils.c \
                        ./srcs/game/move_rotate.c \
                        ./srcs/game/render.c \
                        ./srcs/game/movement.c \

SRCS                =   ./srcs/main.c \
                        ./srcs/utils.c \
                        ${GAME_SRCS} \
                        ${RAYCASTING_SRCS} \
                        ${PARSING_SRCS} \

OBJS                =   ${SRCS:%.c=$(OBJS_DIR)/%.o}

CFLAGS              =   -Wall -Wextra -Werror

CBONUS              =   -Wall -Wextra -Werror -D BONUS=1

$(OBJS_DIR)/%.o: %.c ${HEADERS} Makefile
			@mkdir -p $(dir $@)
			${CC} ${CFLAGS} -I ./ -c $< -o $@

all: libft mlx ${NAME}

${NAME}: ${OBJS} ${LIBFT_AR_PATH} ${MLX_AR_PATH}
			${CC} ${CFLAGS} ${OBJS} ${LIBFT_AR_PATH} ${MLX_AR_PATH} -lm -lbsd -lXext -lX11 -o ${NAME}

bonus: fclean libft mlx
			${MAKE} CFLAGS="${CBONUS}" all

libft: force
			${MAKE} -C ${LIBFT}

mlx: force
			${MAKE} -C ${MINILIB}

clean:
			${MAKE} -C ${LIBFT} clean
			${MAKE} -C ${MINILIB} clean
			rm -rf ${OBJS_DIR}

fclean: clean
			${MAKE} -C ${LIBFT} fclean
			rm -f ${NAME}

re: fclean all

force:

.PHONY: all clean fclean re libft bonus force mlx
