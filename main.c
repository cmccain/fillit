/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmccain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 12:28:01 by cmccain           #+#    #+#             */
/*   Updated: 2016/12/08 12:56:24 by cmccain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_error(void)
{
	ft_putendl("error");
	return (EXIT_FAILURE);
}

void		print_board(t_board *board)
{
	int		y;
	int		x;

	y = 0;
	while (y < board->size)
	{
		x = 0;
		while (x < board->size)
		{
			ft_putchar(board->array[y][x]);
			x++;
		}
		ft_putchar('\n');
		y++;
	}
}

static int	file(int fd)
{
	char	buffer[4096];
	int		num_bytes_read;

	if (fd == -1)
		return (0);
	ft_bzero(buffer, 4096);
	num_bytes_read = read(fd, buffer, 4096);
	buffer[num_bytes_read] = 0;
	if (num_bytes_read == 42)
		return (1);
	return (0);
}

int			main(int argc, char **argv)
{
	t_list	*list;
	t_board	*board;
	int		fd;
	int		temp;
	int		nb_forms;

	nb_forms = 0;
	if (argc != 2)
	{
		ft_putendl("usage: ./fillit file_name");
		exit(EXIT_FAILURE);
	}
	fd = open(argv[1], O_RDONLY);
	temp = open(argv[1], O_RDONLY);
	if ((list = get_lst(fd, &nb_forms)) == NULL || file(temp) == 1)
		return (ft_error());
	board = solve(list, &nb_forms);
	print_board(board);
	exit(EXIT_SUCCESS);
}
