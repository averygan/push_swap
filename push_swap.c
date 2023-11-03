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
// ERROR CHECKER
// - Argument larger than int
// - Non integer arguments
// - Check duplicates

// Create stacks a and b
// Runs stack init to create stack a as linked list
int	main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;
	a = NULL;
	b = NULL;
	if (argc > 1)
		stack_init(&a, argc, argv);
	print_stacks(a, b);
	free_stacks(a, b);
}
