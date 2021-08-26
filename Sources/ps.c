/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 00:39:05 by mboy              #+#    #+#             */
/*   Updated: 2021/08/26 10:48:27 by mboy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

void	ps_exit(t_list *list, int ex, char *mess)
{
	if (list)
	{
		if (list->stackA)
			node_free(list->stackA);
		if (list->stackB)
			node_free(list->stackB);
		list->nb_value = 0;
		list->nb_stackA = 0;
		list->nb_stackB = 0;
		free (list);
	}
	if (mess)
		ft_putstr_fd(mess, 1);
	if (ex == -1)
		exit (EXIT_FAILURE);
	exit (EXIT_SUCCESS);
}

int	ps_prep(t_list *list)
{
	setpos(list);
	while (unit_size(list->stackA) > 3)
		pivot(list, 'B');
	sort(list, 1);
	if (list->nb_value == 3)
		return (1);
	else if (list->nb_stackB <= 3)
	{
		sortpush(list);
		return (1);
	}
	return (0);
}

void	ps_exec(t_list *list)
{
	if (ps_prep(list) == 1)
		return ;
	while (check_list(list) != 1)
	{
		if (unit_size(list->stackB) <= 3)
			sortpush(list);
		else
		{
			pivot(list, 'U');
			if (unit_size(list->stackA) <= 3)
				sort(list, 0);
			else
				pivot(list, '3');
		}
	}
	return ;
}

int	main(int ac, char **av)
{
	t_list	*list;

	if (ac <= 1)
		ps_exit(NULL, -1, NULL);
	list = new_list();
	parse(list, ac - 1, av);
	if (list->nb_value == 1 || check_list(list) == 1)
		ps_exit(list, 1, NULL);
	if (list->nb_value <= 3)
	{
		setpos(list);
		sort(list, 1);
	}
	else
		ps_exec(list);
	if (check_list(list) == 1)
		ps_exit(list, 1, NULL);
	return (0);
}
