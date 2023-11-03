/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:27:25 by agan              #+#    #+#             */
/*   Updated: 2023/10/30 12:27:26 by agan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
}	t_stack;

/* List helper functions */
t_stack	*newnode(int content);
t_stack	*ft_lastnode(t_stack *lst);
void	ft_addnode(t_stack **lst, t_stack *new);
int		ft_stacksize(t_stack *lst);
t_stack	*ft_secondlast(t_stack *lst);

/* Push_swap instructions */
void 	ft_sa(t_stack *a, int repeat);
void 	ft_sb(t_stack *b, int repeat);
void 	ft_ss(t_stack *a, t_stack *b);
void 	ft_pa(t_stack **a, t_stack **b);
void 	ft_pb(t_stack **a, t_stack **b);
void 	ft_ra(t_stack **a, int repeat);
void 	ft_rb(t_stack **b, int repeat);
void	ft_rr(t_stack **a, t_stack **b);
void	ft_rra(t_stack **a, int repeat);
void	ft_rrb(t_stack **b, int repeat);
void	ft_rrr(t_stack **a, t_stack **b);

/* Push swap utils */
void	print_list(t_stack *list);
void	print_stacks(t_stack *a, t_stack *b);
void	free_stacks(t_stack *a, t_stack *b);

# endif
