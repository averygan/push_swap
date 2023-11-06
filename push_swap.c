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
	t_stackdata stack;

	a = NULL;
	b = NULL;
	if (argc > 1)
		stack.length = stack_init(&a, argc, argv);
	// Assigns index for each node
	assign_index(stack, a);
	if (stack.length == 3)
		sort_three(&a);
	sort_n(&stack, &a, &b);
	print_stacks(a, b);
	free_stacks(a, b);
}
