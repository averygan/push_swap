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
# include <stdbool.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int				content;
	int				index;
	int				cost;
	struct s_stack	*target;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

typedef struct s_data
{
	int		length;
	int		a_size;
	int		b_size;
	bool	a_median;
	bool	b_median;
}	t_data;

/* Stack init functions */
int		stack_init(t_data *stack, t_stack **a, int argc, char **argv);
void	error_dup(t_data *stack, t_stack **a);
void	error_checker(t_data *stack, int argc, char **av);
void	ft_error(t_data *stack, t_stack **a, int argc, char **av);
int		ft_atol(t_data *stack, char *num, int argc, char **av);

/* Stack helper functions */
t_stack	*newnode(int content);
t_stack	*ft_lastnode(t_stack *lst);
t_stack	*ft_secondlast(t_stack *lst);
void	ft_addnode(t_stack **lst, t_stack *new);
int		ft_stacksize(t_stack *lst);

/* Swap commands */
void	sa(t_stack **a, int repeat);
void	sb(t_stack **b, int repeat);
void	ss(t_stack **a, t_stack **b);
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
void	sort_three(t_stack **a);
void	sort_ten(t_stack **a, t_stack **b);

/* Sort n algorithm functions */
void	sort_n(t_data *stack, t_stack **a, t_stack **b);
int		get_cost(t_stack *a, t_stack *node);
void	move_cost(t_stack *a, t_stack *b);
void	move_stacks(t_data *stack, t_stack **a, t_stack **b);
void	push_to_b(t_data *stack, t_stack **a, t_stack **b);

/* Sort helper functions */
int		is_sorted(t_stack *a);
int		get_position(t_stack *a, t_stack *match);
void	move_to_top(t_stack **a, t_stack **b, t_stack *node);
void	rotate_stack(t_data *stack, t_stack **a_b, t_stack *to_move, char s);
void	set_target(t_stack *a, t_stack *b);

/* Push swap utils */
void	set_data(t_data *stack, t_stack *a, t_stack *b, t_stack *target_node);
void	assign_index(t_data *stack, t_stack *a);
t_stack	*find_max(t_stack *a);
t_stack	*find_min(t_stack *a);
t_stack	*second_to_min(int min, t_stack *a);

/* Memory free functions */
void	ft_free(char **s);
void	free_stacks(t_data *stack, t_stack *a, t_stack *b);
void	free_stack(t_stack *a);

#endif
