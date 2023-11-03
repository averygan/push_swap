/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:18:06 by agan              #+#    #+#             */
/*   Updated: 2023/11/02 17:18:07 by agan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Print content of a list
void	print_list(t_stack *list)
{
	while (list)
	{
		printf("%d -> ", list->content);
		list = list->next;
	}
	printf("list end\n");
}

// Print content of both stacks
void	print_stacks(t_stack *a, t_stack *b)
{
	ft_printf("stack a: ");
	while (a)
	{
		ft_printf("%d -> ", a->content);
		a = a->next;
	}
	printf("list end\n");
	ft_printf("stack b: ");
	while (b)
	{
		ft_printf("%d -> ", b->content);
		b = b->next;
	}
	printf("list end\n");
}

// Free both stacks
void	free_stacks(t_stack *a, t_stack *b)
{
	t_stack	*tmp;

	while (a)
	{
		tmp = a;
		a = a->next;
		free(tmp);
	}
	while (b)
	{
		tmp = b;
		b = b->next;
		free(tmp);
	}
}

void	free_stack(t_stack *a)
{
	t_stack	*tmp;

	while (a)
	{
		tmp = a;
		a = a->next;
		free(tmp);
	}
}
