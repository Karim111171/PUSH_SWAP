/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkeirouz <kkeirouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 08:23:34 by kkeirouz          #+#    #+#             */
/*   Updated: 2024/11/12 14:09:32 by kkeirouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (0);
	handle_input(argc, argv, &a);
	if(is_sorted(a))
	{
		free_list(&a);
		exit(1);
	}
	if (stack_size(a) <= 3)
		sort_three(&a);
	else if (stack_size(a) <= 5)
		sort_five(&a, &b);
	else if (!is_sorted(a))
		sort_more(&a, &b);
	free_list(&a);
	return (0);
}
