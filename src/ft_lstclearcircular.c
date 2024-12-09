/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclearcircular.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znicola <znicola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 15:06:41 by znicola           #+#    #+#             */
/*   Updated: 2024/12/09 19:19:17 by znicola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstclearcircular(t_clist **lst, void (*del)(void *))
{
	t_clist	*temp;
	t_clist	*last;

	last = (*lst)->prev;
	last->next = NULL;
	while (*lst)
	{
		temp = (*lst)->next;
		ft_lstdelonecircular(*lst, del);
		*lst = temp;
	}
	*lst = NULL;
}
