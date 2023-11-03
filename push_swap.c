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

// Create data structure stacks a and b
// - Order numbers in a linked list

void stack_init(t_stack **a, t_stack **b)
{

}

int	main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;
	int i;
	a = NULL;
	b = NULL;
	if (argc > 1)
	{
		i = 1;
		while(i < argc)
		{
			// Create node
			t_stack *node = newnode(ft_atoi(argv[i]));
			// Add node to linked list
			ft_addnode(&a, node);
			i++;
		}

		i = 1;
		while(i < argc)
		{
			// Create node
			t_stack *node = newnode(ft_atoi(argv[i]) + 1);
			// Add node to linked list
			ft_addnode(&b, node);
			i++;
		}
	}
	print_stacks(a, b);
	ft_rrb(&b, 0);
	ft_rrb(&b, 0);
	print_stacks(a, b);
	free_stacks(a, b);
}
