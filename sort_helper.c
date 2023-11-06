/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:59:10 by agan              #+#    #+#             */
/*   Updated: 2023/11/06 15:59:11 by agan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Function to check if stack is sorted
int is_sorted(t_stack *a)
{
	t_stack *curr;

	curr = a;
	while (a)
	{
		if (curr->content > a->content)
			return (0);
		curr = a;
		a = a->next;
	}
	return (1);
}

// Function to define stack data
// Number of chunks
// Size per chunk
void define_data(t_stackdata *stack)
{
	if (stack->length >= 500)
	{
		stack->chunk = 8;
		stack->length = (stack->length / 8);
	}
	else if (stack->length >= 100)
	{
		stack->chunk = 4;
		stack->key = (stack->length / 4);
	}
	else if (stack->length >= 4)
	{
		stack->chunk = 2;
		stack->key = (stack->length / 3);
	}
}

