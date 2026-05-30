/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonoval <akonoval@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 14:01:42 by akonoval          #+#    #+#             */
/*   Updated: 2026/05/30 14:01:43 by akonoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_stack(t_stack *stack)
{
	t_node	*first;
	t_node	*second;
	int		tmp_value;
	int		tmp_index;

	if (!stack || stack->size < 2)
		return ;
	first = stack->top;
	second = first->next;
	tmp_value = first->value;
	first->value = second->value;
	second->value = tmp_value;
	tmp_index = first->index;
	first->index = second->index;
	second->index = tmp_index;
}

void	sa(t_stack *stack_a)
{
	swap_stack(stack_a);
	write(1, "sa\n", 3);
}

void	sb(t_stack *stack_b)
{
	swap_stack(stack_b);
	write(1, "sb\n", 3);
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	swap_stack(stack_a);
	swap_stack(stack_b);
	write(1, "ss\n", 3);
}
