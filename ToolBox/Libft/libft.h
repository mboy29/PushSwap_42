/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 16:06:41 by mboy              #+#    #+#             */
/*   Updated: 2021/08/11 02:18:52 by mboy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

int				ft_atoi(const char *str);
long			ft_atol(const char *str);
int				ft_isdigit(int c);
size_t			ft_strlen(const char *s);
void			ft_putstr_fd(char *s, int fd);
char			**ft_split(char const *s, char c);
void			ft_swap(int *a, int *b);

#endif
