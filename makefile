# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: estegana <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/26 15:09:47 by estegana          #+#    #+#              #
#    Updated: 2024/02/26 15:09:49 by estegana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##nom de l'executable
NAME = fractol

##compilation
CC = gcc
CFLAGS = -Wall -Werror -Wextra
DFLAG = -g3
LIBXFLAG = -Lminilibx-linux

##fichiers sources
SRCS = main.c \
	algo.c \
	remote.c \
	utils.c \

OBJS = $(SRCS:.c=.o)

##include
INCLUDELIBFT = libft/libft.a
INCLUDEMINILIBX = minilibx-linux/libmlx_Linux.a -lmlx -lXext -lX11

##les fichiers obj prennent le nom des fichiers sources "*.c"
%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

${NAME}: ${OBJS}
	make -C libft
	make -C minilibx-linux
	$(CC) $(CFLAGS) $(DFLAG) $(LIBXFLAG) $(OBJS) -o $(NAME) $(INCLUDELIBFT) $(INCLUDEMINILIBX)

all : $(NAME)

clean :
	rm -rf $(OBJS)
	make -C libft clean
	make -C minilibx-linux clean

fclean : clean
	rm -rf $(NAME)
	make -C libft fclean

norm:
	norminette $(SRCS)

re : fclean all
