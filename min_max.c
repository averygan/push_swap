/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:47:48 by agan              #+#    #+#             */
/*   Updated: 2023/11/08 16:47:49 by agan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
