/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 02:01:24 by mboy              #+#    #+#             */
/*   Updated: 2021/08/11 02:01:58 by mboy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

void	swap_sa(t_list *list, int instruction)
{
	int		value;
	t_node	*swap;

	value = 0;
	swap = NULL;
	if (list->nb_stackA < 2)
		return ;
	swap = list->stackA;
	ft_swap(&swap->value, &swap->next->value);
	ft_swap(&swap->unit, &swap->next->unit);
	ft_swap(&swap->pos, &swap->next->pos);
	list->stackA = swap;
	if (instruction == 1)
		write(1, "sa\n", 3);
}

void	swap_sb(t_list *list, int instruction)
{
	int		value;
	t_node	*swap;

	value = 0;
	swap = NULL;
	if (list->nb_stackB < 2)
		return ;
	swap = list->stackB;
	ft_swap(&swap->value, &swap->next->value);
	ft_swap(&swap->unit, &swap->next->unit);
	ft_swap(&swap->pos, &swap->next->pos);
	list->stackB = swap;
	if (instruction == 1)
		write(1, "sb\n", 3);
}

void	swap_ss(t_list *list)
{
	swap_sa(list, 0);
	swap_sb(list, 0);
	write(1, "ss\n", 3);
}
