/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmccain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 12:27:08 by cmccain           #+#    #+#             */
/*   Updated: 2016/09/27 12:36:53 by cmccain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int		len;
	int		i;
	int		j;

	len = ft_strlen(little);
	i = 0;
	j = 0;
	if (len == 0)
		return ((char *)big);
	while (big[i])
	{
		while (little[j] == big[i + j])
		{
			if (j == len - 1)
				return ((char *)big + i);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
