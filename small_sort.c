/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkeirouz <kkeirouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 09:02:47 by kkeirouz          #+#    #+#             */
/*   Updated: 2024/11/10 10:16:47 by kkeirouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_list **lst)
{
	t_list	*highest;

	highest = find_highest(*lst);
	if (*lst == highest)
	{
		ra(lst, 1);
	}
	else if ((*lst)->next == highest)
	{
		rra(lst, 1);
	}
	if ((*lst)->next != NULL && (*lst)->x > (*lst)->next->x)
	{			
		sa(lst, 1);
	}
}

void	sort_five(t_list **a, t_list **b)
{
	int	size;

	size = stack_size(*a);
	while (size > 3)
	{
		pb(a, b);
		size--;
	}
	sort_three(a);
	more1(a, b);
	if (!is_sorted(*a))
		final_move(a);
}

t_list	*find_node(t_list *lst, int x)
{
	t_list	*find_node;

	find_node = NULL;
	if (lst == NULL)
		return (NULL);
	while (lst)
	{
		if (lst->x == x)
		{
			find_node = lst;
		}
		lst = lst->next;
	}
	return (find_node);
}
