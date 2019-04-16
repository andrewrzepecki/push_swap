# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/11 18:48:32 by anrzepec          #+#    #+#              #
#    Updated: 2019/04/16 17:30:53 by anrzepec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all: 		push_swap checker

push_swap:
			@make -C ps/

checker:	
			@make -C ch/

fcleanlib:  cleanlib
			@make fclean -C libft/

cleanlib:
			@make clean -C libft/

cleanchecker: 
			@make clean -C ch/

cleanpush_swap:
			@make clean -C ps/

fcleanchecker:	cleanchecker
			@make fclean -C ch/
			
fcleanpush_swap: cleanpush_swap
			@make fclean -C ps/

clean:		cleanchecker cleanpush_swap

fclean:		fcleanchecker fcleanpush_swap

re:			fclean all

.PHONY: 	re all fclean clean push_swap checker cleanchecker cleanpush_swap fcleanchecker fcleanpush_swap
