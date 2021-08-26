/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 02:20:08 by mboy              #+#    #+#             */
/*   Updated: 2021/08/11 03:57:54 by mboy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

t_node	*new_node(t_node *prev, t_node *next)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		ps_exit(NULL, -1, "[ERROR]: Malloc() failed.\n");
	node->value = 0;
	node->pos = 0;
	node->unit = 0;
	node->prev = prev;
	node->next = next;
	return (node);
}

t_list	*new_list(void)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (!list)
		ps_exit(NULL, -1, "[ERROR]: Malloc() failed.\n");
	list->nb_value = 0;
	list->nb_stackA = 0;
	list->nb_stackB = 0;
	list->stackA = NULL;
	list->stackB = NULL;
	return (list);
}

void	node_free(t_node *node)
{
	t_node	*tmp;

	while (node != NULL)
	{
		tmp = node;
		node = node->next;
		free(tmp);
	}
	return ;
}

t_node	*node_start(t_node *start)
{
	while (start->prev != NULL)
		start = start->prev;
	return (start);
}

int	node_count(t_node *node)
{
	int		count;

	count = 0;
	while (node->next != NULL)
	{
		node = node->next;
		count++;
	}
	count++;
	node = node_start(node);
	return (count);
}
