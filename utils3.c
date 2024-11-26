/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkeirouz <kkeirouz@student..fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 09:30:24 by kkeirouz          #+#    #+#             */
/*   Updated: 2024/11/10 10:15:51 by kkeirouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	final_move(t_list **a)
{
	int	i;

	i = find_index(*a, lst_min(*a));
	if (i < stack_size(*a) / 2)
	{
		while (i-- > 0)
			ra(a, 1);
	}
	else
	{
		while (i++ < stack_size(*a))
			rra(a, 1);
	}
}

t_list	*node_to_pushb(t_list *a, t_list *b)
{
	int		price;
	t_list	*to_push;

	set_cost_of_push(a, b);
	price = INT_MAX;
	to_push = NULL;
	while (b)
	{
		if (b->price < price)
		{
			price = b->price;
			to_push = b;
		}
		b = b->next;
	}
	return (to_push);
}

t_list	*node_to_push(t_list *a, t_list *b)
{
	int		price;
	t_list	*to_push;

	set_cost_of_push(a, b);
	price = INT_MAX;
	to_push = NULL;
	while (a)
	{
		if (a->price < price)
		{
			price = a->price;
			to_push = a;
		}
		a = a->next;
	}
	return (to_push);
}

static void	set_cost_of_push_part2(t_list *a, t_list *b)
{
	(void) a;
	while (b)
	{
		if (b->median == b->target->median)
		{
			if (b->cost >= b->target->cost)
				b->price = b->cost;
			else
				b->price = b->target->cost;
		}
		else
			b->price = b->cost + b->target->cost;
		b = b->next;
	}
}

void	set_cost_of_push(t_list *a, t_list *b)
{
	init_list(a, b);
	while (a)
	{
		if (a->median == 1)
			a->price = a->index;
		else if (a->median == 2)
			a->price = stack_size(a) - a->index;
		if (a->target->median == 1)
			a->price = a->price + a->target->index;
		else if (a->target->median == 2)
			a->price = a->price + stack_size(b) - a->target->index;
		a = a->next;
	}
	set_cost_of_push_part2(a, b);
}
