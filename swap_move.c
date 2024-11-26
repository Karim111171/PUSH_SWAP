/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkeirouz <kkeirouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 18:01:44 by kkeirouz          #+#    #+#             */
/*   Updated: 2024/10/22 16:26:57 by kkeirouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **lst)
{
	t_list	*temp;

	if (!lst || !*lst || !(*lst)->next)
		return ;
	temp = (*lst)->next;
	(*lst)->next = temp->next;
	temp->next = *lst;
	*lst = temp;
}

void	sa(t_list **a, int prnt)
{
	if (*a != NULL && (*a)->next != NULL)
	{
		swap(a);
		if (prnt)
			write (1, "sa\n", 3);
	}
}

void	sb(t_list **b, int prnt)
{
	if (*b != NULL && (*b)->next != NULL)
	{
		swap(b);
		if (prnt)
			write (1, "sb\n", 3);
	}
}

void	ss(t_list **a, t_list **b)
{
	if (*a != NULL && (*a)->next != NULL && *b != NULL && (*b)->next != NULL)
	{
		sa(a, 0);
		sb(b, 0);
		write (1, "ss\n", 3);
	}
}
