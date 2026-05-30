/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonoval <akonoval@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 13:40:59 by akonoval          #+#    #+#             */
/*   Updated: 2026/05/30 16:56:46 by akonoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_node	*current;

	if (!stack || !stack->top)
		return (1);
	current = stack->top;
	while (current->next != NULL)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

void	sort_three(t_stack *a)
{
	int		top;
	int		mid;
	int		bot;

	if (is_sorted(a))
		return ;
	top = a->top->value;
	mid = a->top->next->value;
	bot = a->bottom->value;
	if (top > mid && mid < bot && top < bot)
		sa(a);
	else if (top > mid && mid > bot)
	{
		sa(a);
		rra(a);
	}
	else if (top > mid && mid < bot && top > bot)
		ra(a);
	else if (top < mid && mid > bot && top < bot)
	{
		sa(a);
		ra(a);
	}
	else if (top < mid && mid > bot && top > bot)
		rra(a);
}

static int	get_min_pos(t_stack *stack)
{
	t_node	*current;
	int		min_idx;
	int		min_pos;
	int		pos;

	current = stack->top;
	min_idx = current->index;
	min_pos = 0;
	pos = 0;
	while (current)
	{
		if (current->index < min_idx)
		{
			min_idx = current->index;
			min_pos = pos;
		}
		pos++;
		current = current->next;
	}
	return (min_pos);
}

void	sort_four_five(t_stack *a, t_stack *b)
{
	int		min_pos;

	while (a->size > 3)
	{
		min_pos = get_min_pos(a);
		if (min_pos <= a->size / 2)
		{
			while (min_pos--)
				ra(a);
		}
		else
		{
			min_pos = a->size - min_pos;
			while (min_pos--)
				rra(a);
		}
		if (is_sorted(a))
			break ;
		pb(a, b);
	}
	sort_three(a);
	while (b->size > 0)
		pa(a, b);
}

void	route_sorting(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size == 2)
		sa(stack_a);
	else if (stack_a->size == 3)
		sort_three(stack_a);
	else if (stack_a->size == 4 || stack_a->size == 5)
		sort_four_five(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
}
