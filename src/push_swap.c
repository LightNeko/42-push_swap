/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znicola <znicola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 17:19:08 by znicola           #+#    #+#             */
/*   Updated: 2024/12/09 21:01:52 by znicola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_swap(t_clist *stack_a)
{
	t_clist	*stack_b;
	t_clist	*current;

	stack_b = NULL;
	current = stack_a;
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
	}
	return (0);
}
