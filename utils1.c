/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkeirouz <kkeirouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 14:49:12 by kkeirouz          #+#    #+#             */
/*   Updated: 2024/11/10 10:15:03 by kkeirouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_index(t_list *a, t_list *b)
{
	int	j;

	if (a)
	{
		j = 0;
		while (a)
		{
			a->index = j;
			a = a->next;
			j++;
		}
	}
	if (b)
	{
		j = 0;
		while (b)
		{
			b->index = j;
			b = b->next;
			j++;
		}
	}
}

void	set_median(t_list *a, t_list *b)
{
	set_index(a, b);
	if (a)
	{
		while (a)
		{
			if (a->index > stack_size(a) / 2)
				a->median = 2;
			else
				a->median = 1;
			a = a->next;
		}
	}
	if (b)
	{
		while (b)
		{
			if (b->index > stack_size(b) / 2)
				b->median = 2;
			else
				b->median = 1;
			b = b->next;
		}
	}
}

void	set_cost(t_list *a, t_list *b)
{
	set_index(a, b);
	set_median(a, b);
	while (a)
	{
		a->cost = 0;
		if (a->median == 1)
			a->cost = a->index;
		if (a->median == 2)
			a->cost = stack_size(a) - a->index;
		a = a->next;
	}
	while (b)
	{
		b->cost = 0;
		if (b->median == 1)
			b->cost = b->index;
		if (b->median == 2)
			b->cost = stack_size(b) - b->index;
		b = b->next;
	}
}

void	init_list(t_list *a, t_list *b)
{
	set_cost(a, b);
	set_target_a(a, b);
	set_target_b(a, b);
}
