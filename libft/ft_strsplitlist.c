/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplitlist.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmccain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 14:49:57 by cmccain           #+#    #+#             */
/*   Updated: 2016/10/06 14:57:37 by cmccain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strsplitlist(char const *str, char c)
{
	char	**t;

	t = ft_strsplit(str, c);
	while (*t)
	{
		ft_putendl(*t);
		t++;
	}
}
