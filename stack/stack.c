/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:50:37 by agan              #+#    #+#             */
/*   Updated: 2023/11/02 17:05:50 by agan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Creates a new node
t_stack	*newnode(int content)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

// Add note to back to list
void	ft_addnode(t_stack **lst, t_stack *new)
{
	if (lst && new)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			new->prev = ft_lastnode(*lst);
			ft_lastnode(*lst)->next = new;
		}
	}
}

// Returns last node in linked list
t_stack	*ft_lastnode(t_stack *lst)
{
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

// Returns second last node in linked list
t_stack	*ft_secondlast(t_stack *lst)
{
	while (lst)
	{
		if (!lst->next->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

// Returns list size
int	ft_stacksize(t_stack *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}
