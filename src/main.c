/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znicola <znicola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:12:56 by znicola           #+#    #+#             */
/*   Updated: 2025/03/03 14:38:12 by znicola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static ssize_t	find_next_min(ssize_t *value, int size)
{
	static ssize_t	last_min = -2147483649;
	int				min;
	int				min_index;
	int				i;

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

static ssize_t	*arr_compress(ssize_t *value, int size)
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

static t_clist	*generate_stack(int argc, ssize_t *content)
{
	t_clist	*stack;
	ssize_t	*node_content;
	int		i;
	t_clist	*new_node;

	stack = NULL;
	i = 0;
	while (i < argc)
	{
		node_content = malloc(sizeof(ssize_t));
		if (!node_content)
			exit(1);
		*node_content = content[i];
		new_node = ft_lstnewcircular(node_content);
		if (!new_node)
		{
			free(node_content);
			exit(1);
		}
		ft_lstadd_backcircular(&stack, new_node);
		i++;
	}
	return (stack);
}

static ssize_t	*init_content(int count, char **argv, int argc)
{
	ssize_t	*content;
	int		i;

	content = malloc((count) * sizeof(ssize_t));
	if (!content)
		return (NULL);
	i = 0;
	while (i < count)
	{
		content[i] = ft_atoi(argv[i]);
		if (!ft_isnumber(argv[i]) || ft_arr_hasduplicatestr(count, argv)
			|| content[i] > INT_MAX || content[i] < INT_MIN)
		{
			free(content);
			if (argc == 2)
				free_split(argv);
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
	char		**numarr;
	ssize_t		*content;
	ssize_t		*compressed;
	int			num_count;

	if (argc == 2)
		numarr = ft_split(argv[1], ' ');
	else
		numarr = argv + 1;
	if (!numarr || !numarr[0] || argc < 2)
		return (0);
	num_count = 0;
	while (numarr[num_count])
		num_count++;
	content = init_content(num_count, numarr, argc);
	if (argc == 2)
		free_split(numarr);
	compressed = arr_compress(content, num_count);
	free(content);
	stack_a = generate_stack(num_count, compressed);
	free(compressed);
	push_swap(stack_a, num_count);
	ft_lstclearcircular(&stack_a, free);
	return (0);
}
