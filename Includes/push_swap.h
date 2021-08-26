/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 02:23:51 by mboy              #+#    #+#             */
/*   Updated: 2021/08/11 02:25:48 by mboy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./../ToolBox/Libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	int				pos;
	int				unit;
	struct s_node	*prev;
	struct s_node	*next;
}				t_node;

typedef struct s_list
{
	int				nb_value;
	int				nb_stackA;
	int				nb_stackB;
	struct s_node	*stackA;
	struct s_node	*stackB;
}				t_list;

void		list_print(t_list *list);
int			main(int ac, char **av);
void		ps_exit(t_list *list, int ex, char *mess);
int			ps_prep(t_list *list);
void		ps_exec(t_list *list);
void		parse(t_list *list, int ac, char **av);
void		parse_loop(t_list *list, t_node *parse, int ac, char **av);
void		parse_reset(t_list *list, t_node *parse);
t_node		*parse_fecth(t_node *node, char **values);
int			check_null(char *values);
int			check_digits(char *value);
int			check_doublon(t_node *node, int value);
t_list		*new_list(void);
t_node		*new_node(t_node *prev, t_node *next);
t_node		*node_start(t_node *start);
int			node_count(t_node *node);
void		node_free(t_node *node);
int			check_list(t_list *list);
int			unit_size(t_node *node);
int			unit_min(t_node *node);
int			unit_max(t_node *node);
void		push_pa(t_list *list);
void		push_pa_stackA(t_list *list);
void		push_pa_stackB(t_list *list);
void		push_pb(t_list *list);
void		push_pb_stackA(t_list *list);
void		push_pb_stackB(t_list *list);
void		swap_ss(t_list *list);
void		swap_sa(t_list *list, int instruction);
void		swap_sb(t_list *list, int instruction);
void		rotate_rr(t_list *list);
void		rotate_ra(t_list *list, int instruction);
t_node		*rotate_ra_loop(t_node *rotate);
void		rotate_rb(t_list *list, int instruction);
t_node		*rotate_rb_loop(t_node *rotate);
void		reverse_rrr(t_list *list);
void		reverse_rra(t_list *list, int instruction);
t_node		*reverse_rra_loop(t_node *reverse);
void		reverse_rrb(t_list *list, int instruction);
t_node		*reverse_rrb_loop(t_node *reverse);
void		setpos(t_list *list);
int			*setpos_get(t_list *list);
int			*setpos_sort(t_list *list);
void		setpos_assign(t_list *list, int *array);
int			setpos_find(int value, int *array);
void		sort(t_list *list, int select);
void		sort3(t_list *list);
void		sort3_next(t_list *list);
void		sort3_min(t_list *list);
void		sort3_min_next(t_list *list);
void		sortpush(t_list *list);
void		sort3push(t_list *list);
void		sort3push_next(t_list *list);
void		pivot(t_list *list, int select);
void		pivot_basic_a(t_list *list, int unit);
void		pivot_unit3_a(t_list *list, int unit);
void		pivot_unit_b(t_list *list, int unit);

#endif	
