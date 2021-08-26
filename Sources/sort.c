/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 00:58:03 by mboy              #+#    #+#             */
/*   Updated: 2021/08/17 11:46:57 by mboy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

void	sort3_next(t_list *list)
{
	int		pos[3];

	pos[0] = list->stackA->pos;
	pos[1] = list->stackA->next->pos;
	pos[2] = list->stackA->next->next->pos;
	if (pos[0] > pos[1] && pos[0] > pos[2])
	{
		swap_sa(list, 1);
		push_pb(list);
		swap_sa(list, 1);
		push_pa(list);
		if (pos[1] > pos[2])
			swap_sa(list, 1);
	}
	return ;
}

void	sort3(t_list *list)
{
	int		pos[3];

	pos[0] = list->stackA->pos;
	pos[1] = list->stackA->next->pos;
	pos[2] = list->stackA->next->next->pos;
	if (!(pos[0] < pos[1] && pos[0] < pos[2] && pos[1] < pos[2]))
	{
		if (pos[0] > pos[1] && pos[0] < pos[2])
			swap_sa(list, 1);
		else if (pos[0] < pos[1])
		{
			push_pb(list);
			swap_sa(list, 1);
			push_pa(list);
			if (pos[0] > pos[2])
				swap_sa(list, 1);
		}
		else
			sort3_next(list);
	}
	return ;
}

void	sort3_min_next(t_list *list)
{
	int		pos[3];

	pos[0] = list->stackA->pos;
	pos[1] = list->stackA->next->pos;
	pos[2] = list->stackA->next->next->pos;
	if (pos[0] > pos[1] && pos[0] > pos[2] && pos[1] > pos[2])
	{
		swap_sa(list, 1);
		reverse_rra(list, 1);
	}
	else if (pos[0] > pos[1] && pos[0] > pos[2] && pos[1] < pos[2])
		rotate_ra(list, 1);
	return ;
}

void	sort3_min(t_list *list)
{
	int		pos[3];

	pos[0] = list->stackA->pos;
	pos[1] = list->stackA->next->pos;
	pos[2] = list->stackA->next->next->pos;
	if (!(pos[0] < pos[1] && pos[0] < pos[2] && pos[1] < pos[2]))
	{
		if (pos[0] < pos[1] && pos[0] < pos[2])
		{
			push_pb(list);
			rotate_ra(list, 1);
			push_pa(list);
		}
		else if (pos[0] > pos[1] && pos[0] < pos[2])
			swap_sa(list, 1);
		else if (pos[0] < pos[1] && pos[0] > pos[2])
			reverse_rra(list, 1);
		else
			sort3_min_next(list);
	}
	return ;
}

void	sort(t_list *list, int select)
{
	if (unit_size(list->stackA) == 2)
	{
		if (list->stackA->pos > list->stackA->next->pos)
			swap_sa(list, 1);
		return ;
	}
	else if (unit_size(list->stackA) == 3)
	{
		if (select == 0)
			return (sort3(list));
		else if (select == 1)
			return (sort3_min(list));
	}
	return ;
}
