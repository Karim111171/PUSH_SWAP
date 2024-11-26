/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five_and_more.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkeirouz <kkeirouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:22:32 by kkeirouz          #+#    #+#             */
/*   Updated: 2024/11/10 10:36:26 by kkeirouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_sort_aux1(t_list **a, t_list **b, int *i, int *j)
{
	int	k;

	if (*i < *j)
	{
		k = *j - *i;
		while ((*i)--)
			rr(a, b);
		while (k--)
			rb(b, 1);
	}
	else
	{
		k = *i - *j;
		while ((*j)--)
			rr(a, b);
		while (k--)
			ra(a, 1);
	}
}

static void	ft_sort_aux2(t_list **a, t_list **b, int *i, int *j)
{
	int	k;

	if ((stack_size(*a) - *i < stack_size(*b) - *j))
	{
		k = ((stack_size(*b) - *j) - (stack_size(*a) - *i));
		while ((*i)++ < stack_size(*a))
			rrr(a, b);
		while (k--)
			rrb(b, 1);
	}
	else
	{
		k = ((stack_size(*a) - *i) - (stack_size(*b) - *j));
		while ((*j)++ < stack_size(*b))
			rrr(a, b);
		while (k--)
			rra(a, 1);
	}
}

static void	ft_sort_aux3(t_list **a, t_list **b, int *i, int *j)
{
	if (*i < stack_size(*a) / 2)
	{
		while ((*i)--)
			ra(a, 1);
	}
	else
	{
		while ((*i)++ < stack_size(*a))
			rra(a, 1);
	}
	if (*j < stack_size(*b) / 2)
	{
		while ((*j)--)
			rb(b, 1);
	}
	else
	{
		while ((*j)++ < stack_size(*b))
			rrb(b, 1);
	}
}

static void	sort_more1(t_list **a, t_list **b, int *i, int *j)
{
	int		size;
	t_list	*temp;

	size = stack_size(*a);
	while (size > 3)
	{
		temp = node_to_push(*a, *b);
		*i = find_index (*a, temp->x);
		*j = find_index (*b, temp->target->x);
		if (temp->median == temp->target->median && temp->median == 1)
			ft_sort_aux1(a, b, i, j);
		if (temp->median == temp->target->median && temp->median == 2)
			ft_sort_aux2(a, b, i, j);
		if (temp->median != temp->target->median)
			ft_sort_aux3(a, b, i, j);
		pb(a, b);
		size--;
	}
}

void	sort_more(t_list **a, t_list **b)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	pb(a, b);
	pb(a, b);
	sort_more1(a, b, &i, &j);
	sort_three(a);
	more1(a, b);
	if (!is_sorted(*a))
		final_move(a);
}
