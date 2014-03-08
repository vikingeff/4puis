/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_win.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-bach <fle-bach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 19:25:06 by fle-bach          #+#    #+#             */
/*   Updated: 2014/03/08 21:08:43 by fle-bach         ###   ########.fr       */
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
				return (1);
			y++;
		}
		x--;
	}
	return (0);
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
				return (1);
			x--;
		}
		y++;
	}
	return (0);
}

int			check_win(t_gboard *p4, int player)
{
	if (check_lines(p4, player) == 1 || check_columns(p4, player) == 1
		|| check_left(p4, player) == 1 || check_right(p4, player) == 1)
	{
		ft_putstr("player ");
		ft_putchar((player + 48));
		ft_putendl(" won.");
		return (1);
	}
	return (0);
}
