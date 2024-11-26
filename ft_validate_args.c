/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_args.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkeirouz <kkeirouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:49:49 by kkeirouz          #+#    #+#             */
/*   Updated: 2024/11/12 14:18:04 by kkeirouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_error(long *values)
{
	write (1, "Error\n", 6);
	free(values);
	return (0);
}

int	ft_validate_args(int argc, char **argv)
{
	int		i;
	int		j;
	long	*values;

	i = 0;
	values = malloc((argc) * sizeof(long));
	if (!values)
		return (0);
	while (i < argc)
	{
		if (!is_numbers(argv[i]))
			return (ft_error(values));
		j = -1;
		values[i] = ft_atol(argv[i]);
		if (values[i] < INT_MIN || values[i] > INT_MAX)
			return (ft_error(values));
		while (++j < i)
		{
			if (values[i] == values[j])
				return (ft_error(values));
		}
		i++;
	}
	free(values);
	return (1);
}

void	free_list(t_list **lst)
{
	t_list	*current;
	t_list	*next;

	if (!lst || !*lst)
		return ;
	current = *lst;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*lst = NULL;
}
