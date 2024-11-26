/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkeirouz <kkeirouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 19:21:58 by kkeirouz          #+#    #+#             */
/*   Updated: 2024/10/22 16:16:31 by kkeirouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_list **lst)
{
	t_list	*head;
	t_list	*tail;

	if (*lst == NULL || (*lst)->next == NULL)
		return ;
	head = *lst;
	*lst = head->next;
	head->next = NULL;
	tail = *lst;
	while (tail->next != NULL)
		tail = tail->next;
	tail->next = head;
}

void	ra(t_list **a, int prnt)
{
	if (*a != NULL && (*a)->next != NULL)
	{
		rotate(a);
		if (prnt)
			write(1, "ra\n", 3);
	}
}

void	rb(t_list **b, int prnt)
{
	if (*b != NULL && (*b)->next != NULL)
	{
		rotate(b);
		if (prnt)
			write(1, "rb\n", 3);
	}
}

void	rr(t_list **a, t_list **b)
{
	if (*a != NULL && (*a)->next != NULL && *b != NULL && (*b)->next != NULL)
	{
		ra(a, 0);
		rb(b, 0);
		write (1, "rr\n", 3);
	}
}
