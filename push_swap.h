/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafilali <yafilali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 00:53:21 by yafilali          #+#    #+#             */
/*   Updated: 2024/07/28 01:17:41 by yafilali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INT_MIN -2147483648
# define INT_MAX 2147483647
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_data
{
	char	*allarg;
}			t_data;

typedef struct s_holder
{
	int		*sorted;
	int		count;
}			t_holder;

typedef struct s_stack
{
	int		*array;
	int		count;
	int		max;
	int		min;

}			t_stack;

char		**ft_split(char const *s, char c);
int			str_len(char *string);
void		ft_putendl(char *string, int fd);
void		ft_error(void);
void		ft_free(char **args);
int			ft_num(int i);
int			check_signes(char *string);
int			check_validate(char *string);
void		check_args_is_valid(char **args);
int			ft_word_count(char const *s, char c);
int			check_duplicate(t_stack *stack);
void		get_args(t_data *data, int c, char **v);
t_stack		get_stack(char *args);
t_stack		get_main_stack(t_data *data);
void		str_cat(char *string1, char *string2);
long		at_oi(char *s);
void		check_min_max(int counter, char **args);
t_stack		clone_stack(t_stack stack_a);
t_holder	make_holder(t_stack *stack_a);

void		swap(int *array);
void		rotate(t_stack *stack);
void		reverse_rotate(t_stack *stack);
void		push(t_stack *stack1, t_stack *stack2);
void		sa(t_stack *stack_a);
void		sb(t_stack *stack_b);
void		ra(t_stack *stack_a);
void		rb(t_stack *stack_b);
void		rra(t_stack *stack_a);
void		rrb(t_stack *stack_b);
void		ss(t_stack *stack_a, t_stack *stack_b);
void		rr(t_stack *stack_a, t_stack *stack_b);
void		rrr(t_stack *stack_a, t_stack *stack_b);
void		pa(t_stack *stack_a, t_stack *stack_b);
void		pb(t_stack *stack_a, t_stack *stack_b);
void		sort_3(t_stack *stack);
void		sort_5(t_stack *stack_a, t_stack *stack_b);
void		big_sorting(t_stack *stack_a, t_stack *stack_b, int range);
void		find_min(t_stack *stack);
void		find_max(t_stack *stack);
int			find_p(int nb, int *array, int len);
int			find_max_p(t_stack *stack);
int			get_sorted_index(t_holder holder, int val);
int			find_index(t_stack *a, t_holder holder, int index, int range);
int			find_min_p(t_stack *stack);
int			stack_is_sorted(t_stack *stack);
void		bubble_sort(t_holder *holder);
void		push_to_stack_a(t_stack *stack_a, t_stack *stack_b);

#endif