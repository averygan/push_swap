/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:56:52 by agan              #+#    #+#             */
/*   Updated: 2023/11/11 16:46:54 by agan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

// take first el at top of b, and put it at top of a, nothing if b empty
void	pa(t_stack **a, t_stack **b)
{
	int		size;
	t_stack	*tmp;

	size = ft_stacksize(*b);
	if (size > 0)
	{
		tmp = *b;
		*b = (*b)->next;
		if (*b)
			(*b)->prev = NULL;
		tmp->next = *a;
		if (tmp->next)
			tmp->next->prev = tmp;
		*a = tmp;
	}
}

// take first el at top of a and put it at top of b, nothing if a empty
void	pb(t_stack **a, t_stack **b)
{
	int		size;
	t_stack	*tmp;

	size = ft_stacksize(*a);
	if (size > 0)
	{
		tmp = *a;
		*a = (*a)->next;
		if (*a)
			(*a)->prev = NULL;
		tmp->next = *b;
		if (tmp->next)
			tmp->next->prev = tmp;
		*b = tmp;
	}
}

// shift up all elements of stack a by 1 (first el becomes last)
void	ra(t_stack **a)
{
	t_stack	*first;
	t_stack	*last;

	if (*a)
	{
		first = *a;
		last = ft_lastnode(*a);
		if (first == last)
			return ;
		first->prev = last;
		last->next = first;
		*a = (*a)->next;
		(*a)->prev = NULL;
		first->next = NULL;
		last->next = first;
	}
}

// shift up all elements of stack b by 1 (first el becomes last)
void	rb(t_stack **b)
{
	t_stack	*first;
	t_stack	*last;

	if (*b)
	{
		first = *b;
		last = ft_lastnode(*b);
		if (first == last)
			return ;
		first->prev = last;
		last->next = first;
		*b = (*b)->next;
		(*b)->prev = NULL;
		first->next = NULL;
		last->next = first;
	}
}

// ra + rb
void	rr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
}
