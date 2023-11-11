/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 16:06:05 by agan              #+#    #+#             */
/*   Updated: 2023/11/11 16:06:06 by agan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int				content;
	int				index;
	int 			cost;
	struct s_stack	*target;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

typedef struct s_data
{
	int length;
	int a_size;
	int b_size;
	bool a_median;
	bool b_median;
}	t_data;

/* Stack init functions */
int		stack_init(t_data *stack, t_stack **a, int argc, char **argv);
void	error_checker(t_data *stack, t_stack **a, char **av, int check);
void	ft_error(t_data *stack, t_stack **a, int num);
int		ft_atol(t_data *stack, char *num);

/* Stack helper functions */
t_stack	*newnode(int content);
t_stack	*ft_lastnode(t_stack *lst);
t_stack	*ft_secondlast(t_stack *lst);
void	ft_addnode(t_stack **lst, t_stack *new);
int		ft_stacksize(t_stack *lst);

/* Swap commands */
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
/* push and rotate commmands */
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
/* rr commands */
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

/* Checker utils */
int		is_sorted(t_stack *a);

/* Memory free functions */
void	ft_free(char **s);
void	free_stacks(t_data *stack, t_stack *a, t_stack *b);
void	free_stack(t_stack *a);

# endif
