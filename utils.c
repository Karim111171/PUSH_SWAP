/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkeirouz <kkeirouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 15:55:40 by kkeirouz          #+#    #+#             */
/*   Updated: 2024/10/26 18:24:44 by kkeirouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r');
}

int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

int	is_numbers(const char *str)
{
	int	i;

	i = 0;
	if (*str == '\0' || (ft_isspace(*str) && *(str +1) == '\0'))
		return (0);
	while (*str)
	{
		if (i > 0 && !ft_isspace(*str))
			return (0);
		if (ft_isspace(*str))
			str++;
		if (*str == '-' || *str == '+')
			str++;
		if (!ft_isdigit(*str))
			return (0);
		i = 0;
		while (ft_isdigit(*str))
		{
			i++;
			str++;
		}
		while (ft_isspace(*str))
			str++;
	}
	return (1);
}

int	lst_min(t_list *a)
{
	int	i;

	i = a->x;
	while (a)
	{
		if (a->x < i)
			i = a->x;
		a = a->next;
	}
	return (i);
}

int	find_index(t_list *a, int nbr)
{
	int	i;

	i = 0;
	while (a->x != nbr)
	{
		i++;
		a = a->next;
	}
	return (i);
}
