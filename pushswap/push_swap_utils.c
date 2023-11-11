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

#include "../push_swap.h"

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

/* Function to set data for above/below median for target node and size of both stacks */
void set_data(t_data *stack, t_stack *a, t_stack *b, t_stack *target_node)
{
	stack->a_median = false;
	stack->b_median = false;
	stack->a_size = ft_stacksize(a);
	stack->b_size = ft_stacksize(b);
	if (get_position(a, target_node->target) > stack->a_size / 2)
		stack->a_median = true;
	if (get_position(b, target_node) > stack->b_size / 2)
		stack->b_median = true;
}

// // Print content of a list
// void	print_list(t_stack *list)
// {
// 	while (list)
// 	{
// 		printf("%d -> ", list->content);
// 		list = list->next;
// 	}
// 	printf("list end\n");
// }

// // Print content of both stacks
// void	print_stacks(t_stack *a, t_stack *b)
// {
// 	ft_printf("stack a: ");
// 	while (a)
// 	{
// 		ft_printf("%d -> ", a->content);
// 		//ft_printf("%d (index %d)-> ", a->content, a->index);
// 		a = a->next;
// 	}
// 	printf("list end\n");
// 	ft_printf("stack b: ");
// 	while (b)
// 	{
// 		ft_printf("%d -> ", b->content);
// 		b = b->next;
// 	}
// 	printf("list end\n");
// }

// // Print content of both stacks
// void	print_stackbackwards(t_stack *a, t_stack *b)
// {
// 	ft_printf("\nPrinting backwards\n");
// 	ft_printf("stack a: ");
// 	t_stack *a_tail = ft_lastnode(a);
// 	t_stack *b_tail = ft_lastnode(b);
// 	while (a_tail)
// 	{
// 		//ft_printf("%d -> ", a->content);
// 		ft_printf("%d -> ", a_tail->content);
// 		a_tail = a_tail->prev;
// 	}
// 	printf("list end\n");
// 	ft_printf("stack b: ");
// 	while (b_tail)
// 	{
// 		ft_printf("%d -> ", b_tail->content);
// 		b_tail = b_tail->prev;
// 	}
// 	printf("list end\n");
// }
