/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znicola <znicola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:12:56 by znicola           #+#    #+#             */
/*   Updated: 2024/12/09 21:01:54 by znicola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_clist	*generate_stack(int argc, char **argv)
{
	t_clist	*stack;
	int		i;
	int		*content;
	t_clist	*new_node;

	stack = NULL;
	i = 1;
	while (i < argc)
	{
		content = malloc(sizeof(int));
		if (!content)
			return (NULL);
		*content = ft_atoi(argv[i]);
		new_node = ft_lstnewcircular(content);
		if (!new_node)
			return (NULL);
		ft_lstadd_backcircular(&stack, new_node);
		i++;
	}
	return (stack);
}

int	main(int argc, char **argv)
{
	t_clist	*stack_a;

	if (argc >= 2 && argv)
	{
		stack_a = generate_stack(argc, argv);
		if (!stack_a)
		{
			ft_putstr_fd("Error\n", 2);
			return (-1);
		}
		push_swap(stack_a);
		ft_lstclearcircular(&stack_a, free);
	}
	else
	{
		ft_putstr_fd("Error\n", 2);
		return (-1);
	}
	return (0);
}
