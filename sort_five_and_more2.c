/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five_and_more2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkeirouz <kkeirouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 09:38:08 by kkeirouz          #+#    #+#             */
/*   Updated: 2024/11/10 09:48:52 by kkeirouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	more1(t_list **a, t_list **b)
{
	int		size;

	size = stack_size(*b);
	while (size > 0)
	{
		set_target_b(*a, *b);
		while ((*a)->x != (*b)->target->x)
		{
			if ((*b)->target->median == 1)
				ra(a, 1);
			else if ((*b)->target->median == 2)
				rra(a, 1);
		}
		pa(a, b);
		size--;
	}
}
