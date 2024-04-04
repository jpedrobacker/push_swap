/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergfel <jbergfel@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 10:37:58 by jbergfel          #+#    #+#             */
/*   Updated: 2024/04/04 13:54:47 by jbergfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	push(t_mstack *src, t_mstack *dst)
{
	int	i;
	int	j;
	int	temp_nb;
	int	temp_index;

	if (src->size == 0)
		return ;
	i = dst->size + 1;
	j = -1;
	temp_nb = src->nb[0];
	temp_index = src->index[0];
	while (--i > 0)
	{
		dst->nb[i] = dst->nb[i - 1];
		dst->index[i] = dst->index[i - 1];
	}
	while (++j < src->size - 1)
	{
		src->nb[j] = src->nb[j + 1];
		src->index[j] = src->index[j + 1];
	}
	dst->nb[0] = temp_nb;
	dst->index[0] = temp_index;
	src->size--;
	dst->size++;
}

void	pa(t_stacks *stacks)
{
	push(&stacks->b, &stacks->a);
	ft_printf("pa\n");
}

void	pb(t_stacks *stacks)
{
	push(&stacks->a, &stacks->b);
	ft_printf("pb\n");
}
