/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 16:55:39 by agan              #+#    #+#             */
/*   Updated: 2023/11/11 16:55:40 by agan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

// Function to check if stack is sorted
int	is_sorted(t_stack *a)
{
	t_stack	*curr;

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
