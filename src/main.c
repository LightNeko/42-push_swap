/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znicola <znicola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:12:56 by znicola           #+#    #+#             */
/*   Updated: 2024/12/22 22:16:43 by znicola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_next_min(int *value, int size)
{
	static int	last_min = INT_MIN;
	int			min;
	int			min_index;
	int			i;

	min = INT_MAX;
	min_index = -1;
	i = 0;
	while (i < size)
	{
		if (value[i] > last_min && value[i] < min)
		{
			min = value[i];
			min_index = i;
		}
		i++;
	}
	if (min_index != -1)
		last_min = min;
	return (min_index);
}

int	*arr_compress(int *value, int size)
{
	int	*result;
	int	min_index;
	int	i;

	result = calloc(size, sizeof(int));
	if (!result)
		exit(1);
	i = 0;
	while (i < size)
	{
		min_index = find_next_min(value, size);
		if (min_index == -1)
			break ;
		result[min_index] = i;
		i++;
	}
	return (result);
}

t_clist	*generate_stack(int argc, int *content)
{
	t_clist	*stack;
	int		*node_content;
	int		i;
	t_clist	*new_node;

	stack = NULL;
	i = 0;
	while (i < argc - 1)
	{
		node_content = malloc(sizeof(int));
		*node_content = content[i];
		new_node = ft_lstnewcircular(node_content);
		if (!new_node)
			exit(1);
		ft_lstadd_backcircular(&stack, new_node);
		i++;
	}
	return (stack);
}

int	*init_content(int argc, char **argv)
{
	int	*content;
	int	i;

	content = malloc((argc - 1) * sizeof(int));
	if (!content)
		return (NULL);
	i = 1;
	while (i < argc)
	{
		content[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	return (content);
}

int	main(int argc, char **argv)
{
	t_clist	*stack_a;
	int		*content;
	int		*compressed;

	if (argc >= 2 && argv)
	{
		content = init_content(argc, argv);
		compressed = arr_compress(content, argc - 1);
		free(content);
		stack_a = generate_stack(argc, compressed);
		free(compressed);
		push_swap(stack_a, argc - 1);
		ft_lstclearcircular(&stack_a, free);
	}
	else
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	return (0);
}
