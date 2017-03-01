/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmccain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 18:27:45 by cmccain           #+#    #+#             */
/*   Updated: 2016/10/19 18:03:11 by cmccain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**ft_split(char **split, char *str, char c, size_t j)
{
	size_t	i;
	size_t	start;
	size_t	k;

	i = 0;
	start = 0;
	k = 0;
	while (str[i] != '\0' && k < j)
	{
		if (str[i] != c)
		{
			start = i;
			while (str[i] != c && str[i] != '\0')
				i++;
			split[k] = ft_strsub(str, start, i - start);
			k++;
		}
		else
			i++;
	}
	split[k] = NULL;
	return (split);
}

char			**ft_strsplit(char const *str, char c)
{
	char	**split;
	size_t	k;

	if (!str || !c)
		return (0);
	k = ft_countword((char *)str, c);
	split = NULL;
	if ((split = (char **)malloc((k + 1) * sizeof(char *))) == NULL)
		return (NULL);
	split = ft_split(split, (char *)str, c, k);
	return (split);
}
