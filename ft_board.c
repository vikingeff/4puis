/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_board.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 12:24:59 by gleger            #+#    #+#             */
/*   Updated: 2014/03/08 12:48:54 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <p4.h>

t_gboard		*init_game()
{
	t_gboard			*board;

	board = malloc(sizeof (t_gboard));
	if (board == NULL)
		return NULL;
	return (board);
}

int				memset_board(t_gboard *grid)
{
	int					loop;
	int					*buffer;

	loop = -1;
	while (++loop < grid->nb_lines)
	{
		buffer = malloc(grid->nb_columns * sizeof(int));
		if (buffer == NULL)
			return (-1);
		
		grid->board[loop] = buffer;
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
	}
}