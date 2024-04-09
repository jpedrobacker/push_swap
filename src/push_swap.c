/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergfel <jbergfel@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:15:16 by jbergfel          #+#    #+#             */
/*   Updated: 2024/04/09 12:12:29 by jbergfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int ac, char **av)
{
	t_stacks	*stacks;
	int			j;

	j = 0;
	stacks = ft_calloc(1, sizeof(t_stacks));
	if (!stacks)
		free_all(stacks, "Error", 1);
	if (ac > 1)
		check_av(ac, av, stacks, 0);
	if (already_sorted(stacks))
		free_all(stacks, "Error", 0);
	if (stacks->a.size == 2 && stacks->a.nb[0] > stacks ->a.nb[1])
		sa(stacks);
	else if (stacks->a.size == 3)
		tree_sort(stacks);
	else if (stacks->a.size == 4)
		four_sort(stacks);
	else if (stacks->a.size == 5)
		five_sort(stacks);
	else
		radix_sort(stacks);
	free_all(stacks, "Stacks free", 0);
	return (0);
}
