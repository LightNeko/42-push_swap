/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnewcircular.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znicola <znicola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 12:20:00 by znicola           #+#    #+#             */
/*   Updated: 2024/12/02 20:43:14 by znicola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_clist	*ft_lstnewcircular(void *content)
{
	t_clist	*list;

	list = malloc(sizeof(t_clist));
	if (!list)
		return (NULL);
	list->content = content;
	list->next = list;
	list->prev = list;
	return (list);
}
