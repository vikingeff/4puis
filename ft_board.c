/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_board.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 12:24:59 by gleger            #+#    #+#             */
/*   Updated: 2014/03/08 21:38:58 by fle-bach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <p4.h>
#include <stdio.h>

t_gboard		*init_game(void)
{
	t_gboard			*board;

	board = malloc(sizeof(t_gboard));
	if (board == NULL)
		return (NULL);
	return (board);
}

int				memset_board(t_gboard *grid)
{
	int					loop;

	loop = -1;
	grid->board = malloc(grid->nb_lines * sizeof(int *));
	if (grid->board == NULL)
		return (-1);
	while (++loop < grid->nb_lines)
	{
		grid->board[loop] = malloc(grid->nb_columns * sizeof(int));
		if (grid->board[loop] == NULL)
			return (-1);
	}
	return (0);
}

void			bzero_board(t_gboard *grid)
{
	int					loop;
	int					index;

	loop = -1;
	index = -1;
	memset_board(grid);
	while (++loop < grid->nb_lines)
	{
		while (++index < grid->nb_columns)
			grid->board[loop][index] = 0;
		index = -1;
	}
}

void			print_board(t_gboard *grid)
{
	int					loop;
	int					index;
	int					val;

	loop = -1;
	while (++loop < grid->nb_lines)
	{
		index = -1;
		while (++index < grid->nb_columns)
		{
			val = grid->board[loop][index];
			if (val == 0)
				ft_putchar('_');
			else if (val == 1)
				ft_putstr("\033[0;31mR\033[0;37m");
			else if (val == 2)
				ft_putstr("\033[0;33mJ\033[0;37m");
			ft_putchar(' ');
		}
		ft_putchar('\n');
	}
	ft_putchar('\n');
}
