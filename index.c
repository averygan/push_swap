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
