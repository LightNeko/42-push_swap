/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znicola <znicola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 12:02:50 by znicola           #+#    #+#             */
/*   Updated: 2025/02/14 12:04:15 by znicola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"

typedef struct s_clist
{
	void			*content;
	struct s_clist	*next;
	struct s_clist	*prev;
}	t_clist;

int		push_swap(t_clist *stack_a, int size);
int		simple_sort_stack(t_clist **start, t_clist **end, int min);
int		five_sort_stack(t_clist **start, t_clist **end, int size);
int		swap(t_clist **stack_a, t_clist **stack_b, char flag);
int		push(t_clist **start, t_clist **end, char flag);
int		rotate(t_clist **stack_a, t_clist **stack_b, const char *flag);
t_clist	*ft_lstnewcircular(void *content);
void	ft_lstadd_backcircular(t_clist **lst, t_clist *new);
t_clist	*ft_lstlastcircular(t_clist *lst);
void	ft_lstclearcircular(t_clist **lst, void (*del)(void *));
void	ft_lstdelonecircular(t_clist *lst, void (*del)(void *));
int		ft_lstsizecircular(t_clist *lst);
int		calculate_bit_size(int count);
void	free_split(char **arr);
#endif
