/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znicola <znicola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 17:19:08 by znicola           #+#    #+#             */
/*   Updated: 2024/12/18 23:11:11 by znicola          ###   ########.fr       */
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

static int	get_msb(t_clist *stack)
{
	int				msb;
	unsigned int	value;
	int				bit_position;
	t_clist			*current;

	msb = 0;
	current = stack;
	while (current)
	{
		value = *(int *)(current->content);
		bit_position = 0;
		while (value > 0)
		{
			value >>= 1;
			bit_position++;
		}
		if (bit_position > msb)
			msb = bit_position;
		current = current->next;
		if (current == stack)
			break ;
	}
	return (msb - 1);
}

static int	radix_sort_stack(t_clist **start, t_clist **end)
{
	int	i;
	int	j;	
	int	msb;

	msb = get_msb(*start);
	i = 0;
	while (i <= msb)
	{
		if (*start == NULL || is_sorted(*start))
			break ;
		j = ft_lstsizecircular(*start);
		while (j != 0)
		{
			if (!((*(int *)(*start)->content >> i) & 1))
				push(start, end, 'b');
			else
				rotate(start, end, "a");
			j--;
		}
		while (*end)
			push(end, start, 'a');
		i++;
	}
	return (0);
}

int	push_swap(t_clist *stack_a)
{
	t_clist	*stack_b;
//	t_clist	*current;

	stack_b = NULL;	
	radix_sort_stack(&stack_a, &stack_b);
//	current = stack_a;
/*	ft_printf("\nSTACK_A\n");
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
	}
*/
	return (0);
}
