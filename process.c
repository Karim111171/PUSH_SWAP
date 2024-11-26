/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkeirouz <kkeirouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:06:17 by kkeirouz          #+#    #+#             */
/*   Updated: 2024/11/10 11:13:21 by kkeirouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*avmalloc(int ac, char **av)
{
	char	*d;
	int		i;
	int		g;

	g = 1;
	i = 0;
	while (av[g])
	{
		i += ft_strlen(av[g]);
		g++;
	}
	d = malloc((i + ac) * sizeof(char));
	if (d == NULL)
		return (NULL);
	return (d);
}

char	*build(int ac, char **av, char *d)
{
	int	i;
	int	j;
	int	k;

	k = 0;
	(void)ac;
	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			d[k] = av[i][j];
			j++;
			k++;
		}
		d[k] = ' ';
		k++;
		i++;
	}
	d[--k] = '\0';
	return (d);
}

char	*process(int ac, char **av)
{
	char	*d;

	d = avmalloc(ac, av);
	d = build(ac, av, d);
	return (d);
}
