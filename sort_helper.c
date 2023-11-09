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
	if (stack->length >= 400)
	{
		stack->chunk = 12;
		stack->pivot = (stack->length / 12);
	}
	else if (stack->length >= 100)
	{
		stack->chunk = 4;
		stack->pivot = (stack->length / 4);
	}
	else if (stack->length >= 4)
	{
		stack->chunk = 2;
		stack->pivot = (stack->length / 2);
	}
}

// Gets which position int match is within the linked list
int	get_position(t_stack *a, int match)
{
	int pos;

	 pos = 1;
	 while (a)
	 {
	 	if (a->content == match)
	 		return (pos);
	 	pos++;
	 	a = a->next;
	 }
	 return (-1);
}

// Function to find the closest node, from top and bottom, that matches pivot value
t_stack *find_pivot_node(t_stack *a, int pivot_value)
{
	t_stack *top;
	t_stack *bot;
	int top_pos;
	int bot_pos;

	top_pos = 0;
	bot_pos = 0;
	top = a;
	bot = ft_lastnode(a);
	while (top && ++top_pos)
	{
		if (top->content <= pivot_value)
			break ;
		top = top->next;
	}
	while (bot && ++bot_pos)
	{
		if (bot->content <= pivot_value)
			break ;
		bot = bot->prev;
	}
	if (top_pos > bot_pos)
		return (bot);
	if (top_pos == bot_pos && !top && !bot)
		return (NULL);
	return (top);
}
