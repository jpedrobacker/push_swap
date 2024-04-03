/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergfel <jbergfel@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:15:16 by jbergfel          #+#    #+#             */
/*   Updated: 2024/04/03 17:10:51 by jbergfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int main(int ac, char **av)
{
	t_stacks *stacks;
	int	j;

	j = 0;
	stacks = ft_calloc(1, sizeof(t_stacks));
	if (!stacks)
		free_all(stacks, "Calloc Error!", 1);
	if (ac == 2)
		;//only one number to sort, function to clean av goes here
	else
		check_av(ac, av, stacks, 0);
	print_arr(stacks, "Original: ");
	if (already_sorted(stacks))
		free_all(stacks, "Already sorted!", 1);
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
	print_arr(stacks, "Sorted: ");
	free_all(stacks, "Stacks freed!", 1);
	return (0);
}
