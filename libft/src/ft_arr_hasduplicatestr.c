/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_hasduplicatestr.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znicola <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 13:28:44 by znicola           #+#    #+#             */
/*   Updated: 2025/01/20 23:09:01 by znicola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_arr_hasduplicatestr(int size, char **strarr)
{
	int	i;
	int	j;

	if (size < 2)
		return (0);
	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (ft_strcmp(strarr[i], strarr[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
