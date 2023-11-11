/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_algorithm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:09:36 by agan              #+#    #+#             */
/*   Updated: 2023/11/08 14:09:37 by agan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Sets target node of b to a matching node in a that is the smallest node that's larger
// If none exists, set to smallest node
void	set_target(t_stack *a, t_stack *b)
{
	t_stack *tmp;
	t_stack *target_node;
	int flag;

	while (b)
	{
		flag = 0;
		tmp = a;
		target_node = find_max(a);
		while (tmp)
		{
			if (tmp->content > b->content && tmp->content <= target_node->content)
			{
				target_node = tmp;
				flag = 1;
			}
			tmp = tmp->next;
		}
		if (flag)
			b->target = target_node;
		else
			b->target = find_min(a);
		b = b->next;
	}
}

// Function to find the closest node, from top and bottom, that matches pivot value
int get_cost(t_stack *a, t_stack *node)
{
	int position;
	int stacksize;

	position = get_position(a, node);
	stacksize = ft_stacksize(a);
	if (position > (stacksize / 2))
		return (stacksize - position);
	else
		return (position - 1);
}

// Calculate cost of moving the node to target node
void move_cost(t_stack *a, t_stack *b)
{
	t_stack *tmp;

	tmp = b;
	while (tmp)
	{
		tmp->cost = get_cost(a, tmp->target) + get_cost(b, tmp);
		tmp = tmp->next;
	}
}

// Function to find the cheapest node and move both the node and target node to top of stack
// Push to a
void move_stacks(t_data *stack, t_stack **a, t_stack **b)
{
	t_stack *to_move;
	t_stack *tmp;

	tmp = *b;
	to_move = *b;
	while (tmp)
	{
		if (to_move->cost > tmp->cost)
			to_move = tmp;
		tmp = tmp->next;
	}
	set_data(stack, *a, *b, to_move);
	if (stack->b_median && stack->a_median)
		while (*a != to_move->target && *b != to_move)
			rrr(a, b);
	if (!(stack->b_median) && !(stack->a_median))
		while (*a != to_move->target && *b != to_move)
			rr(a, b);
	set_data(stack, *a, *b, to_move);
	rotate_stack(stack, a, to_move->target, 'a');
	rotate_stack(stack, b, to_move, 'b');
	if (*a == to_move->target && *b == to_move)
		pa(a, b);
}

// Algo to sort n elements
// 	Push all nodes from b to a (except 3)
//	Assign b to a target node
//	Calculate cost of moving from b node to target node
//	Move cheapest
void	sort_n(t_data *stack, t_stack **a, t_stack **b)
{
	t_stack *min;

	while (ft_stacksize(*a) > 3)
		pb(a, b);
	sort_three(a);
	while (*b)
	{
		set_target(*a, *b);
		move_cost(*a, *b);
		move_stacks(stack, a, b);
	}
	min = find_min(*a);
	set_data(stack, *a, *b, min);
	rotate_stack(stack, a, min, 'a');
}