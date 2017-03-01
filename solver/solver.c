/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmccain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 12:25:23 by cmccain           #+#    #+#             */
/*   Updated: 2016/12/08 12:57:14 by cmccain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fillit.h"

t_board	*solve(t_list *list, int *nb_forms)
{
	int		board_size;
	t_board	*board;

	board_size = high_sqrt(*nb_forms * 4);
	board = create_board(board_size);
	while (!solve_board(board, list))
	{
		board_size++;
		board = create_board(board_size);
	}
	return (board);
}

int		solve_board(t_board *board, t_list *list)
{
	int		x;
	int		y;
	t_piece	*piece;

	if (list == NULL)
		return (1);
	y = 0;
	piece = (t_piece *)(list->content);
	while (y < board->size - piece->height + 1)
	{
		x = 0;
		while (x < board->size - piece->width + 1)
		{
			if (is_place_possible(piece, board, x, y))
			{
				if (solve_board(board, list->next))
					return (1);
				else
					put_dot(piece, board, new_coor(x, y));
			}
			x++;
		}
		y++;
	}
	return (0);
}

int		is_place_possible(t_piece *piece, t_board *board, int x, int y)
{
	int		i;
	int		j;

	i = 0;
	while (i < piece->width)
	{
		j = 0;
		while (j < piece->height)
		{
			if (ft_isalpha(piece->array[j][i]) &&
				board->array[y + j][x + i] != '.')
				return (0);
			j++;
		}
		i++;
	}
	put_piece(piece, board, new_coor(x, y));
	return (1);
}

void	put_piece(t_piece *piece, t_board *board, t_coor *coor)
{
	int		i;
	int		j;

	i = 0;
	while (i < piece->width)
	{
		j = 0;
		while (j < piece->height)
		{
			if (ft_isalpha(piece->array[j][i]))
				board->array[coor->y + j][coor->x + i] = piece->array[j][i];
			j++;
		}
		i++;
	}
}

void	put_dot(t_piece *piece, t_board *board, t_coor *coor)
{
	int		i;
	int		j;

	i = 0;
	while (i < piece->width)
	{
		j = 0;
		while (j < piece->height)
		{
			if (ft_isalpha(piece->array[j][i]))
				board->array[coor->y + j][coor->x + i] = '.';
			j++;
		}
		i++;
	}
}
