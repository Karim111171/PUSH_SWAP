/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkeirouz <kkeirouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:04:19 by kkeirouz          #+#    #+#             */
/*   Updated: 2024/11/10 14:09:08 by kkeirouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_process_arguments(char **argv, t_list **a)
{
	int	i;

	if (!argv)
		exit(1);
	i = ft_count_args(argv);
	if (!ft_validate_args(i, argv))
	{
		ft_free_argv(argv);
		exit(1);
	}
	*a = ft_create_list(i, argv);
	ft_free_argv(argv);
}

void	handle_input(int argc, char **argv, t_list **a)
{
	char	*av;

	av = NULL;
	if ((argc == 2 && argv[1][0] == '\0'))
	{
		write (1, "Error\n", 6);
		exit(1);
		return ;
	}	
	if (argc == 2)
	{
		argv = ft_process_single_argument(argv[1]);
		ft_process_arguments(argv, a);
	}
	else
	{
		av = process(argc, argv);
		*argv = av;
		argv = ft_process_single_argument(*argv);
		free(av);
		ft_process_arguments(argv, a);
	}
}

char	**ft_process_single_argument(const char *arg)
{
	char	**split_argv;

	split_argv = ft_split(arg, ' ');
	if (!split_argv)
	{
		ft_printf("Error\n");
		return (NULL);
	}
	return (split_argv);
}
