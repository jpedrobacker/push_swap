/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergfel <jbergfel@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 10:39:22 by jbergfel          #+#    #+#             */
/*   Updated: 2024/04/04 11:28:17 by jbergfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	rev_rotate(t_mstack *stack)
{
	int	temp_nb;
	int	temp_index;
	int	i;

	if (stack->size < 2)
		return ;
	temp_nb = stack->nb[stack->size - 1];
	temp_index = stack->index[stack->size - 1];
	i = stack->size;
	while (i > 0)
	{
		stack->nb[i] = stack->nb[i - 1];
		stack->index[i] = stack->index[i - 1];
		i--;
	}
	stack->nb[0] = temp_nb;
	stack->index[0] = temp_index;
}

void	rra(t_stacks *stacks)
{
	rev_rotate(&stacks->a);
	ft_printf("rra\n");
}

void	rrb(t_stacks *stacks)
{
	rev_rotate(&stacks->b);
	ft_printf("rb\n");
}

void	rrr(t_stacks *stacks)
{
	rra(stacks);
	rrb(stacks);
	ft_printf("rrr\n");
}
