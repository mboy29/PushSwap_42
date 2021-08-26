/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortpush.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 03:33:17 by mboy              #+#    #+#             */
/*   Updated: 2021/08/11 03:34:16 by mboy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

void	sort3push_next(t_list *list)
{
	int		pos[3];

	pos[0] = list->stackB->pos;
	pos[1] = list->stackB->next->pos;
	pos[2] = list->stackB->next->next->pos;
	if ((pos[0] > pos[1] && pos[0] < pos[2])
		|| (pos[0] < pos[1] && pos[0] > pos[2]))
	{
		push_pa(list);
		if (pos[0] > pos[1] && pos[0] < pos[2])
			swap_sb(list, 1);
		push_pa(list);
		swap_sa(list, 1);
		push_pa(list);
	}
	return ;
}

void	sort3push(t_list *list)
{
	int		pos[3];

	pos[0] = list->stackB->pos;
	pos[1] = list->stackB->next->pos;
	pos[2] = list->stackB->next->next->pos;
	if (pos[0] < pos[1] && pos[0] < pos[2])
	{
		swap_sb(list, 1);
		push_pa(list);
		swap_sb(list, 1);
		push_pa(list);
		if (pos[1] < pos[2])
			swap_sa(list, 1);
		push_pa(list);
	}
	else if (pos[0] > pos[1] && pos[0] > pos[2])
	{
		push_pa(list);
		push_pa(list);
		push_pa(list);
		if (pos[1] < pos[2])
			swap_sa(list, 1);
	}
	else
		sort3push_next(list);
}

void	sortpush(t_list *list)
{
	if (unit_size(list->stackB) == 1)
		return (push_pa(list));
	else if (unit_size(list->stackB) == 2)
	{
		push_pa(list);
		push_pa(list);
		if (list->stackA->pos > list->stackA->next->pos)
			swap_sa(list, 1);
		return ;
	}
	else if (unit_size(list->stackB) == 3)
		return (sort3push(list));
}
