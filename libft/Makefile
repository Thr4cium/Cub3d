# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: magrondi <magrondi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/06 16:04:47 by mguy              #+#    #+#              #
#    Updated: 2024/12/19 18:00:14 by magrondi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a

HEADERS 	= libft.h ./gnl/get_next_line.h ./printf/ft_printf.h 

OBJS_DIR	= .objs

SRCS = 	./src/ft_itoa.c \
		./src/ft_putchar_fd.c \
		./src/ft_putendl_fd.c \
		./src/ft_putnbr_fd.c \
		./src/ft_putstr_fd.c \
		./src/ft_strlen.c \
		./src/free_tab.c \
		./src/ft_strtrim.c \
		./src/ft_tolower.c \
		./src/ft_toupper.c \
		./src/ft_isprint.c \
		./src/ft_isascii.c \
		./src/ft_isalnum.c \
		./src/ft_isdigit.c \
		./src/ft_isalpha.c \
		./src/ft_atoi.c \
		./src/ft_strncmp.c \
		./src/ft_strnstr.c \
		./src/ft_strchr.c \
		./src/ft_strdup.c \
		./src/ft_strrchr.c \
		./src/ft_strcpy.c \
		./src/ft_memset.c \
		./src/ft_bzero.c \
		./src/ft_memcpy.c \
		./src/ft_memmove.c \
		./src/ft_memchr.c \
		./src/ft_memcmp.c \
		./src/ft_striteri.c \
		./src/ft_strsearch.c \
		./src/ft_strmapi.c \
		./src/ft_strlcat.c \
		./src/ft_substr.c \
		./src/ft_split.c \
		./src/ft_strjoin.c \
		./src/ft_calloc.c \
		./src/ft_strlcpy.c \
		./src/ft_lstnew.c \
		./src/ft_lstadd_front.c \
		./src/ft_lstsize.c \
		./src/ft_lstlast.c \
		./src/ft_lstadd_back.c \
		./src/ft_lstdelone.c \
		./src/ft_free.c \
		./src/ft_lstclear.c \
		./src/ft_lstiter.c \
		./src/ft_lstmap.c \
		./src/ft_strcmp.c \
		./src/ft_isspace.c \
		./gnl/get_next_line.c \
		./gnl/get_next_line_utils.c \
		./printf/ft_printf.c \
		./printf/ft_hexa.c \
		./printf/ft_pointer.c \
		./printf/ft_putchar.c \
		./printf/ft_putstr.c \
		./printf/ft_utoa.c \


OBJS		= ${SRCS:%.c=$(OBJS_DIR)/%.o}

CFLAGS		= -Wall -Wextra -Werror 

all:		${NAME}

${NAME}:	${OBJS}
			ar -rsc ${NAME} ${OBJS}

$(OBJS_DIR)/%.o: %.c 	${HEADERS} Makefile
			@mkdir -p $(dir $@)
			${CC} ${CFLAGS} -I ./ -c $< -o $@

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re