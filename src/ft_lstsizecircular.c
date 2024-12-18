/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsizecircular.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znicola <znicola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 13:23:37 by znicola           #+#    #+#             */
/*   Updated: 2024/12/17 20:45:14 by znicola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsizecircular(t_clist *lst)
{
	int		count;
	t_clist	*start;

	if (!lst)
		return (0);
	count = 0;
	start = lst;
	while (1)
	{
		count++;
		lst = lst->next;
		if (lst == start)
			break ;
	}
	return (count);
}
