# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lnelson <lnelson@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/02 14:32:03 by lnelson           #+#    #+#              #
#    Updated: 2021/11/02 14:32:07 by lnelson          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long

OS			:= $(shell uname)

ifeq (${OS}, Darwin)
	MLX		:= minilibx_opengl_20191021
else
	MLX		:= minilibx-linux
endif

SRCS_DIR	= srcs/

OBJS_DIR	= obj/

INCLS_DIR	= includes/

LIBS_DIR	= libs/

CFLAGS		= -Wall -Wextra -Werror -I ${INCLS_DIR}

FLAGS		= -L ${LIBS_DIR}libft -lft

ifeq (${OS}, Darwin)
MLX_FLAGS	= -L ${LIBS_DIR}${MLX} -lmlx -framework OpenGL -framework AppKit 
else
MLX_FLAGS	= -L ${LIBS_DIR}${MLX} -lmlx -lX11 -lm -lXext -lbsd
endif

CC			= gcc

SRCS		= so_long.c\
			  parce_map.c\
			  put_textures.c\
			  init_game.c\
			  hooks.c\
			  hooks_utils.c\
			  exit_game.c\

OBJS		= ${SRCS:.c=.o}

OBJS		:= ${addprefix ${OBJS_DIR}, ${OBJS}}

${OBJS_DIR}%.o: ${SRCS_DIR}%.c
			${CC} ${CFLAGS} -c $< -o $@

all:		${NAME}

${NAME}:	${OBJS}
			make -C ${LIBS_DIR}libft
			make -C ${LIBS_DIR}${MLX}
			${CC} -o $@ ${OBJS} ${FLAGS} ${MLX_FLAGS}

sanitize:	${OBJS}
			make -C ${LIBS_DIR}libft
			make -C ${LIBS_DIR}${MLX}
			${CC} -o $@ ${OBJS} ${FLAGS} ${MLX_FLAGS} -g3 -fsanitize=address	

clean:
			make clean -C ${LIBS_DIR}libft
			make clean -C ${LIBS_DIR}${MLX}
			${RM} ${OBJS}
			
fclean:		clean
			make fclean -C ${LIBS_DIR}libft
			${RM} ${NAME} sanitize

re:			fclean all

RM			= rm -f
