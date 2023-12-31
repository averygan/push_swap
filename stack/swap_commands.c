/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:54:30 by agan              #+#    #+#             */
/*   Updated: 2023/11/06 15:54:31 by agan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// swap first 2 elements at the top of stack a
void	sa(t_stack **a, int repeat)
{
	int		size;
	t_stack	*tmp;

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
		if (!repeat)
			ft_printf("sa\n");
	}
}

// swap first 2 elements at the top of stack b
void	sb(t_stack **b, int repeat)
{
	int		size;
	t_stack	*tmp;

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
		if (!repeat)
			ft_printf("sb\n");
	}
}

// sa + sb
void	ss(t_stack **a, t_stack **b)
{
	sa(a, 1);
	sb(b, 1);
	ft_printf("s\n");
}
