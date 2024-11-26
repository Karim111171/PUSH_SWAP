/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkeirouz <kkeirouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 08:53:09 by kkeirouz          #+#    #+#             */
/*   Updated: 2024/11/10 10:13:23 by kkeirouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdarg.h>
# include <limits.h>

typedef struct list
{
	int			x;
	int			index;
	int			cost;
	int			price;
	int			median;
	struct list	*target;
	struct list	*next;
}	t_list;

char	**ft_split(char const *s, char c);
t_list	*ft_lstnew(int content);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_atoi(const char *str);
long	ft_atol(const char *str);
void	ft_print_list(t_list *lst);
int		ft_count_args(char **argv);
t_list	*ft_create_list(int argc, char **argv);
void	ft_free_argv(char **argv);
int		ft_validate_args(int argc, char **argv);
char	**ft_process_single_argument(const char *arg);
int		ft_printf(const char *format, ...);
int		ft_putnbr(int n);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putunbr(unsigned int n);
int		ft_puthexa(unsigned long n, int uppercase);
int		ft_putptr(void *ptr);
int		handle_format(char specifier, va_list args);
void	swap(t_list **lst);
void	sa(t_list **a, int prnt);
void	sb(t_list **b, int prnt);
void	ss(t_list **a, t_list **b);
void	pa(t_list **a, t_list **b);
void	pb(t_list **a, t_list **b);
void	rotate(t_list **lst);
void	ra(t_list **a, int prnt);
void	rb(t_list **b, int prnt);
void	rr(t_list **a, t_list **b);
void	reverse_rotate(t_list **lst);
void	rra(t_list **a, int prnt);
void	rrb(t_list **b, int prnt);
void	rrr(t_list **a, t_list **b);
int		stack_size(t_list *lst);
void	sort_three(t_list **lst);
t_list	*find_highest(t_list *lst);
int		is_sorted(t_list *lst);
void	small_sort(t_list **a);
int		lst_max(t_list *a);
int		lst_min(t_list *b);
int		ft_isspace(char c);
int		ft_isdigit(char c);
int		is_numbers(const char *str);
char	*process(int ac, char **av);
char	*build(int ac, char **av, char *d);
char	*avmalloc(int ac, char **av);
int		count(char *s, char c);
void	handle_input(int argc, char **argv, t_list **a);
int		find_index(t_list *a, int nbr);
t_list	*find_smallest(t_list *lst);
t_list	*find_node(t_list *lst, int x);
int		ft_strlen(const char *str);
void	free_list(t_list **lst);
void	set_index(t_list *a, t_list *b);
void	set_cost(t_list *a, t_list *b);
void	set_median(t_list *a, t_list *b);
void	init_list(t_list *a, t_list *b);
void	set_target_a(t_list *a, t_list *b);
void	set_target_b(t_list *a, t_list *b);
t_list	*node_to_push(t_list *a, t_list *b);
void	sort_more(t_list **a, t_list **b);
void	set_cost_of_push(t_list *a, t_list *b);
void	more1(t_list **a, t_list **b);
t_list	*node_to_pushb(t_list *a, t_list *b);
void	final_move(t_list **a);
void	sort_five(t_list **a, t_list **b);
void	set_right_index(t_list *a, t_list *b);

#endif
