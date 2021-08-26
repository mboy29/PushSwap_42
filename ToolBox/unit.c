/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 02:20:52 by mboy              #+#    #+#             */
/*   Updated: 2021/08/11 02:21:50 by mboy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

int	unit_size(t_node *node)
{
	int		unit;
	int		size;

	size = 0;
	unit = node->unit;
	while (node->unit == unit && node->next != NULL)
	{
		size++;
		node = node->next;
	}
	if (node->unit == unit)
		size++;
	node = node_start(node);
	return (size);
}

int	unit_min(t_node *node)
{
	int		min;
	int		unit;

	min = node->pos;
	unit = node->unit;
	while (node->unit == unit && node->next != NULL)
	{
		if (node->pos < min)
			min = node->pos;
		node = node->next;
	}
	if (node->unit == unit && node->pos < min)
		min = node->pos;
	node = node_start(node);
	return (min);
}

int	unit_max(t_node *node)
{
	int		max;
	int		unit;

	max = node->pos;
	unit = node->unit;
	while (node->unit == unit && node->next != NULL)
	{
		if (node->pos > max)
			max = node->pos;
		node = node->next;
	}
	if (node->unit == unit && node->pos > max)
		max = node->pos;
	node = node_start(node);
	return (max);
}
