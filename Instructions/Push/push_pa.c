/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_pa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 02:03:29 by mboy              #+#    #+#             */
/*   Updated: 2021/08/11 02:04:15 by mboy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap.h"

void	push_pa_stackB(t_list *list)
{
	t_node	*update;

	if (list->nb_stackB == 1)
	{
		free (list->stackB);
		list->stackB = NULL;
		list->nb_stackB -= 1;
	}
	else
	{
		rotate_rb(list, 0);
		update = list->stackB;
		while (update->next->next != NULL)
			update = update->next;
		free (update->next);
		update->next = NULL;
		while (update->prev != NULL)
			update = update->prev;
		list->nb_stackB -= 1;
		list->stackB = update;
	}
}

void	push_pa_stackA(t_list *list)
{
	t_node	*update;

	update = NULL;
	update = list->stackA;
	while (update->next != NULL)
		update = update->next;
	update->next = new_node(update, NULL);
	update->next->value = list->stackB->value;
	update->next->unit = list->stackB->unit;
	update->next->pos = list->stackB->pos;
	while (update->prev != NULL)
		update = update->prev;
	list->stackA = update;
	list->nb_stackA += 1;
	reverse_rra(list, 0);
}

void	push_pa(t_list *list)
{
	t_node	*push;

	push = NULL;
	if (list->nb_stackB == 0)
		return ;
	if (!list->stackA)
	{
		list->stackA = new_node(NULL, NULL);
		list->stackA->value = list->stackB->value;
		list->stackA->unit = list->stackB->unit;
		list->stackA->pos = list->stackB->pos;
		list->nb_stackA += 1;
		push_pa_stackB(list);
	}
	else
	{
		push_pa_stackA(list);
		push_pa_stackB(list);
	}
	write(1, "pa\n", 3);
}
