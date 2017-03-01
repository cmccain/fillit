/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmccain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 12:27:10 by cmccain           #+#    #+#             */
/*   Updated: 2016/12/08 12:56:49 by cmccain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fillit.h"

t_list	*get_lst(int fd, int *nb_forms)
{
	char		buf[21];
	char		letter;
	int			ret;
	t_piece		*piece;
	t_list		*list;

	letter = 'A';
	list = NULL;
	while ((ret = read(fd, buf, 21)) >= 20)
	{
		if (!check_errors(buf, ret) ||
			(piece = get_piece(letter++, buf)) == NULL)
			return (NULL);
		(*nb_forms)++;
		ft_lstadd(&list, ft_lstnew(piece, sizeof(t_piece)));
	}
	if (ret != 0)
		return (NULL);
	return (ft_lst_reverse(list));
}

t_piece	*get_piece(char letter, char *buf)
{
	int		y;
	t_coor	*min;
	t_coor	*max;
	char	**array;
	t_piece	*piece;

	y = 0;
	piece = NULL;
	min = new_coor(3, 3);
	max = new_coor(0, 0);
	get_min_max_piece(buf, min, max);
	MAL_CHECK((array = malloc(sizeof(char*) * (max->y - min->y) + 1)));
	while (y < max->y - min->y + 1)
	{
		MAL_CHECK((array[y] = (char*)malloc(sizeof(char) *
						(max->x - min->x) + 1)));
		array[y] = ft_strncpy(array[y], buf + (min->x) + (y + min->y) * 5,
				max->x - min->x + 1);
		y++;
	}
	get_piece_with_letter(array, letter, max->y - min->y + 1,
			max->x - min->x + 1);
	piece = get_lst_piece(array, max->x - min->x + 1,
			max->y - min->y + 1, letter);
	return (piece);
}

char	**get_piece_with_letter(char **piece, char letter,
		int height, int width)
{
	int		y;
	int		x;

	y = 0;
	x = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			if (piece[y][x] == '#')
				piece[y][x] = letter;
			x++;
		}
		y++;
	}
	return (piece);
}

void	get_min_max_piece(char *buf, t_coor *min, t_coor *max)
{
	int i;

	i = 0;
	while (i < 20)
	{
		if (buf[i] == '#')
		{
			if (i % 5 < min->x)
				min->x = i % 5;
			if (i / 5 < min->y)
				min->y = i / 5;
			if (i % 5 > max->x)
				max->x = i % 5;
			if (i / 5 > max->y)
				max->y = i / 5;
		}
		i++;
	}
}

t_piece	*get_lst_piece(char **array, int width, int height, char letter)
{
	t_piece *piece;

	MAL_CHECK((piece = (t_piece *)malloc(sizeof(t_piece))));
	piece->array = array;
	piece->width = width;
	piece->height = height;
	piece->letter = letter;
	return (piece);
}
