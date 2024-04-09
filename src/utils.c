/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergfel <jbergfel@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 12:42:21 by jbergfel          #+#    #+#             */
/*   Updated: 2024/04/09 12:12:43 by jbergfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	index_min(int *num, int size)
{
	int	i_min;
	int	v_min;
	int	j;

	i_min = 0;
	v_min = num[0];
	j = 0;
	while (j < size)
	{
		if (num[j] < v_min)
		{
			v_min = num[j];
			i_min = j;
		}
		j++;
	}
	return (i_min);
}

void	small_a_to_b(t_stacks *stacks)
{
	int	i_min;

	i_min = index_min(stacks->a.nb, stacks->a.size);
	while (i_min != 0)
	{
		if (i_min <= stacks->a.size / 2)
			ra(stacks);
		else
			rra(stacks);
		i_min = index_min(stacks->a.nb, stacks->a.size);
	}
	pb(stacks);
}

void	update_index(t_stacks *stacks)
{
	int		i;
	int		j;
	int		k;
	int		*index_a;

	index_a = malloc(stacks->a.size * sizeof * index_a);
	if (index_a == NULL)
		free_all(stacks, "Error", 1);
	i = -1;
	while (++i < stacks->a.size)
	{
		k = 0;
		j = -1;
		while (++j < stacks->a.size)
			if (stacks->a.index[i] > stacks->a.index[j])
				k++;
		index_a[i] = k;
	}
	i = stacks->a.size;
	while (i--)
		stacks->a.index[i] = index_a[i];
	free(index_a);
}

int	check_dups(t_mstack stack, int num)
{
	int	i;

	i = 0;
	while (i < stack.size)
	{
		if (stack.nb[i] == num)
			return (1);
		i++;
	}
	return (0);
}
