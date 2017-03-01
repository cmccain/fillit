/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmccain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 17:00:26 by cmccain           #+#    #+#             */
/*   Updated: 2016/09/26 21:56:02 by cmccain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t len)
{
	size_t	i;

	i = 0;
	while (src[i] && (i < len))
	{
		dest[i] = src[i];
		i++;
	}
	while (len > i)
	{
		dest[i] = 0;
		i++;
	}
	return (dest);
}
