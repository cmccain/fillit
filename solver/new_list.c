/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmccain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 12:26:08 by cmccain           #+#    #+#             */
/*   Updated: 2016/12/08 12:57:00 by cmccain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fillit.h"

t_coor	*new_coor(int x, int y)
{
	t_coor	*new_t_coor;

	MAL_CHECK((new_t_coor = (t_coor *)malloc(sizeof(t_coor))));
	new_t_coor->x = x;
	new_t_coor->y = y;
	return (new_t_coor);
}

int		high_sqrt(int n)
{
	int size;

	size = 2;
	while (size * size < n)
		size++;
	return (size);
}

t_board	*create_board(int board_size)
{
	int		y;
	int		x;
	t_board	*board;

	y = 0;
	MAL_CHECK((board = malloc(sizeof(t_board))));
	MAL_CHECK((board->array = malloc(sizeof(char*) * board_size + 1)));
	board->size = board_size;
	while (y < board_size)
	{
		MAL_CHECK((board->array[y] = (char*)malloc(sizeof(char)
						* board_size + 1)));
		x = 0;
		while (x < board_size)
		{
			board->array[y][x] = '.';
			x++;
		}
		board->array[y][x] = '\0';
		y++;
	}
	board->array[y] = NULL;
	return (board);
}
