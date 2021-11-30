# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tedison <tedison@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/31 09:06:11 by tedison           #+#    #+#              #
#    Updated: 2021/06/28 13:11:25 by tedison          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= stack_init.c ft_lstnew.c ft_lstadd_back.c ft_lstlast.c ft_atoi.c\
			  operations.c operations_rr.c ft_bzero.c push_swap.c operations_a.c\
			  utils.c ft_split.c ft_substr.c operations_a_2.c operations_a_3.c\
			  sort_med_large.c opti.c utils_med_large.c utils_med_large_2.c\
			  utils_2.c sort_small.c
OBJS		= $(SRCS:.c=.o)
INC			= push_swap.h
CC			= gcc
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror -I. 
NAME		= push_swap

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS) $(BONUS_OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)


.PHONY:			all clean fclean re bonus
