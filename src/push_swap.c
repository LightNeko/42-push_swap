/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znicola <znicola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 17:19:08 by znicola           #+#    #+#             */
/*   Updated: 2025/01/17 12:35:57 by znicola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_sorted(t_clist *stack)
{
	t_clist *current;

	if (!stack || stack->next == stack)
		return (1);
	current = stack;
	while (current->next != stack)
	{
		if (*(int *)(current->content) > *(int *)(current->next->content))
			return (0);
		current = current->next;
	}
	return	(1);
}

static int	radix_sort_stack(t_clist **start, t_clist **end)
{
	int	i;
	int	j;	

	i = 0;
	while (i < 7)
	{
		j = ft_lstsizecircular(*end);
		while (j != 0)
		{
			if (((*(int *)(*end)->content >> i) & 1))
				push(end, start, 'a');
			else
				rotate(start, end, "b");
			j--;
		}
		j = ft_lstsizecircular(*start);
		while (j != 0)
		{
			if (!((*(int *)(*start)->content >> i) & 1))
				push(start, end, 'b');
			else
				rotate(start, end, "a");
			j--;
		}
		i++;
	}
	while (*end)
		push(end, start, 'a');
	return (0);
}

int	push_swap(t_clist *stack_a, int size)
{
	t_clist	*stack_b;
	//t_clist	*current;

	stack_b = NULL;	
	if (is_sorted(stack_a))
		return (0);
	if (size <= 3)
		simple_sort_stack(&stack_a, &stack_b, 0);
	else if (size <= 5)
		five_sort_stack(&stack_a, &stack_b, size);
	else if (size <= 500)
		radix_sort_stack(&stack_a, &stack_b);
	/*current = stack_a;
	ft_printf("\nSTACK_A\n");
	while (current)
	{
		ft_printf("%d\n",*(int *)current->content);
		current = current->next;
		if (current == stack_a)
			break ;
	}
	current = stack_b;
	ft_printf("\nSTACK B\n");
	while (current)
	{
		ft_printf("%d\n",*(int *)current->content);
		current = current->next;
		if (current == stack_b)
			break ;
	}*/
	return (0);
}
