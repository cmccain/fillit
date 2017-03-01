/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmccain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/21 12:27:35 by cmccain           #+#    #+#             */
/*   Updated: 2016/12/08 12:56:40 by cmccain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fillit.h"

int		check_errors(char *buf, int count)
{
	int i;
	int count_block;

	i = 0;
	count_block = 0;
	while (i < 20)
	{
		if (i % 5 < 4)
		{
			if (buf[i] != '.' && buf[i] != '#')
				return (0);
			if (buf[i] == '#' && ++count_block > 4)
				return (0);
		}
		else if (buf[i] != '\n')
			return (0);
		i++;
	}
	if (count == 21 && buf[20] != '\n')
		return (0);
	if (!check_if_block_in_contact(buf))
		return (0);
	return (1);
}

int		check_if_block_in_contact(char *buf)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (i < 20)
	{
		if (buf[i] == '#')
		{
			if (i - 1 >= 0 && buf[i - 1] == '#')
				count++;
			if (i + 1 < 20 && buf[i + 1] == '#')
				count++;
			if (i - 5 >= 0 && buf[i - 5] == '#')
				count++;
			if (i + 5 < 20 && buf[i + 5] == '#')
				count++;
		}
		i++;
	}
	if (count != 6 && count != 8)
		return (0);
	return (1);
}
