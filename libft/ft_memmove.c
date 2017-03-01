/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmccain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 13:33:33 by cmccain           #+#    #+#             */
/*   Updated: 2016/09/29 17:44:44 by cmccain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	signed char		set;
	size_t			set_len;
	unsigned char	*s;
	unsigned char	*d;

	s = (unsigned char *)src;
	d = (unsigned char *)dst;
	if (dst < src)
	{
		set = 1;
		set_len = 0;
	}
	else
	{
		set = -1;
		set_len = len - 1;
		len = -1;
	}
	while (set_len != len)
	{
		d[set_len] = s[set_len];
		set_len += set;
	}
	return (dst);
}
