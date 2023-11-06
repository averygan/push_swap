/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:21:11 by agan              #+#    #+#             */
/*   Updated: 2023/11/06 15:21:37 by agan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// ****** Algorithm ******
// 3 numbers
// If largest number at top, ra
// If largest number in the middle, sa, ra
// Checks first two elements, sa if #1 larger than #2
void sort_three(t_stack **a)
{
	t_stack *max;

	max = find_max(*a);
	if (*a == max)
		ft_ra(a, 0);
	else if ((*a)->next == max)
		ft_rra(a, 0);
	if ((*a)->content > (*a)->next->content)
		ft_sa(*a, 0);
}

// Function to sort n (n >= 4)
void sort_n(t_stackdata *stack, t_stack **a, t_stack **b)
{
	int key_value;
	int i;

	i = 1;
	(void)b;
	// If aleady sorted, return
	if (is_sorted(*a))
	{
		printf("input is already sorted\n");
		exit(0);
	}
	// Defines data of number of chunks and size per chunk (key)
	define_data(stack);
	while (i <= stack->chunk)
	{
		key_value = get_index((stack->key * i), *a);
		// Move everything <= key value to stack b
		printf("keyvalue is %d\n", key_value);
		i++;
	}
}