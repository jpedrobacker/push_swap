/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergfel <jbergfel@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:15:28 by jbergfel          #+#    #+#             */
/*   Updated: 2024/03/09 12:31:05 by jbergfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	swap(t_mstack *stack)
{
	int	temp_nb;
	int	temp_i;

	if(stack->size < 2)
		return ;
	temp_nb = stack->nb[0];
	temp_i = stack->index[0];
	stack->nb[0] = stack->nb[1];
	stack->index[0] = stack->index[1];
	stack->nb[1] = temp_nb;
	stack->index[1] = temp_i;
}

void	sa(t_stacks *stacks)
{
	swap(&stacks->a);
	ft_printf("sa\n");
}

void	sb(t_stacks *stacks)
{
	swap(&stacks->a);
	ft_printf("sb\n");
}

void	ss(t_stacks *stacks)
{
	swap(&stacks->a);
	swap(&stacks->b);
	ft_printf("ss\n");
}
