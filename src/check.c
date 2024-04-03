/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergfel <jbergfel@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 20:53:27 by jbergfel          #+#    #+#             */
/*   Updated: 2024/04/03 17:01:28 by jbergfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	already_sorted(t_stacks *stacks)
{
	int	i;

	i = 0;
	while (i < stacks->a.size - 1)
	{
		if (stacks->a.nb[i] > stacks->a.nb[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	check_input(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

void	check_av(int ac, char **av, t_stacks *stacks, int index)
{
	long	temp;

	stacks->a.size = 0;
	stacks->b.size = 0;
	stacks->a.nb = ft_calloc((ac - 1), sizeof(int));
	stacks->b.nb = ft_calloc((ac - 1), sizeof(int));
	stacks->a.index = ft_calloc((ac - 1), sizeof(int));
	stacks->b.index = ft_calloc((ac - 1), sizeof(int));
	if (!stacks->a.nb || !stacks->a.index || !stacks->b.nb || !stacks->b.index)
		free_all(stacks, "Stacks Calloc Error!", 1);
	while(++index < ac)
	{
		if (check_input(av[index]) == 0)
			free_all(stacks, "Input Error!", 1);
		temp = ft_atoi(av[index]);
		if (check_dups(stacks->a ,temp))
			free_all(stacks, "Duplicates Found!", 1);
		stacks->a.index[stacks->a.size] = (int)temp;
		stacks->a.nb[stacks->a.size] = (int)temp;
		stacks->a.size++;
	}
}

void	print_arr(t_stacks *stacks, char *msg)
{
	ft_printf("%s", msg);
	int j = 0;
	while (j < stacks->a.size)
	{
		ft_printf("%d, ", stacks->a.nb[j]);
		j++;
	}
	ft_printf("\n");
}
