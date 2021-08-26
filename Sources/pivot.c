/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 00:53:29 by mboy              #+#    #+#             */
/*   Updated: 2021/08/11 03:24:42 by mboy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

void	pivot_basic_a(t_list *list, int unit)
{
	int		size;
	double	pivot;

	size = list->nb_stackA + 1;
	pivot = list->nb_stackA / 2;
	if (list->nb_stackA % 2 == 1)
		pivot += 0.5;
	pivot = list->nb_value - pivot;
	while (--size != 0)
	{
		if ((double)list->stackA->pos < pivot)
		{
			push_pb(list);
			list->stackB->unit = unit;
		}
		else
			rotate_ra(list, 1);
	}
	if ((double)list->stackA->pos < pivot)
	{
		push_pb(list);
		list->stackB->unit = unit;
	}
	return ;
}

void	pivot_unit3_a(t_list *list, int unit)
{
	int	rot;
	int	size;
	int	pivot3;

	rot = 0;
	size = unit_size(list->stackA) + 1;
	pivot3 = unit_max(list->stackA) - 3;
	while (--size != 0)
	{
		if (list->stackA->pos <= pivot3)
		{
			push_pb(list);
			list->stackB->unit = unit;
		}
		else
		{
			rotate_ra(list, 1);
			rot++;
		}
	}
	while (--rot != -1)
		reverse_rra(list, 1);
	return (sort(list, 0));
}

void	pivot_unit_b(t_list *list, int unit)
{
	int		rot;
	int		size;
	double	pivot;

	rot = 0;
	size = unit_size(list->stackB) + 1;
	pivot = unit_min(list->stackB) + (size / 2);
	if (size % 2 == 1)
		pivot += 0.5;
	while (--size != 0)
	{
		if ((double)list->stackB->pos >= pivot)
		{
			push_pa(list);
			list->stackA->unit = unit;
		}
		else
		{
			rotate_rb(list, 1);
			rot++;
		}
	}
	while (--rot != -1)
		reverse_rrb(list, 1);
	return ;
}

void	pivot(t_list *list, int select)
{
	static int	unit = 1;

	if (select == 'B')
		pivot_basic_a(list, (int)unit);
	else if (select == 'U')
		pivot_unit_b(list, (int)unit);
	else if (select == '3')
		pivot_unit3_a(list, (int)unit);
	unit++;
	return ;
}
