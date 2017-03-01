/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmccain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 22:50:21 by cmccain           #+#    #+#             */
/*   Updated: 2016/09/28 15:10:35 by cmccain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*mem;
	size_t	i;
	char	*set;

	i = 0;
	mem = (void *)malloc(size);
	if (!mem)
		return (NULL);
	set = (char *)mem;
	while (i < size)
		set[i++] = 0;
	return (set);
}
