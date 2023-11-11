/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:50:27 by agan              #+#    #+#             */
/*   Updated: 2023/11/11 16:46:58 by agan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

// shift down all elements of stack a by 1 (last el becomes first)
void	rra(t_stack **a)
{
	t_stack	*last;
	t_stack	*second_to_last;
	int		size;

	size = ft_stacksize(*a);
	if (size > 1)
	{
		second_to_last = ft_secondlast(*a);
		last = second_to_last->next;
		second_to_last->next = NULL;
		last->next = *a;
		(*a)->prev = last;
		last->prev = NULL;
		*a = last;
	}
}

// shift down all elements of stack b by 1 (last el becomes first)
void	rrb(t_stack **b)
{
	t_stack	*last;
	t_stack	*second_to_last;
	int		size;

	size = ft_stacksize(*b);
	if (size > 1)
	{
		second_to_last = ft_secondlast(*b);
		last = second_to_last->next;
		second_to_last->next = NULL;
		last->next = *b;
		(*b)->prev = last;
		last->prev = NULL;
		*b = last;
	}
}

// rra + rrb
void	rrr(t_stack **a, t_stack **b)
{
	rra(a);
	rrb(b);
}
