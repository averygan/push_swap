/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 13:57:01 by agan              #+#    #+#             */
/*   Updated: 2023/11/06 15:52:09 by agan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Checks argument, runs error checker and creates linked list
int	stack_init(t_data *stack, t_stack **a, int argc, char **argv)
{
	int		i;
	char	**av;
	t_stack	*node;
	int		counter;

	counter = 0;
	i = 0;
	if (argc == 2)
		av = ft_split(argv[1], ' ');
	else
		av = argv + 1;
	error_checker(stack, argc, av);
	while (av[i])
	{
		node = newnode(ft_atol(stack, av[i], argc, av));
		ft_addnode(a, node);
		i++;
		counter++;
	}
	if (argc == 2)
		ft_free(av);
	error_dup(stack, a);
	return (ft_stacksize(*a));
}

// Checks for duplicate error
void	error_dup(t_data *stack, t_stack **a)
{
	t_stack	*curr;
	t_stack	*num;

	curr = *a;
	while (curr)
	{
		num = curr->next;
		while (num)
		{
			if (num->content == curr->content)
				ft_error(stack, a, 0, NULL);
			num = num->next;
		}
		curr = curr->next;
	}
}

// Error checker to check if all numbers are valid
// Checks if numbers are valid
void	error_checker(t_data *stack, int argc, char **av)
{
	int		i;

	i = -1;
	if (!av[0] && argc == 2)
		ft_error(stack, NULL, argc, av);
	while (av[++i])
	{
		if (av[i][0] == '\0')
			ft_error(stack, NULL, argc, av);
		ft_atol(stack, av[i], argc, av);
	}
}

// Free all allocated memory
// Output error
void	ft_error(t_data *stack, t_stack **a, int argc, char **av)
{
	free(stack);
	if (argc == 2)
		ft_free(av);
	if (a)
		free_stack(*a);
	write(2, "Error\n", 6);
	exit(0);
}

// Atol function and returns error if invalid integer
int	ft_atol(t_data *stack, char *num, int argc, char **av)
{
	long	res;
	int		i;
	int		sign;

	res = 0;
	i = 0;
	sign = 1;
	if (num[0] == '+' || num[0] == '-')
	{
		if (num[0] == '-')
			sign *= -1;
		i++;
		if (!ft_isdigit(num[i]))
			ft_error(stack, NULL, argc, av);
	}
	while (num[i] && ft_isdigit(num[i]))
	{
		res = res * 10 + num[i] - '0';
		i++;
	}
	if (num[i] != '\0')
		ft_error(stack, NULL, argc, av);
	if ((res * sign) > 2147483647 || (res * sign) < -2147483647)
		ft_error(stack, NULL, argc, av);
	return ((int)(res * sign));
}
