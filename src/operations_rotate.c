/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonoval <akonoval@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 13:59:24 by akonoval          #+#    #+#             */
/*   Updated: 2026/05/30 13:59:59 by akonoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_stack(t_stack *stack)
{
	t_node	*old_top;

	if (!stack || stack->size < 2)
		return ;
	old_top = stack->top;
	stack->top = old_top->next;
	stack->top->prev = NULL;
	stack->bottom->next = old_top;
	old_top->prev = stack->bottom;
	old_top->next = NULL;
	stack->bottom = old_top;
}

void	ra(t_stack *stack_a)
{
	rotate_stack(stack_a);
	write(1, "ra\n", 3);
}

void	rb(t_stack *stack_b)
{
	rotate_stack(stack_b);
	write(1, "rb\n", 3);
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	rotate_stack(stack_a);
	rotate_stack(stack_b);
	write(1, "rr\n", 3);
}
