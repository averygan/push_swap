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

#include "push_swap.h"

// swap first 2 elements at the top of stack a
void	ft_sa(t_stack *a, int repeat)
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
	if (!repeat)
		ft_printf("sa\n");
}

// swap first 2 elements at the top of stack b
void	ft_sb(t_stack *b, int repeat)
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
	if (!repeat)
		ft_printf("sb\n");
}

// sa + sb
void	ft_ss(t_stack *a, t_stack *b)
{
	ft_sa(a, 1);
	ft_sa(b, 1);
	ft_printf("s\n");
}
