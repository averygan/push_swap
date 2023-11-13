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

#include "../push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_data	*stack;

	stack = malloc(sizeof(t_data));
	if (!stack)
		return (-1);
	a = NULL;
	b = NULL;
	if (argc > 1)
		stack->length = stack_init(stack, &a, argc, argv);
	if (is_sorted(a))
	{
		free(stack);
		free_stack(a);
		return (0);
	}
	assign_index(stack, a);
	if (stack->length <= 10)
		sort_ten(&a, &b);
	else if (stack->length > 10)
		sort_n(stack, &a, &b);
	free_stacks(stack, a, b);
}
