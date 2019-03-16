/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 17:31:51 by anrzepec          #+#    #+#             */
/*   Updated: 2019/03/15 16:47:43 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	CHECKER_H_
# define CHECKER_H_

# include "../libft/libft.h"

# define	A	0
# define	B	1


typedef	struct		s_stack
{
	int				pos;
	int 			value;
	struct s_stack	*next;
	struct s_stack  *prev;
}					t_stack;			

typedef struct		s_commands
{
	int				(*f)(t_stack **);
}					t_commands;

/* List Functions */
t_stack				*ft_new_stkelem(int d);
void				ft_free_stack(t_stack **stk);

/* Output Funcitons */
void				ft_malloc_fail(void);
int					ft_checker_output(int ret);

/* Execute Commands */
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

#endif