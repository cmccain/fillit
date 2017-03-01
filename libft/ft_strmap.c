/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmccain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 15:54:55 by cmccain           #+#    #+#             */
/*   Updated: 2016/09/29 19:00:05 by cmccain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*map;

	if (!s || !f)
		return (0);
	map = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!map)
		return (0);
	i = -1;
	while (s[++i])
		map[i] = f(s[i]);
	map[ft_strlen(s)] = '\0';
	return (map);
}
