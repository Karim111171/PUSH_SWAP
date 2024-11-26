/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkeirouz <kkeirouz@student..fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 19:00:30 by kkeirouz          #+#    #+#             */
/*   Updated: 2024/11/06 15:59:20 by kkeirouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_target_a(t_list *a, t_list *b)
{
	t_list	*current_b;
	t_list	*target;
	int		match;

	set_median(a, b);
	while (a)
	{
		current_b = b;
		match = INT_MIN;
		while (current_b)
		{
			if ((a->x > current_b->x) && (match < current_b->x))
			{
				match = current_b->x;
				target = current_b;
			}
			current_b = current_b->next;
		}
		if (match == INT_MIN)
			a->target = find_highest(b);
		else
			a->target = target;
		a = a->next;
	}
}

void	set_target_b(t_list *a, t_list *b)
{
	t_list	*current_a;
	t_list	*target;
	int		match;

	set_median(a, b);
	while (b)
	{
		current_a = a;
		match = INT_MAX;
		while (current_a)
		{
			if ((b->x < current_a->x) && (match > current_a->x))
			{
				match = current_a->x;
				target = current_a;
			}
			current_a = current_a->next;
		}
		if (match == INT_MAX)
			b->target = find_smallest(a);
		else
			b->target = target;
		b = b->next;
	}
}

t_list	*find_highest(t_list *lst)
{
	int		highest;
	t_list	*highest_node;

	highest_node = NULL;
	if (lst == NULL)
		return (NULL);
	highest = INT_MIN;
	while (lst)
	{
		if (lst->x > highest)
		{
			highest = lst->x;
			highest_node = lst;
		}
		lst = lst->next;
	}
	return (highest_node);
}

int	lst_max(t_list *a)
{
	int	i;

	i = a->x;
	while (a)
	{
		if (a->x > i)
			i = a->x;
		a = a->next;
	}
	return (i);
}

t_list	*find_smallest(t_list *lst)
{
	int		smallest;
	t_list	*smallest_node;

	smallest_node = NULL;
	if (lst == NULL)
		return (NULL);
	smallest = INT_MAX;
	while (lst)
	{
		if (lst->x < smallest)
		{
			smallest = lst->x;
			smallest_node = lst;
		}
		lst = lst->next;
	}
	return (smallest_node);
}
