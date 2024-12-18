/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znicola <znicola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:00:48 by znicola           #+#    #+#             */
/*   Updated: 2024/12/17 17:40:02 by znicola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_clist **stack_a, t_clist **stack_b, char flag)
{
	void	*temp;

	if (*stack_a && (flag == 'a' || flag == 's'))
	{
		ft_printf("swapping a\n");
		temp = (*stack_a)->content;
		(*stack_a)->content = (*stack_a)->next->content;
		(*stack_a)->next->content = temp;
	}
	if (*stack_b && (flag == 'b' || flag == 's'))
	{
		ft_printf("swapping b\n");
		temp = (*stack_b)->content;
		(*stack_b)->content = (*stack_b)->next->content;
		(*stack_b)->next->content = temp;
	}
	ft_printf("s%c\n", flag);
	return (0);
}

static int	push_start(t_clist **start)
{
	if ((*start)->next == *start)
		*start = NULL;
	else
	{
		(*start)->prev->next = (*start)->next;
		(*start)->next->prev = (*start)->prev;
		*start = (*start)->next;
	}
	return (0);
}

int	push(t_clist **start, t_clist **end, char flag)
{
	t_clist	*temp;

	if (!*start)
		return (-1);
	temp = *start;
	push_start(start);
	if (*end)
	{
		temp->next = *end;
		temp->prev = (*end)->prev;
		(*end)->prev->next = temp;
		(*end)->prev = temp;
	}
	else
	{
		temp->prev = temp;
		temp->next = temp;
	}
	*end = temp;
	ft_printf("p%c\n", flag);
	return (0);
}

int	rotate(t_clist **stack_a, t_clist **stack_b, const char *flag)
{
	if (*stack_a && (ft_strcmp(flag, "a") == 0 || ft_strcmp(flag, "r") == 0))
		*stack_a = (*stack_a)->next;
	if (*stack_a && (ft_strcmp(flag, "ra") == 0 || ft_strcmp(flag, "rr") == 0))
		*stack_a = (*stack_a)->prev;
	if (*stack_b && (ft_strcmp(flag, "b") == 0 || ft_strcmp(flag, "r") == 0))
		*stack_b = (*stack_b)->next;
	if (*stack_b && (ft_strcmp(flag, "rb") == 0 || ft_strcmp(flag, "rr") == 0))
		*stack_b = (*stack_b)->prev;
	ft_printf("r%s\n", flag);
	return (0);
}
