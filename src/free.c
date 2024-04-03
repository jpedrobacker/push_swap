/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergfel <jbergfel@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 12:22:29 by jbergfel          #+#    #+#             */
/*   Updated: 2024/04/02 10:11:54 by jbergfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	free_all(t_stacks *stacks, char *error_msg, int i)
{
	if (stacks)
	{
		if (stacks->a.nb)
			free(stacks->a.nb);
		if (stacks->a.index)
			free(stacks->a.index);
		if (stacks->b.nb)
			free(stacks->b.nb);
		if (stacks->b.index)
			free(stacks->b.index);
		free(stacks);
		stacks = NULL;
	}
	if (i == 1)
		ft_printf("%s\n", error_msg);
	exit(0);
}

