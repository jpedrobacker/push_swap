/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergfel <jbergfel@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 10:01:43 by jbergfel          #+#    #+#             */
/*   Updated: 2024/03/31 19:19:44 by jbergfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	bubble_sort(int *stack, int size)
{
	int	j = 0;
	int	temp;

	while (j < (size - 1))
	{
		if (stack[j] > stack[j + 1])
		{
			temp = stack[j];
			stack[j] = stack[j + 1];
			stack[j + 1] = temp;
			j = 0;
		}
		else
			j++;
	}
}

void	tree_sort(t_stacks *stacks)
{
	int	*nb;

	nb = stacks->a.nb;
	if (nb[0] > nb[1] && nb[1] < nb[2] && nb[0] < nb[2])
		sa(stacks);
	else if (nb[0] > nb[1] && nb[1] < nb[2] && nb[0] > nb[2])
		ra(stacks);
	else if (nb[0] < nb[1] && nb[1] > nb[2] && nb[0] > nb[2])
		rra(stacks);
	else if (nb[0] > nb[1] && nb[1] > nb[2])
	{
		sa(stacks);
		rra(stacks);
	}
	else if (nb[0] < nb[1] && nb[1] > nb[2] && nb[0] < nb[2])
	{
		sa(stacks);
		ra(stacks);
	}
}

void	four_sort(t_stacks *stacks)
{
	small_a_to_b(stacks);
	tree_sort(stacks);
	pa(stacks);
}

void	five_sort(t_stacks *stacks)
{
	small_a_to_b(stacks);
	four_sort(stacks);
	pa(stacks);
}

static void	radix_sort_b(t_stacks *stacks, int b_size, int bit_max, int i)
{
	while (b_size-- && i <= bit_max && !already_sorted(stacks))
	{
		if (((stacks->b.index[0] >> i) & 1) == 0)
			rb(stacks);
		else
			pa(stacks);
	}
	if (already_sorted(stacks))
	{
		while(stacks->b.size != 0)
			pa(stacks);
	}
}

void	radix_sort(t_stacks *stacks)
{
	int	i;
	int	max_bits;
	int	size;

	update_index(stacks);
	max_bits = 0;
	size = stacks->a.size;
	while (size > 1 && ++max_bits)
		size /= 2;
	i = -1;
	while (++i <= max_bits)
	{
		size = stacks->a.size;
		while (size-- && !already_sorted(stacks))
		{
			if (((stacks->a.index[0] >> i) & 1) == 0)
				pb(stacks);
			else
				ra(stacks);
		}
		radix_sort_b(stacks, stacks->b.size, max_bits, i + 1);
	}
	while (stacks->b.size != 0)
		pa(stacks);
}
