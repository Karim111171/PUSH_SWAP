/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_move.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkeirouz <kkeirouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 19:38:54 by kkeirouz          #+#    #+#             */
/*   Updated: 2024/10/22 16:10:53 by kkeirouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_list **lst)
{
	t_list	*prev;
	t_list	*tail;

	if (*lst == NULL || (*lst)->next == NULL)
		return ;
	tail = *lst;
	prev = NULL;
	while (tail->next != NULL)
	{
		prev = tail;
		tail = tail->next;
	}
	prev->next = NULL;
	tail->next = *lst;
	*lst = tail;
}

void	rra(t_list **a, int prnt)
{
	if (*a != NULL && (*a)->next != NULL)
	{
		reverse_rotate(a);
		if (prnt)
			write(1, "rra\n", 4);
	}
}

void	rrb(t_list **b, int prnt)
{
	if (*b != NULL && (*b)->next != NULL)
	{
		reverse_rotate(b);
		if (prnt)
			write(1, "rrb\n", 4);
	}
}

void	rrr(t_list **a, t_list **b)
{
	if (*a != NULL && (*a)->next != NULL && *b != NULL && (*b)->next != NULL)
	{
		rra(a, 0);
		rrb(b, 0);
		write (1, "rrr\n", 4);
	}
}
