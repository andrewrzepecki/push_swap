# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/11 18:48:32 by anrzepec          #+#    #+#              #
#    Updated: 2019/04/04 18:42:46 by anrzepec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHKNAME = 	checker

PSNAME	= 	push_swap

PSSRC 	= 	ps/push_swap_main.c \
			ps/ft_ps_output.c\
			ps/ft_sort_a.c \
			ps/ft_sort_b.c \
			ps/ft_sort_stacks.c \
			ps/ft_sort_tools.c

CHKSRC	=	ch/checker_main.c \
			ch/ft_checker_output.c \
			ch/ft_get_commands.c \
			ch/ft_get_vcommands.c \
			ch/ft_print_screen.c

COMMSRC =	common_srcs/ft_execute_comms.c \
			common_srcs/ft_parse_args.c	\
			common_srcs/ft_quicksort.c \
			common_srcs/ft_stack_functions.c \
			common_srcs/ft_tab_tools.c

COBJS	=	$(COMMSRC:.c=.o)

PSOBJS	=	$(PSSRC:.c=.o)

CHKOBJS	=	$(CHKSRC:.c=.o)

CC		=	gcc 

CFLAGS	+=	-Werror -Wall -Wextra

GFLAGS	+=	-F/Library/Frameworks -framework SDL2

RM		=	rm -f

LPATH	=	libft/libft.a

all: $(PSNAME) $(CHKNAME)

%.o:		%.c	
			@$(CC) $(CFLAGS) -c $< -o $@

#lib:	
#	@make -C libft/

$(PSNAME):	$(LPATH) $(COBJS) $(PSOBJS)
	$(CC) -o $(PSNAME) $(COBJS) $(PSOBJS) $(LPATH)

$(CHKNAME):	$(LPATH) $(COBJS) $(CHKOBJS)
	$(CC) $(GFLAGS) -o $(CHKNAME) $(COBJS) $(CHKOBJS) $(LPATH)

fcleanlib:  cleanlib
	@make fclean -C libft/

cleanlib:
	@make clean -C libft/

clean:		cleanlib
	$(RM) $(COBJS) $(PSOBJS)

fclean:		fcleanlib clean
	$(RM) $(NAME)

re:			fclean all

.PHONY: re all fclean clean