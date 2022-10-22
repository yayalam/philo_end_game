# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ylambark <ylambark@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/29 16:28:18 by ylambark          #+#    #+#              #
#    Updated: 2022/10/18 09:23:30 by ylambark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc 
CFLAGS = -Wall -Wextra -Werror
M_SRCS = philo-mandatory/main.c philo-mandatory/utils.c philo-mandatory/initils.c philo-mandatory/error_hand.c

M_OBJS = $(M_SRCS:.c=.o)

all : $(NAME) philo-mandatory/philosopher.h
$(NAME) : $(M_OBJS) 
	$(CC) $(CFLAGS) $(M_OBJS) -o $@
%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -rf $(M_OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all