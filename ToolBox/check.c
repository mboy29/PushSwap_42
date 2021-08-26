/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 02:19:45 by mboy              #+#    #+#             */
/*   Updated: 2021/08/11 02:19:57 by mboy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

int	check_list(t_list *list)
{
	t_node	*check;

	if (list->stackB != NULL)
		return (-1);
	check = list->stackA;
	while (check->next != NULL)
	{
		if ((check->prev == NULL || check->prev->value < check->value)
			&& (check->next == NULL || check->next->value > check->value))
			check = check->next;
		else
			return (-1);
	}
	return (1);
}
