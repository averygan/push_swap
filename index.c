/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:07:41 by agan              #+#    #+#             */
/*   Updated: 2023/11/06 16:07:42 by agan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int get_index(int index, t_stack *a)
{
	while (a)
	{
		if (index == a->index)
			return (a->content);
		a = a->next;
	}
	return (-1);
}

t_stack	*second_to_min(int min, t_stack *a)
{
	int new_min;
	t_stack *min_node;

	new_min = 2147483647;
	min_node = a;
	while (a)
	{
		if (a->content < new_min && a->content != min && a->content > min)
		{
			min_node = a;
			new_min = a->content;
		}
		a = a->next;
	}
	return (min_node);
}

void assign_index(t_stackdata stack, t_stack *a)
{
	int i;
	t_stack *min;

	i = 1;
	min = find_min(a);
	min->index = 1;
	while (++i < stack.length + 1)
	{
		min = second_to_min(min->content, a);
		min->index = i;
	}
}

/* Find max node */
t_stack *find_max(t_stack *a)
{
	t_stack *max;

	max = a;
	while (a)
	{
		if (max->content < a->content)
			max = a;
		a = a->next;
	}
	return (max);
}

/* Find min node */
t_stack *find_min(t_stack *a)
{
	t_stack *min;

	min = a;
	while (a)
	{
		if (min->content > a->content)
			min = a;
		a = a->next;
	}
	return (min);
}