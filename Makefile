# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edalexan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/23 13:14:31 by edalexan          #+#    #+#              #
#    Updated: 2024/10/29 14:47:29 by edalexan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = cc
CFLAGS = -g -Wall -Wextra -Werror
READLINE = -lreadline
SRCS= minishell.c \
	utils.c \
	cd.c \
	echo.c \
	process_command.c \
	pipes.c \
	
OBJS= $(SRCS:.c=.o)

LIBDIR = libft
LIBFT = $(LIBDIR)/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(READLINE) 

$(LIBFT):
	make -C $(LIBDIR)
	
#$(OBJS):
#	$(CC) $(CFLAGS) -c $(SRCS) $(READLINE)

clean:
	rm -f $(OBJS)
	make clean -C $(LIBDIR)

fclean:	clean
	rm -f $(NAME)
	make fclean -C $(LIBDIR)

re:	fclean all
