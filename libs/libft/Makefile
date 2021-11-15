# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lnelson <lnelson@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/02 14:32:12 by lnelson           #+#    #+#              #
#    Updated: 2021/11/02 14:33:12 by lnelson          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a

CC			= gcc

FLAGS		= -Wall -Wextra -Werror -I ./includes

OS			:= $(shell uname)

ifeq ($(UNAME),Darwin)
			$(shell sed -i 's/typedef __uintmax_t uintmax_t;//;24,25d' includes/printf.h)
endif

#	Core functions including string/memory manipulations, and atoi atof itoa...
CORE		=\
			ft_atof.c\
			ft_isalnum.c\
			ft_isprint.c\
			ft_memcmp.c\
			ft_putchar_fd.c\
			ft_putnstr_fd.c\
			ft_strdup.c\
			ft_strlen.c\
			ft_strrchr.c\
			ft_toupper.c\
			ft_atoi.c\
			ft_isalpha.c\
			ft_itoa.c\
			ft_memcpy.c\
			ft_putendl_fd.c\
			ft_putstr_fd.c\
			ft_strjoin.c\
			ft_strmapi.c\
			ft_strtrim.c\
			ft_str_is_charset.c\
			ft_bzero.c\
			ft_isascii.c\
			ft_memccpy.c\
			ft_memmove.c\
			ft_putnbr_fd.c\
			ft_split.c\
			ft_strlcat.c\
			ft_strncmp.c\
			ft_substr.c\
			ft_calloc.c\
			ft_isdigit.c\
			ft_memchr.c\
			ft_memset.c\
			ft_putnchar_fd.c\
			ft_strchr.c\
			ft_strlcpy.c\
			ft_strnstr.c\
			ft_tolower.c

#			List manipulating functions
LST			=\
			ft_lstadd_back.c\
			ft_lstadd_front.c\
			ft_lstclear.c\
			ft_lstiter.c\
			ft_lstlast.c\
			ft_lstmap.c\
			ft_lstnew.c\
			ft_lstsize.c

#			ft_get_next_line(int fd, char **buffer)
GNL			=\
			get_next_line.c\
			get_next_line_utils.c

#			ft_printf(char *sting, ...) - REMOVED TILL RE-WRITING - working on both Linux-Mac on Napoleon-42/ft_printf.git
#PRINTF		=\
			ft_printf.c\
			ft_printf_utils.c\
			print_c_s.c\
			print_e.c\
			print_f.c\
			print_g.c\
			print_hexa.c\
			print_i_d.c\
			print_p.c\
			print_u.c



SRCS		= $(addprefix libft/core/, $(CORE)) $(addprefix libft/gnl/, $(GNL)) $(addprefix libft/ft_printf/, $(PRINTF)) $(addprefix libft/lst/, $(LST))

OBJS		= ${SRCS:.c=.o}

.c.o:
			${CC} ${FLAGS} -c $< -o ${<:.c=.o} 
			
all:		${NAME}


${NAME}:	${OBJS}
				ar rc ${NAME} ${OBJS}
				ranlib ${NAME}

clean:		
				${RM} ${OBJS}
				
fclean:		 clean
				${RM} ${NAME}
				
re:			fclean all

RM		= rm -fr



