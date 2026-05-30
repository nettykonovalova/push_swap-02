/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonoval <akonoval@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 13:33:12 by akonoval          #+#    #+#             */
/*   Updated: 2026/05/30 18:02:45 by akonoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(t_stack *stack)
{
	int		max_idx;
	int		max_bits;

	max_idx = stack->size - 1;
	max_bits = 0;
	while ((max_idx >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_stack *a, t_stack *b)
{
	int		i;
	int		j;
	int		size;
	int		max_bits;

	max_bits = get_max_bits(a);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		size = a->size;
		while (j < size)
		{
			if ((((a->top->index) >> i) & 1) == 0)
				pb(a, b);
			else
				ra(a);
			j++;
		}
		while (b->size > 0)
			pa(a, b);
		if (is_sorted(a))
			break ;
		i++;
	}
}
