/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkeirouz <kkeirouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:44:44 by kkeirouz          #+#    #+#             */
/*   Updated: 2024/10/30 18:32:46 by kkeirouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_create_list(int argc, char **argv)
{
	t_list	*a;
	int		i;

	i = 0;
	a = NULL;
	while (i < argc)
	{
		ft_lstadd_back(&a, ft_lstnew(ft_atoi(argv[i])));
		i++;
	}
	return (a);
}

void	ft_print_list(t_list *lst)
{
	while (lst != NULL)
	{
		ft_printf("%d ", lst->x);
		lst = lst->next;
	}
}

int	is_sorted(t_list *lst)
{
	while (lst && lst->next)
	{
		if (lst->x > lst->next->x)
			return (0);
		lst = lst->next;
	}
	return (1);
}

t_list	*ft_lstnew(int content)
{
	t_list	*new_elem;

	new_elem = (t_list *)malloc(sizeof(t_list));
	if (new_elem == NULL)
		return (NULL);
	new_elem->x = content;
	new_elem->next = NULL;
	return (new_elem);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current;

	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		current = *lst;
		while (current->next != NULL)
			current = current->next;
		current->next = new;
	}
}
