/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:50:27 by agan              #+#    #+#             */
/*   Updated: 2023/11/02 14:50:28 by agan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// swap first 2 elements at the top of stack a
void ft_sa(t_stack *a, int repeat)
{
	int size;
	int tmp;
	size = ft_stacksize(a);
	if (size >= 2)
	{
		tmp = a->content;
		a->content = a->next->content;
		a->next->content = tmp;
	}
	if (repeat)
		ft_printf("sa\n");
}

// swap first 2 elements at the top of stack b
void ft_sb(t_stack *b, int repeat)
{
	int size;
	int tmp;
	size = ft_stacksize(b);
	if (size >= 2)
	{
		tmp = b->content;
		b->content = b->next->content;
		b->next->content = tmp;
	}
	if (repeat)
		ft_printf("sb\n");
}

// sa + sb
void ft_ss(t_stack *a, t_stack *b)
{
	ft_sa(a, 1);
	ft_sa(b, 1);
	ft_printf("s\n");
}

// take first el at top of b, and put it at top of a, nothing if b empty
void ft_pa(t_stack **a, t_stack **b)
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
void ft_pb(t_stack **a, t_stack **b)
{
	int size;
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

// // shift up all elements of stack a by 1 (first el becomes last)
// void ft_ra(t_stack *a, t_stack *b)
// {
	
// }

// // shift up all elements of stack b by 1 (first el becomes last)
// void ft_rb(t_stack *a, t_stack *b)
// {
	
// }

// // ra + rb
// void ft_rr(t_stack *a, t_stack *b)
// {
	
// }

// // shift down all elements of stack a by 1 (last el becomes first)
// void ft_rra(t_stack *a, t_stack *b)
// {
	
// }

// // shift down all elements of stack b by 1 (last el becomes first)
// void ft_rrb(t_stack *a, t_stack *b)
// {
	
// }

// // rra + rrb
// void ft_rrr(t_stack *a, t_stack *b)
// {
	
// }