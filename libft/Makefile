# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsusanna <gsusanna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/16 01:01:58 by gsusanna          #+#    #+#              #
#    Updated: 2021/05/07 13:13:31 by gsusanna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

INC		=	libft.h

SRC		=	ft_atoi.c \
			ft_bzero.c \
			ft_calloc.c \
			ft_err.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_is_not_printable.c \
			ft_itoa.c \
			ft_memccpy.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memset.c \
			ft_putchar.c \
			ft_putchar_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_putstr_fd.c \
			ft_snumbers.c \
			ft_split.c \
			ft_sspaces.c \
			ft_strdup.c \
			ft_strjoin.c \
			ft_strjoin_free.c \
			ft_strchr.c \
			ft_strcpy.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strmapi.c \
			ft_strncmp.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strtrim.c \
			ft_substr.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_strfnl.c \
			ft_strfnl_null.c \
			ft_wipe_ptr.c \
			ft_wipe_pptr.c \
			get_next_line.c \
			ft_lstd_list_free.c \
			ft_lstadd_back.c \
			ft_lstadd_front.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstlast.c \
			ft_lstmap.c \
			ft_lstnew.c \
			ft_lstsize.c \
			ft_lstdnew.c \
			ft_lstdadd_front.c \
			ft_lstdadd_back.c

OBJ	= ${SRC:.c=.o}
 
CC 		= gcc

CFLAGS	= -Wall -Wextra -Werror

AR		= ar rcs

RM		= rm -f

all:		${NAME}

$(NAME):	${OBJ} ${INC}
	@${AR} ${NAME} ${OBJ}

%.o: %.c
	@${CC} ${CFLAGS} -I ${INC} -c $< -o $@
	@echo "compiling" $<

clean:	
	@${RM} ${OBJ}
	@echo "libft clean"

fclean:
	@${RM} ${OBJ}
	@${RM} ${NAME}
	@echo "libft fclean"

re: fclean all

.PHONY:	all clean fclean re
