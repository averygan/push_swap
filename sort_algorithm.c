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
		ra(a, 0);
	else if ((*a)->next == max)
		rra(a, 0);
	if ((*a)->content > (*a)->next->content)
		sa(a, 0);
}

// Sort n <= 10 && n != 3
// Check if sorted
// If size > 3, move min node to b until size = 3
// If size = 2, swap top 2
	// When size = 3 -> use sort_three function
// Push from b back to a
void sort_ten(t_stack **a, t_stack **b)
{
	if (is_sorted(*a))
	{
		printf("input is already sorted\n");
		exit(0);
	}
	// Get min node and move to top, then move to b
	while (ft_stacksize(*a) > 3)
		move_to_top(a, b, find_min(*a));
	if (ft_stacksize(*a) == 2)
		sa(a, 0);
	// If stack size == 3, sort the three numbers in a
	else if (ft_stacksize(*a) == 3)
		sort_three(a);
	// Push from b back to a
	while (*b)
		pa(a, b);
}

// Move given node to top, and push to stack b
void move_to_top(t_stack **a, t_stack **b, t_stack *node)
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