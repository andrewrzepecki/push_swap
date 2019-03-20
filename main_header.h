/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_header.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 16:21:22 by anrzepec          #+#    #+#             */
/*   Updated: 2019/03/20 16:36:53 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_HEADER_H
# define MAIN_HEADER_H

#include "libft/libft.h"

# define A 0
# define B 1

/*Stack Structures */
typedef struct		s_stack
{
	int				value;
	int				pos;
	struct s_stack	*next;
}					t_stack;

typedef struct		s_commands
{
	int				(*f)(t_stack **);
}					t_commands;

/* Parsing Functions */
int					ft_parse_args(int ac, char **av);
int					ft_check_double(char *s, int index, int len);
int					ft_stack_check(t_stack **chk, int d);

/* Stack Functions */
void				ft_set_stacks(t_stack **stack, int ac, char **av, int *tab);
void				ft_free_stack(t_stack **stk);
int					ft_get_pos(int *tab, int t_len, int nb);
t_stack				*ft_new_stkelem(int d, int *tab, int t_len);

/* Output Function */
void				ft_malloc_fail(void);

/* Stack Action Commands */
int					ft_swap_a(t_stack **stack);
int					ft_swap_b(t_stack **stack);
int					ft_swap_r(t_stack **stack);
int					ft_push_a(t_stack **stack);
int					ft_push_b(t_stack **stack);
int					ft_rot_a(t_stack **stack);
int					ft_rot_b(t_stack **stack);
int					ft_rot_r(t_stack **stack);
int					ft_rev_rot_a(t_stack **stack);
int					ft_rev_rot_b(t_stack **stack);
int					ft_rev_rot_r(t_stack **stack);

/* Quicksort Array Implementation */
void				ft_quicksort(int *tab, int min, int max);

#endif