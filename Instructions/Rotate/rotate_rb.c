/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 02:02:51 by mboy              #+#    #+#             */
/*   Updated: 2021/08/11 02:02:55 by mboy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap.h"

t_node	*rotate_rb_loop(t_node *rotate)
{
	while (rotate->next != NULL)
	{
		rotate->value = rotate->next->value;
		rotate->unit = rotate->next->unit;
		rotate->pos = rotate->next->pos;
		rotate = rotate->next;
	}
	return (rotate);
}

void	rotate_rb(t_list *list, int instruction)
{
	int		pos;
	int		unit;
	int		value;
	t_node	*rotate;

	pos = 0;
	unit = 0;
	value = 0;
	rotate = NULL;
	if (list->nb_stackB > 1)
	{
		rotate = list->stackB;
		value = rotate->value;
		unit = rotate->unit;
		pos = rotate->pos;
		rotate = rotate_rb_loop(rotate);
		rotate->value = value;
		rotate->unit = unit;
		rotate->pos = pos;
		while (rotate->prev != NULL)
			rotate = rotate->prev;
		list->stackB = rotate;
	}
	if (instruction == 1)
		write(1, "rb\n", 3);
}
