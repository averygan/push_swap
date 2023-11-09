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

#include "push_swap.h"

// More efficient version of move_to_top function
// Moves given node to top
// Push to b
// If index > pivot_value / 2, rb
void	move_to_b(t_stack **a, t_stack **b, t_stack *node)
{
	int position;

	position = get_position(*a, node->content);
	while (position != 1)
	{
		if (position == 2)
			sa(a, 0);
		else if (position > (ft_stacksize(*a) / 2))
			rra(a, 0);
		else
			ra(a, 0);
		position = get_position(*a, node->content);
	}
	if (position == 1)
		pb(a, b);
}

// Sorts stack a (highest chunk)
void sort_a(t_stack **a, t_stack **b)
{
	int count;

	count = 0;
	if (is_sorted(*a))
		return ;
	while (ft_stacksize(*a) > 3)
	{
		count++;
		move_to_top(a, b, find_min(*a));
	}
	if (ft_stacksize(*a) == 3)
		sort_three(a);
	while (count--)
		pa(a, b);
}

// Find given node, push from b to a
void push_to_a(t_stack **a, t_stack **b, t_stack *node)
{
	int position; 

	position = get_position(*b, node->content);
	while (position != 1)
	{
		if (position == 2)
			sb(b, 0);
		else if (position > (ft_stacksize(*b) / 2))
			rrb(b, 0);
		else
			rb(b, 0);
		position = get_position(*b, node->content);
	}
	if (position == 1)
		pa(a, b);
}

// Function to sort n (n > 10)
// Check if sorted
// Define_data to get chunk information
	// Find all nodes <= pivot value
	// Push node to b
void sort_n(t_stackdata *stack, t_stack **a, t_stack **b)
{
	int i;

	i = 1;
	// Defines data of number of chunks and size per chunk (pivot)
	define_data(stack);
	while (i < stack->chunk)
	{
		stack->pivot_index = stack->pivot * i;
		//printf("pivot is %d\n", stack->pivot * i);
		stack->pivot_value = get_index((stack->pivot_index), *a);
		//printf("pivot_value is %d\n", pivot_value);
		stack->pivot_node = find_pivot_node(*a, stack->pivot_value);
		// Move everything <= pivot value to stack b
		//printf("chunk size is %d, pivot value is %d\n", stack->chunk, pivot_value);
		while (stack->pivot_node)
		{
			//printf("pivot value is %d, currently moving %d\n", pivot_value, (*a)->content);
			move_to_b(a, b, stack->pivot_node);
			stack->pivot_node = find_pivot_node(*a, stack->pivot_value);
		}
		i++;
	}
	sort_a(a, b);
	while (ft_stacksize(*b) > 0)
		push_to_a(a, b, find_max(*b));
}
