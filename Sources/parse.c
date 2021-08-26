/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 00:42:19 by mboy              #+#    #+#             */
/*   Updated: 2021/08/11 00:42:28 by mboy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

t_node	*parse_fecth(t_node *node, char **values)
{
	int		idx;

	idx = -1;
	while (values[++idx])
	{
		if (ft_atol(values[idx]) < -2147483648
			|| ft_atol(values[idx]) > 2147483647
			|| check_digits(values[idx]) != 0
			|| check_doublon(node, ft_atoi(values[idx])) != 0)
			return (NULL);
		node->value = ft_atoi(values[idx]);
		node->next = new_node(node, NULL);
		node = node->next;
	}
	return (node);
}

void	parse_reset(t_list *list, t_node *parse)
{
	parse = parse->prev;
	free(parse->next);
	parse->next = NULL;
	parse = node_start(parse);
	list->stackA = parse;
}

void	parse_loop(t_list *list, t_node *parse, int ac, char **av)
{
	int		idx;
	int		jdx;
	char	**values;

	idx = 0;
	values = NULL;
	while (++idx <= ac)
	{
		if (check_null(av[idx]) == 1)
			ps_exit(NULL, -1, "[ERROR]: Empty argument.\n");
		values = ft_split(av[idx], ' ');
		parse = parse_fecth(parse, values);
		if (!parse)
			ps_exit(list, -1, "[ERROR]: Invalid values.\n");
		jdx = -1;
		while (values[++jdx])
			free(values[jdx]);
		free(values);
		values = NULL;
	}
	parse_reset(list, parse);
	return ;
}

void	parse(t_list *list, int ac, char **av)
{
	t_node	*parse;

	parse = list->stackA;
	parse = new_node(NULL, NULL);
	parse_loop(list, parse, ac, av);
	list->nb_value = node_count(list->stackA);
	list->nb_stackA = list->nb_value;
	list->stackB = NULL;
	list->nb_stackB = 0;
	return ;
}
