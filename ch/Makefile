# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/11 18:48:32 by anrzepec          #+#    #+#              #
#    Updated: 2019/04/16 17:34:51 by anrzepec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= 	../checker

SRC 	= 	checker_main.c \
			ft_checker_output.c \
			ft_get_commands.c \
			ft_get_vcommands.c \
			ft_print_screen.c \
			../common_srcs/ft_check_no_args.c \
			../common_srcs/ft_execute_comms.c \
			../common_srcs/ft_parse_args.c	\
			../common_srcs/ft_quicksort.c \
			../common_srcs/ft_stack_functions.c \
			../common_srcs/ft_tab_tools.c

OBJS	=	$(SRC:.c=.o)

CC		=	gcc 

CFLAGS	+=	-Werror -Wall -Wextra

GFLAGS	+=	-F/Library/Frameworks -framework SDL2

RM		=	rm -f

DEBUG	=   -g3 -fsanitize=address

LPATH	=	../libft/libft.a

all:	  	$(NAME)

%.o:		%.c	
			@$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(LPATH) $(OBJS)
	@$(CC) $(GFLAGS) -o $(NAME) $(OBJS) $(LPATH) && echo "Checker compiled with success!"

$(LPATH):
			@make -C ../libft/ && echo "Libft compiled with success"

fcleanlib:  cleanlib
			@make fclean -C ../libft/

cleanlib:
			@make clean -C ../libft/

clean:		cleanlib
	$(RM) $(OBJS)

fclean:		fcleanlib clean
	$(RM) $(NAME)

re:			fclean all

.PHONY: re all fclean clean checker