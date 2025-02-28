/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort_stack.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znicola <znicola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 22:34:33 by znicola           #+#    #+#             */
/*   Updated: 2025/02/28 09:52:07 by znicola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	simple_sort_stack(t_clist **start, t_clist **end, int min)
{
	if (*(int *)(*start)->content == min)
	{
		swap(start, end, 'a');
		rotate(start, end, "a");
	}
	else if (*(int *)(*start)->content == min + 1)
	{
		if ((*(int *)(*start)->content) >= (*(int *)(*start)->next->content))
			swap(start, end, 'a');
		else
			rotate(start, end, "ra");
	}
	else if (*(int *)(*start)->content == min + 2)
	{
		if (*(int *)(*start)->next->content == min)
			rotate(start, end, "a");
		else
		{
			rotate(start, end, "a");
			swap(start, end, 'a');
		}
	}
	return (0);
}

int	five_sort_stack(t_clist **start, t_clist **end, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (*(int *)(*start)->content == 0 || *(int *)(*start)->content == 1)
			push(start, end, 'b');
		else
			rotate(start, end, "a");
		i++;
	}
	if (*(int *)(*start)->content != 2
		|| (*(int *)(*start)->prev->content != 4))
		simple_sort_stack(start, end, 2);
	if (*(int *)(*end)->content == 0)
		rotate(start, end, "b");
	push(end, start, 'a');
	push(end, start, 'a');
	return (0);
}
