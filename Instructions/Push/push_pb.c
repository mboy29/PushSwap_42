/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_pb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 02:04:41 by mboy              #+#    #+#             */
/*   Updated: 2021/08/11 02:04:44 by mboy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap.h"

void	push_pb_stackB(t_list *list)
{
	t_node	*update;

	if (list->nb_stackA == 1)
	{
		free (list->stackA);
		list->stackA = NULL;
		list->nb_stackA -= 1;
	}
	else
	{
		rotate_ra(list, 0);
		update = list->stackA;
		while (update->next->next != NULL)
			update = update->next;
		free (update->next);
		update->next = NULL;
		while (update->prev != NULL)
			update = update->prev;
		list->nb_stackA -= 1;
		list->stackA = update;
	}
}

void	push_pb_stackA(t_list *list)
{
	t_node	*update;

	update = NULL;
	update = list->stackB;
	while (update->next != NULL)
		update = update->next;
	update->next = new_node(update, NULL);
	update->next->value = list->stackA->value;
	update->next->unit = list->stackA->unit;
	update->next->pos = list->stackA->pos;
	while (update->prev != NULL)
		update = update->prev;
	list->stackB = update;
	list->nb_stackB += 1;
	reverse_rrb(list, 0);
}

void	push_pb(t_list *list)
{
	t_node	*push;

	push = NULL;
	if (list->nb_stackA == 0)
		return ;
	if (!list->stackB)
	{
		list->stackB = new_node(NULL, NULL);
		list->stackB->value = list->stackA->value;
		list->stackB->unit = list->stackA->unit;
		list->stackB->pos = list->stackA->pos;
		list->nb_stackB += 1;
		push_pb_stackB(list);
	}
	else
	{
		push_pb_stackA(list);
		push_pb_stackB(list);
	}
	write(1, "pb\n", 3);
}
