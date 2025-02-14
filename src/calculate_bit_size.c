/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_bit_size.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znicola <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:34:08 by znicola           #+#    #+#             */
/*   Updated: 2025/02/14 10:34:24 by znicola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calculate_bit_size(int numcount)
{
	int	bit_count;

	bit_count = 0;
	while (numcount > 0)
	{
		bit_count++;
		numcount >>= 1;
	}
	if (bit_count == 0)
		bit_count = 1;
	return (bit_count);
}
