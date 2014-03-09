/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_win.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 19:25:06 by fle-bach          #+#    #+#             */
/*   Updated: 2014/03/09 01:30:07 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <p4.h>

int			check_lines(t_gboard *p4, int player)
{
	int		x;
	int		y;
	int		check;

	x = p4->nb_lines - 1;
	while (x != -1)
	{
		check = 0;
		y = 0;
		while (y != p4->nb_columns)
		{
			if (p4->board[x][y] == player)
				check++;
			else
				check = 0;
			if (check == 4)
				return (check);
			y++;
		}
		x--;
	}
	return (check);
}

int			check_columns(t_gboard *p4, int player)
{
	int		x;
	int		y;
	int		check;

	y = 0;
	while (y != p4->nb_columns)
	{
		check = 0;
		x = p4->nb_lines - 1;
		while (x != -1)
		{
			if (p4->board[x][y] == player)
				check++;
			else
				check = 0;
			if (check == 4)
				return (check);
			x--;
		}
		y++;
	}
	return (check);
}

int			check_win(t_gboard *p4, int player)
{
	if (check_lines(p4, player) == 4 || check_columns(p4, player) == 4
		|| check_left(p4, player) == 4 || check_right(p4, player) == 4)
	{
		ft_putstr("player ");
		ft_putchar((player + 48));
		ft_putendl(" wins.");
		return (1);
	}
	return (0);
}
