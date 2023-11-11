/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 13:57:01 by agan              #+#    #+#             */
/*   Updated: 2023/11/11 16:47:11 by agan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

// Checks argument, runs error checker and creates linked list
int	stack_init(t_data *stack, t_stack **a, int argc, char **argv)
{
	int		i;
	char	**av;
	t_stack	*node;
	int counter = 0;

	i = 0;
	if (argc == 2)
		av = ft_split(argv[1], ' ');
	else
		av = argv + 1;
	error_checker(stack, a, av, 0);
	while (av[i])
	{
		node = newnode(ft_atol(stack, av[i]));
		ft_addnode(a, node);
		i++;
		counter++;
	}
	error_checker(stack, a, av, 1);
	if (argc == 2)
		ft_free(av);
	return (ft_stacksize(*a));
}

// Error checker to check if all numbers are valid
// Check == 0 checks if numbers are valid
// Check == 1 checks for duplicated numbers
void	error_checker(t_data *stack, t_stack **a, char **av, int check)
{
	int		i;
	t_stack	*curr;
	t_stack	*num;

	i = -1;
	if (check == 0)
	{
		while (av[++i])
		{
			if (av[i][0] == '\0')
				ft_error(stack, NULL, 1);
			ft_atol(stack, av[i]);
		}
	}
	else
	{
		curr = *a;
		while (curr)
		{
			num = curr->next;
			while (num)
			{
				if (num->content == curr->content)
					ft_error(stack, a, 0);
				num = num->next;
			}
			curr = curr->next;
		}
	}
}

// Output error
void	ft_error(t_data *stack, t_stack **a, int num)
{
	free(stack);
	if (num == 0)
		free_stack(*a);
	write(2, "Error\n", 6);
	exit(1);
}

// Atol function and returns error if invalid integer
int	ft_atol(t_data *stack, char *num)
{
	long	res;
	int		i;
	int		sign;

	res = 0;
	i = 0;
	sign = 1;
	while (num[i] == ' ')
		i++;
	if (num[i] == '+' || num[i] == '-')
	{
		if (num[i] == '-')
			sign *= -1;
		i++;
	}
	while (num[i] && ft_isdigit(num[i]))
	{
		res = res * 10 + num[i] - '0';
		i++;
	}
	if (num[i] != '\0')
		ft_error(stack, NULL, 1);
	if ((res * sign) > 2147483647 || (res * sign) < -2147483647)
		ft_error(stack, NULL, 1);
	return ((int)(res * sign));
}