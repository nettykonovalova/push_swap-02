/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonoval <akonoval@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 17:08:39 by akonoval          #+#    #+#             */
/*   Updated: 2026/05/30 17:24:33 by akonoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	handle_error(t_stack *stack_a)
{
	write(2, "Error\n", 6);
	lst_clear(stack_a);
	exit(1);
}

static void	free_split(char **arr)
{
	int		i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static void	parce_and_populate(t_stack *stack_a, char **tokens, int is_split)
{
	int		i;
	int		value;

	i = 0;
	while (tokens[i])
	{
		if (ft_atoi_ps(tokens[i], &value) == 0)
		{
			if (is_split)
				free_split(tokens);
			handle_error(stack_a);
		}
		if (has_duplicate(stack_a, value) == 1)
		{
			if (is_split)
				free_split(tokens);
			handle_error(stack_a);
		}
		lst_add_bottom(stack_a, lst_new_node(value));
		i++;
	}
}

static void	process_arguments(t_stack *stack_a, char *arg)
{
	char	**tokens;
	char	*tmp[2];

	if (arg[0] == '\0')
		handle_error(stack_a);
	if (ft_strchr(arg, ' '))
	{
		tokens = ft_split(arg, ' ');
		if (!tokens || !tokens[0])
		{
			free_split(tokens);
			handle_error(stack_a);
		}
		parce_and_populate(stack_a, tokens, 1);
		free_split(tokens);
	}
	else
	{
		tmp[0] = arg;
		tmp[1] = NULL;
		parce_and_populate(stack_a, tmp, 0);
	}
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		i;

	if (argc < 2)
		return (0);
	stack_a.top = NULL;
	stack_a.bottom = NULL;
	stack_a.size = 0;
	stack_b.top = NULL;
	stack_b.bottom = NULL;
	stack_b.size = 0;
	i = 1;
	while (i < argc)
		process_arguments(&stack_a, argv[i++]);
	assign_indices(&stack_a);
	if (!is_sorted(&stack_a))
		route_sorting(&stack_a, &stack_b);
	lst_clear(&stack_a);
	lst_clear(&stack_b);
	return (0);
}
