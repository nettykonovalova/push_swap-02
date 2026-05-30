/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonoval <akonoval@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 13:55:49 by akonoval          #+#    #+#             */
/*   Updated: 2026/05/30 14:00:20 by akonoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_stack(t_stack *dest, t_stack *src)
{
	t_node	*node_to_push;

	if (!src || src->size == 0)
		return ;
	node_to_push = src->top;
	src->top = src->top->next;
	if (src->top)
		src->top->prev = NULL;
	else
		src->bottom = NULL;
	src->size--;
	if (dest->size == 0)
	{
		dest->top = node_to_push;
		dest->bottom = node_to_push;
		node_to_push->next = NULL;
	}
	else
	{
		node_to_push->next = dest->top;
		dest->top->prev = node_to_push;
		dest->top = node_to_push;
	}
	dest->size++;
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	push_stack(stack_a, stack_b);
	write(1, "pa\n", 3);
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	push_stack(stack_b, stack_a);
	write(1, "pb\n", 3);
}
