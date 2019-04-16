# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/11 18:48:32 by anrzepec          #+#    #+#              #
#    Updated: 2019/04/16 17:28:15 by anrzepec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= 	../push_swap

SRC 	= 	push_swap_main.c \
			ft_sort_tools.c \
			ft_sort_stacks.c \
			ft_sort_b.c \
			ft_sort_a.c \
			ft_ps_output.c \
			../common_srcs/ft_check_no_args.c \
			../common_srcs/ft_execute_comms.c \
			../common_srcs/ft_parse_args.c	\
			../common_srcs/ft_quicksort.c \
			../common_srcs/ft_stack_functions.c \
			../common_srcs/ft_tab_tools.c

OBJS	=	$(SRC:.c=.o)

CC		=	gcc 

CFLAGS	+=	-Werror -Wall -Wextra

RM		=	rm -f

LPATH	=	../libft/libft.a

all:		$(NAME)

%.o:		%.c
			@$(CC) $(CFLAGS) -c $< -o $@


$(NAME):	$(LPATH) $(OBJS)
			@$(CC) -o $(NAME) $(OBJS) $(LPATH) && echo "Push_swap compiled with success!"

$(LPATH):
			@make -C ../libft/

fcleanlib:  cleanlib
			@make fclean -C ../libft/

cleanlib:
			@make clean -C ../libft/

clean:		cleanlib
	$(RM) $(OBJS)

fclean:		fcleanlib clean
	$(RM) $(NAME)

re:			fclean all

.PHONY: re all fclean clean