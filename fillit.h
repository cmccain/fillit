/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmccain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 12:27:51 by cmccain           #+#    #+#             */
/*   Updated: 2016/12/07 13:15:50 by cmccain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# ifndef FILLIT_INCLUDES
#  define FILLIT_INCLUDES
#  include <unistd.h>
#  include <stdlib.h>
#  include <fcntl.h>
#  include "libft/libft.h"
# endif

# ifndef MAL_CHECK
#  define MAL_CHECK(x) if (!x) return (NULL);
# endif

typedef struct	s_coor
{
	int			x;
	int			y;
}				t_coor;

typedef struct	s_board
{
	int			size;
	char		**array;
}				t_board;

typedef struct	s_piece
{
	char		**array;
	char		letter;
	int			width;
	int			height;
}				t_piece;

t_list			*get_lst(int fd, int *nb_forms);
t_piece			*get_piece(char letter, char *buf);
char			**get_piece_with_letter(char **piece, char letter,
		int height, int width);
void			get_min_max_piece(char *buf, t_coor *min, t_coor *max);
t_piece			*get_lst_piece(char **array, int width,
		int height, char letter);

int				check_errors(char *buf, int count);
int				check_if_block_in_contact(char *buf);
t_coor			*new_coor(int x, int y);
int				high_sqrt(int n);
t_board			*create_board(int board_size);
t_board			*solve(t_list *list, int *nb_forms);
int				solve_board(t_board *board, t_list *list);
int				is_place_possible(t_piece *piece, t_board *board, int x, int y);
void			put_piece(t_piece *piece, t_board *board, t_coor *coor);
void			put_dot(t_piece *piece, t_board *board, t_coor *coor);

#endif
