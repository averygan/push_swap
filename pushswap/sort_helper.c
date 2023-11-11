/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:59:10 by agan              #+#    #+#             */
/*   Updated: 2023/11/06 15:59:11 by agan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Function to check if stack is sorted
int is_sorted(t_stack *a)
{
	t_stack *curr;

	curr = a;
	while (a)
	{
		if (curr->content > a->content)
			return (0);
		curr = a;
		a = a->next;
	}
	return (1);
}

// Gets which position int match is within the linked list
int	get_position(t_stack *a, t_stack *match)
{
	int pos;

	 pos = 1;
	 while (a)
	 {
	 	if (match && a && a->content == match->content)
	 		return (pos);
	 	pos++;
	 	a = a->next;
	 }
	 return (-1);
}

// Rotate stack till to_move is at the top of stack
void rotate_stack(t_data *stack, t_stack **curr_stack, t_stack *to_move, char stack_name)
{
	while (*curr_stack != to_move)
	{
		if (stack_name == 'a')
		{
			if (stack->a_median)
				rra(curr_stack, 0);
			else
				ra(curr_stack, 0);
		}
		else if (stack_name == 'b')
		{
			if (stack->b_median)
				rrb(curr_stack, 0);
			else
				rb(curr_stack, 0);
		}
	}
}

// Move given node to top, and push to stack b
void move_to_top(t_stack **a, t_stack **b, t_stack *node)
{
	int position;

	position = get_position(*a, node);
	while (position != 1)
	{
		if (position == 2)
			sa(a, 0);
		else if (position > (ft_stacksize(*a) / 2))
			rra(a, 0);
		else
			ra(a, 0);
		position = get_position(*a, node);
	}
	if (position == 1)
		pb(a, b);
}