/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_reverse.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonoval <akonoval@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 13:53:24 by akonoval          #+#    #+#             */
/*   Updated: 2026/05/30 13:54:14 by akonoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverce_rotate_stack(t_stack *stack)
{
	t_node	*old_bottom;

	if (!stack || stack->size < 2)
		return ;
	old_bottom = stack->bottom;
	stack->bottom = old_bottom->prev;
	stack->bottom->next = NULL;
	old_bottom->next = stack->top;
	stack->top->prev = old_bottom;
	old_bottom->prev = NULL;
	stack->top = old_bottom;
}

void	rra(t_stack *stack_a)
{
	reverce_rotate_stack(stack_a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack *stack_b)
{
	reverce_rotate_stack(stack_b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	reverce_rotate_stack(stack_a);
	reverce_rotate_stack(stack_b);
	write(1, "rrr\n", 1);
}
