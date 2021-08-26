/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setpos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 00:54:12 by mboy              #+#    #+#             */
/*   Updated: 2021/08/11 00:57:43 by mboy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

int	*setpos_get(t_list *list)
{
	int		idx;
	int		*array;

	array = malloc(sizeof(int) * list->nb_value);
	if (!array)
		ps_exit(list, -1, "[ERROR]: Malloc() failed.\n");
	idx = 0;
	while (list->stackA->next != NULL)
	{
		array[idx] = list->stackA->value;
		list->stackA = list->stackA->next;
		idx++;
	}
	array[idx] = list->stackA->value;
	list->stackA = node_start(list->stackA);
	return (array);
}

int	*setpos_sort(t_list *list)
{
	int		idx;
	int		jdx;
	int		min;
	int		*array;

	idx = -1;
	array = setpos_get(list);
	while (++idx < list->nb_value)
	{
		min = idx;
		jdx = idx - 1;
		while (++jdx < list->nb_value)
			if (array[min] > array[jdx])
				min = jdx;
		if (min != idx)
			ft_swap(&array[idx], &array[min]);
	}
	return (array);
}

int	setpos_find(int value, int *array)
{
	int		idx;

	idx = 0;
	while (array[idx] != value)
		idx++;
	return (idx);
}

void	setpos_assign(t_list *list, int *array)
{
	int		idx;

	idx = 0;
	while (list->stackA->next != NULL)
	{
		list->stackA->pos = setpos_find(list->stackA->value, array);
		list->stackA = list->stackA->next;
		idx++;
	}
	list->stackA->pos = setpos_find(list->stackA->value, array);
	list->stackA = node_start(list->stackA);
}

void	setpos(t_list *list)
{
	int		*array;

	array = setpos_sort(list);
	setpos_assign(list, array);
	free (array);
}
