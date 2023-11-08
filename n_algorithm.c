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
	// Find all nodes <= key value
	// Push node to b
void sort_n(t_stackdata *stack, t_stack **a, t_stack **b)
{
	int key_value;
	t_stack *key_node;
	int i;

	i = 1;
	(void)b;
	// If aleady sorted, return
	if (is_sorted(*a))
		exit(0);
	// Defines data of number of chunks and size per chunk (key)
	define_data(stack);
	while (i < stack->chunk)
	{
		//printf("key is %d\n", stack->key * i);
		key_value = get_index((stack->key * i), *a);
		//printf("key_value is %d\n", key_value);
		key_node = find_key_node(*a, key_value);
		// Move everything <= key value to stack b
		while (key_node)
		{
			move_to_top(a, b, key_node);
			key_node = find_key_node(*a, key_value);
		}
		i++;
	}
	sort_a(a, b);
	while (ft_stacksize(*b) > 0)
		push_to_a(a, b, find_max(*b));
}
