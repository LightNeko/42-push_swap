/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znicola <znicola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:12:56 by znicola           #+#    #+#             */
/*   Updated: 2025/01/17 16:14:03 by znicola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

ssize_t	find_next_min(ssize_t *value, int size)
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
		if (value[i] > last_min && value[i] <= min)
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

ssize_t	*arr_compress(ssize_t *value, int size)
{
	ssize_t	*result;
	int		min_index;
	int		i;

	result = ft_calloc(size, sizeof(ssize_t));
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

t_clist	*generate_stack(int argc, ssize_t *content)
{
	t_clist	*stack;
	ssize_t	*node_content;
	int		i;
	t_clist	*new_node;

	stack = NULL;
	i = 0;
	while (i < argc - 1)
	{
		node_content = malloc(sizeof(ssize_t));
		*node_content = content[i];
		new_node = ft_lstnewcircular(node_content);
		if (!new_node)
			exit(1);
		ft_lstadd_backcircular(&stack, new_node);
		i++;
	}
	return (stack);
}

ssize_t	*init_content(int argc, char **argv)
{
	ssize_t	*content;
	int	i;

	content = malloc((argc - 1) * sizeof(ssize_t));
	if (!content)
		return (NULL);
	i = 1;
	while (i < argc)
	{
		content[i - 1] = ft_atoi(argv[i]);
		if (!ft_isnumber(argv[i]) || ft_arr_hasduplicatestr(argc, argv)
			|| content[i - 1] > INT_MAX)
		{
			ft_printf("Error\n");
			exit(1);
		}
		i++;
	}
	return (content);
}

int	main(int argc, char **argv)
{
	t_clist		*stack_a;
	ssize_t		*content;
	ssize_t		*compressed;

	if (argc < 2)
	{
		ft_printf("Error\n");
		exit(1);
	}
	content = init_content(argc, argv);
	compressed = arr_compress(content, argc - 1);
	free(content);
	stack_a = generate_stack(argc, compressed);
	free(compressed);
	push_swap(stack_a, argc - 1);
	ft_lstclearcircular(&stack_a, free);
	return (0);
}
