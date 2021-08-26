/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 02:03:02 by mboy              #+#    #+#             */
/*   Updated: 2021/08/11 02:03:18 by mboy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap.h"

t_node	*reverse_rra_loop(t_node *reverse)
{
	while (reverse->prev != NULL)
	{
		reverse->value = reverse->prev->value;
		reverse->unit = reverse->prev->unit;
		reverse->pos = reverse->prev->pos;
		reverse = reverse->prev;
	}
	return (reverse);
}

void	reverse_rra(t_list *list, int instruction)
{
	int		pos;
	int		unit;
	int		value;
	t_node	*reverse;

	pos = 0;
	unit = 0;
	value = 0;
	reverse = NULL;
	if (list->nb_stackA > 1)
	{
		reverse = list->stackA;
		while (reverse->next != NULL)
			reverse = reverse->next;
		value = reverse->value;
		unit = reverse->unit;
		pos = reverse->pos;
		reverse = reverse_rra_loop(reverse);
		reverse->value = value;
		reverse->unit = unit;
		reverse->pos = pos;
		list->stackA = reverse;
	}
	if (instruction == 1)
		write(1, "rra\n", 4);
}
