/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 16:00:10 by agan              #+#    #+#             */
/*   Updated: 2023/11/11 16:46:35 by agan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

void do_commands(char *buf, t_stack **a, t_stack **b)
{
	if (ft_strncmp(buf, "sa\n", 3) == 0)
		sa(a);
	else if (ft_strncmp(buf, "sb\n", 3) == 0)
		sb(b);
	else if (ft_strncmp(buf, "ss\n", 3) == 0)
		ss(a, b);
	else if (ft_strncmp(buf, "pa\n", 3) == 0)
		pa(a, b);
	else if (ft_strncmp(buf, "pb\n", 3) == 0)
		pb(a, b);
	else if (ft_strncmp(buf, "ra\n", 3) == 0)
		ra(a);
	else if (ft_strncmp(buf, "rb\n", 3) == 0)
		rb(b);
	else if (ft_strncmp(buf, "rra\n", 4) == 0)
		rra(a);
	else if (ft_strncmp(buf, "rrb\n", 4) == 0)
		rrb(b);
	else if (ft_strncmp(buf, "rrr\n", 4) == 0)
		rrr(a, b);
	else if (ft_strncmp(buf, "rr\n", 3) == 0)
		rr(a, b);
}

int checker(t_stack **a, t_stack **b)
{
	char *buf;

	while (buf)
	{
		buf = get_next_line(STDIN_FILENO);
		if (buf)
			do_commands(buf, a, b);
		free(buf);
	}
	if (is_sorted(*a) && !(*b))
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;
	t_data *stack;

	stack = malloc(sizeof(t_data));
	a = NULL;
	b = NULL;
	if (argc <= 1)
		return (0);
	stack->length = stack_init(stack, &a, argc, argv);
	checker(&a, &b);
	free_stacks(stack, a, b);
}
