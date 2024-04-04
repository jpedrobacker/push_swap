/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergfel <jbergfel@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:15:19 by jbergfel          #+#    #+#             */
/*   Updated: 2024/04/04 11:27:28 by jbergfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "../libftprintf/ft_printf.h"
# include "../libftprintf/libft/libft.h"

typedef struct s_mstack
{
	int	*nb;
	int	*index;
	int	size;
}	t_mstack;

typedef struct s_stacks
{
	t_mstack	a;
	t_mstack	b;
}	t_stacks;

int		check_input(char *str);
int		already_sorted(t_stacks *stacks);
int		check_dups(t_mstack stack, int num);
void	check_av(int ac, char **av, t_stacks *stack, int index);
void	tree_sort(t_stacks *stacks);
void	four_sort(t_stacks *stacks);
void	five_sort(t_stacks *stacks);
void	radix_sort(t_stacks *stacks);

//Frees
void	free_all(t_stacks *stacks, char *error_msg, int i);

//Utils
void	update_index(t_stacks *stacks);
void	small_a_to_b(t_stacks *stacks);
int		index_min(int *num, int size);
void	print_arr(t_stacks *stacks, char *msg);

//Swap
void	swap(t_mstack *stack);
void	sa(t_stacks *stacks);
void	sb(t_stacks *stacks);
void	ss(t_stacks *stacks);

//Rotate
void	rotate(t_mstack *stack);
void	ra(t_stacks *stacks);
void	rb(t_stacks *stacks);
void	rr(t_stacks *stacks);

//Push
void	push(t_mstack *src_stack, t_mstack *dst_stack);
void	pa(t_stacks *stacks);
void	pb(t_stacks *stacks);

//Reverse rotate
void	rev_rotate(t_mstack *stack);
void	rra(t_stacks *stacks);
void	rrb(t_stacks *stacks);
void	rrr(t_stacks *stacks);

#endif
