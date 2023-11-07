/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:27:25 by agan              #+#    #+#             */
/*   Updated: 2023/10/30 12:27:26 by agan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int				content;
	int				index;
	struct s_stack	*next;
}	t_stack;

typedef struct s_stackdata
{
	int length;
	int chunk;
	int key;
}	t_stackdata;

/* Stack init functions */
int		stack_init(t_stack **a, int argc, char **argv);
void	error_checker(t_stack **a, char **av, int check);
void	ft_error(t_stack **a, int num);
long	ft_atol(char *num);

/* Stack helper functions */
t_stack	*newnode(int content);
t_stack	*ft_lastnode(t_stack *lst);
t_stack	*ft_secondlast(t_stack *lst);
void	ft_addnode(t_stack **lst, t_stack *new);
int		ft_stacksize(t_stack *lst);

/* Swap commands */
void	sa(t_stack **a, int repeat);
void	sb(t_stack **b, int repeat);
void	ss(t_stack *a, t_stack *b);
/* push and rotate commmands */
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **a, int repeat);
void	rb(t_stack **b, int repeat);
/* rr commands */
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a, int repeat);
void	rrb(t_stack **b, int repeat);
void	rrr(t_stack **a, t_stack **b);

/* Sort algorithm functions */
void 	sort_three(t_stack **a);
void	sort_ten(t_stack **a, t_stack **b);
void 	sort_n(t_stackdata *stack, t_stack **a, t_stack **b);
void	move_to_top(t_stack **a, t_stack **b, t_stack *node);

/* Sort helper functions */
int		is_sorted(t_stack *a);
void	define_data(t_stackdata *stack);
int		get_position(t_stack *a, int match);

/* Push swap utils */
void	print_list(t_stack *list);
void	print_stacks(t_stack *a, t_stack *b);

/* Functions for nodes' index */
int 	get_index(int index, t_stack *a);
void 	assign_index(t_stackdata stack, t_stack *a);
t_stack	*second_to_min(int min, t_stack *a);
t_stack *find_max(t_stack *a);
t_stack *find_min(t_stack *a);

/* Cleanup functions */
void	ft_free(char **s);
void	free_stacks(t_stack *a, t_stack *b);
void	free_stack(t_stack *a);

#endif
