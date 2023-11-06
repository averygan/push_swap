/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_commands.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:56:52 by agan              #+#    #+#             */
/*   Updated: 2023/11/06 15:56:54 by agan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// take first el at top of b, and put it at top of a, nothing if b empty
void	ft_pa(t_stack **a, t_stack **b)
{
	int size;
	t_stack *tmp;
	size = ft_stacksize(*b);
	if (size > 0)
	{
		tmp = *b;
		*b = (*b)->next;
	}
	tmp->next = *a;
	*a = tmp;
	ft_printf("pa\n");
}

// take first el at top of a and put it at top of b, nothing if a empty
void	ft_pb(t_stack **a, t_stack **b)
{
	int		size;
	t_stack *tmp;

	size = ft_stacksize(*a);
	if (size > 0)
	{
		tmp = *a;
		*a = (*a)->next;
	}
	tmp->next = *b;
	*b = tmp;
	ft_printf("pb\n");
}

// shift up all elements of stack a by 1 (first el becomes last)
void	ft_ra(t_stack **a, int repeat)
{
	t_stack *first;
	t_stack *last;

	if (*a)
	{
		first = *a;
		last = ft_lastnode(*a);
		*a = (*a)->next;
		first->next = NULL;
		last->next = first;
	}
	if (!repeat)
		ft_printf("ra\n");
}

// shift up all elements of stack b by 1 (first el becomes last)
void	ft_rb(t_stack **b, int repeat)
{
	t_stack *first;
	t_stack *last;
	if (*b)
	{
		first = *b;
		last = ft_lastnode(*b);
		*b = (*b)->next;
		first->next = NULL;
		last->next = first;
	}
	if (!repeat)
		ft_printf("rb\n");	
}

// ra + rb
void	ft_rr(t_stack **a, t_stack **b)
{
	ft_ra(a, 1);
	ft_rb(b, 1);
	ft_printf("rr\n");
}

