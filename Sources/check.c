/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 11:12:13 by mboy              #+#    #+#             */
/*   Updated: 2021/08/17 11:16:39 by mboy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

int	check_null(char *values)
{
	int		idx;

	idx = 0;
	while (values[idx])
	{
		if (values[idx] == ' ')
			idx++;
		else
			return (0);
	}
	return (1);
}

int	check_digits(char *value)
{
	int		idx;

	idx = -1;
	while (value[++idx])
	{
		if (value[idx] != '-' && ft_isdigit(value[idx]) != 1)
			return (-1);
	}
	return (0);
}

int	check_doublon(t_node *node, int value)
{
	node = node_start(node);
	while (node->next != NULL)
	{
		if (node->value == value)
			return (-1);
		node = node->next;
	}
	return (0);
}
