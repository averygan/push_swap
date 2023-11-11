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
int	is_sorted(t_stack *a)
{
	t_stack	*curr;

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
	int	pos;

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
void	rotate_stack(t_data *stack, t_stack **a_b, t_stack *to_move, char s)
{
	while (*a_b != to_move)
	{
		if (s == 'a')
		{
			if (stack->a_median)
				rra(a_b, 0);
			else
				ra(a_b, 0);
		}
		else if (s == 'b')
		{
			if (stack->b_median)
				rrb(a_b, 0);
			else
				rb(a_b, 0);
		}
	}
}

// Move given node to top, and push to stack b
void	move_to_top(t_stack **a, t_stack **b, t_stack *node)
{
	int	position;

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

// Sets target node of b to a matching node in a that is
// the smallest, larger node
// If none exists, set to smallest node
void	set_target(t_stack *a, t_stack *b)
{
	t_stack	*tmp;
	t_stack	*target_n;
	int		flag;

	while (b)
	{
		flag = 0;
		tmp = a;
		target_n = find_max(a);
		while (tmp)
		{
			if (tmp->content > b->content && tmp->content <= target_n->content)
			{
				target_n = tmp;
				flag = 1;
			}
			tmp = tmp->next;
		}
		if (flag)
			b->target = target_n;
		else
			b->target = find_min(a);
		b = b->next;
	}
}
