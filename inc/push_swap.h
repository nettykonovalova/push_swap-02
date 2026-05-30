/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonoval <akonoval@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 17:55:03 by akonoval          #+#    #+#             */
/*   Updated: 2026/05/30 16:53:34 by akonoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stuck
{
	t_node	*top;
	t_node	*bottom;
	int		size;
}	t_stack;

void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);
void	ra(t_stack *stack_a);
void	rb(t_stack *stack_b);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rra(t_stack *stack_a);
void	rrb(t_stack *stack_b);
void	rrr(t_stack *stack_a, t_stack *stack_b);
int		ft_atoi_ps(const char *str, int *result);
int		has_duplicate(t_stack *stack, int value);
void	assign_indices(t_stack *stack);
int		is_sorted(t_stack *stack);
void	sort_three(t_stack *a);
void	sort_four_five(t_stack *a, t_stack *b);
void	radix_sort(t_stack *a, t_stack *b);
void	route_sorting(t_stack *stack_a, t_stack *stack_b);

t_node	*lst_new_node(int value);
void	lst_add_bottom(t_stack *stack, t_node *new_node);
void	lst_clear(t_stack *stack);
void	print_stacks(t_stack *stack_a, t_stack *stack_b);

#endif