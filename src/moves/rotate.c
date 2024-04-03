/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergfel <jbergfel@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 10:13:12 by jbergfel          #+#    #+#             */
/*   Updated: 2024/02/29 13:22:13 by jbergfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	rotate(t_mstack *stack)
{
	int	temp_nb;
	int	temp_index;
	int	i;

	if (stack->size < 2)
		return ;
	temp_nb = stack->nb[0];
	temp_index = stack->index[0];
	i = 0;
	while (i < stack->size)
	{
		stack->nb[i] = stack->nb[i + 1];
		stack->index[i] = stack->index[i + 1];
		i++;
	}
	stack->nb[stack->size - 1] = temp_nb;
	stack->index[stack->size - 1] = temp_index;
}

void	ra(t_stacks *stacks)
{
	rotate(&stacks->a);
	ft_printf("ra\n");
}

void	rb(t_stacks *stacks)
{
	rotate(&stacks->b);
	ft_printf("rb\n");
}

void	rr(t_stacks *stacks)
{
	ra(stacks);
	rb(stacks);
	ft_printf("rr\n");
}
