/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:27:16 by agan              #+#    #+#             */
/*   Updated: 2023/10/30 12:27:17 by agan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;
	t_stackdata *stack;

	stack = malloc(sizeof(t_stackdata));
	a = NULL;
	b = NULL;
	if (argc > 1)
		stack->length = stack_init(&a, argc, argv);
	// Assigns index for each node
	assign_index(stack, a);
	if (is_sorted(a))
	{
		free_stack(a);
		exit(0);
	}
	if (stack->length == 3)
		sort_three(&a);
	else if (stack->length != 3 && stack->length <= 10)
		sort_ten(&a, &b);
	else if (stack->length > 10)
		sort_n(stack, &a, &b);
	// print_stacks(a, b);
	// print_stackbackwards(a, b);
	free_stacks(a, b);
}

// int	main(int argc, char **argv)
// {
// 	t_stack *a;
// 	t_stack *b;
// 	//t_stackdata stack;
// 	int i;

// 	a = NULL;
// 	b = NULL;
// 	// if (argc > 1)
// 	// 	stack.length = stack_init(&a, argc, argv);
// 	// // Assigns index for each node
// 	// assign_index(stack, a);
// 	// if (stack.length == 3)
// 	// 	sort_three(&a);
// 	// else if (stack.length != 3 && stack.length <= 10)
// 	// 	sort_ten(&a, &b);
// 	// else if (stack.length > 10)
// 	// 	sort_n(&stack, &a, &b);
// 	// pb(&a, &b);
// 	// pb(&a, &b);
// 	// pb(&a, &b);
// 	// rrb(&b, 0);

// 	if (argc > 1)
// 	{
// 		i = 1;
// 		while(i < argc)
// 		{
// 			// Create node
// 			t_stack *node = newnode(ft_atoi(argv[i]));
// 			// Add node to linked list
// 			ft_addnode(&a, node);
// 			i++;
// 		}

// 		i = 1;
// 		while(i < argc)
// 		{
// 			// Create node
// 			t_stack *node = newnode(ft_atoi(argv[i]));
// 			// Add node to linked list
// 			ft_addnode(&b, node);
// 			i++;
// 		}
// 	}
// 	rra(&a, 0);
// 	rrb(&b, 0);
// 	print_stacks(a, b);
// 	print_stackbackwards(a, b);

// 	free_stacks(a, b);
// }
