/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rrr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 02:40:47 by mboy              #+#    #+#             */
/*   Updated: 2021/08/11 02:40:49 by mboy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap.h"

void	reverse_rrr(t_list *list)
{
	reverse_rra(list, 0);
	reverse_rrb(list, 0);
	write(1, "rrr\n", 4);
}