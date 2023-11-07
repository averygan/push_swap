/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_commands.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:50:27 by agan              #+#    #+#             */
/*   Updated: 2023/11/06 15:57:45 by agan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// shift down all elements of stack a by 1 (last el becomes first)
void	rra(t_stack **a, int repeat)
{
	t_stack *last;
	t_stack *second_to_last;
	int size;
	size = ft_stacksize(*a);
	if (size > 1)
	{
		second_to_last = ft_secondlast(*a);
		last = second_to_last->next;
		second_to_last->next = NULL;
		last->next = *a;
		*a = last;
	}
	if (!repeat)
		ft_printf("rra\n");
}

// shift down all elements of stack b by 1 (last el becomes first)
void	rrb(t_stack **b, int repeat)
{
	t_stack *last;
	t_stack *second_to_last;
	int size;

	size = ft_stacksize(*b);
	if (size > 1)
	{
		second_to_last = ft_secondlast(*b);
		last = second_to_last->next;
		second_to_last->next = NULL;
		last->next = *b;
		*b = last;
	}
	if (!repeat)
		ft_printf("rrb\n");
}

// rra + rrb
void	rrr(t_stack **a, t_stack **b)
{
	rra(a, 1);
	rra(b, 1);
	ft_printf("rrr\n");	
}
