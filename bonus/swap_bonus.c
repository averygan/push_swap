/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:54:30 by agan              #+#    #+#             */
/*   Updated: 2023/11/11 16:47:17 by agan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

// swap first 2 elements at the top of stack a
void	sa(t_stack **a)
{
	int size;
	t_stack *tmp;
	size = ft_stacksize(*a);
	if (size >= 2)
	{
		tmp = (*a)->next;
		(*a)->prev = tmp;
		(*a)->next = (*a)->next->next;
		if (tmp->next)
			(*a)->next->prev = *a;
		tmp->prev = NULL;
		tmp->next = *a;
		*a = tmp;
	}
}

// swap first 2 elements at the top of stack b
void	sb(t_stack **b)
{
	int size;
	t_stack *tmp;
	size = ft_stacksize(*b);
	if (size >= 2)
	{
		tmp = (*b)->next;
		(*b)->prev = tmp;
		(*b)->next = (*b)->next->next;
		if (tmp->next)
			(*b)->next->prev = *b;
		tmp->prev = NULL;
		tmp->next = *b;
		*b = tmp;
	}
}

// sa + sb
void	ss(t_stack **a, t_stack **b)
{
	sa(a);
	sb(b);
}
