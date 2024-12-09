/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_backcircular.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znicola <znicola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 13:44:41 by znicola           #+#    #+#             */
/*   Updated: 2024/12/02 20:44:16 by znicola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_backcircular(t_clist **lst, t_clist *new)
{
	t_clist	*last;

	if (new)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			last = ft_lstlastcircular(*lst);
			last->next = new;
			new->prev = last;
			new->next = *lst;
			(*lst)->prev = new;
		}
	}
}
