/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonoval <akonoval@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 13:47:01 by akonoval          #+#    #+#             */
/*   Updated: 2026/05/30 13:51:02 by akonoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi_ps(const char *str, int *result)
{
	int			i;
	int			sign;
	long long	num;

	i = 0;
	sign = 1;
	num = 0;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	if (str[i] < '0' || str[i] > '9')
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - '0');
		if ((sign * num) > 2147483647 || (sign * num) < -2147483648)
			return (0);
		i++;
	}
	if (str[i] != '\0')
		return (0);
	*result = (int)(num * sign);
	return (1);
}

int	has_duplicate(t_stack *stack, int value)
{
	t_node	*current;

	if (!stack || !stack->top)
		return (0);
	current = stack->top;
	while (current != NULL)
	{
		if (current->value == value)
			return (1);
		current = current->next;
	}
	return (0);
}

void	assign_indices(t_stack *stack)
{
	t_node	*current;
	t_node	*smallest_node;
	int		rank;

	if (!stack || stack->size == 0)
		return ;
	rank = 0;
	while (rank < stack->size)
	{
		current = stack->top;
		smallest_node = NULL;
		while (current != NULL)
		{
			if (current->index == -1 && (smallest_node == NULL
					|| current->value < smallest_node->value))
			{
				smallest_node = current;
			}
			current = current->next;
		}
		if (smallest_node != NULL)
			smallest_node->index = rank;
		rank++;
	}
}
