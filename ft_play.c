/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_play.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-bach <fle-bach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 14:36:04 by fle-bach          #+#    #+#             */
/*   Updated: 2014/03/08 16:57:50 by fle-bach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <p4.h>

void	ft_player(t_gboard *p4, int player)
{
	int		y;
	char	*buff;
	char	*nb;

	y = 0;
	nb = ft_strdup("");
	ft_putendl_fd("choose your columns :", 2);
	while (y != -1 && read(0, buff, BUFF_SIZE))
	{
		if (buff[0] >= '\0' && buff[0] <= '9')
			nb = ft_strjoin(nb, buff);
		else
		{
			y = -1;
			ft_putendl_fd("error charactere", 2);
		}
	}
	if (y != -1)
	{
		y = ft_atoi(nb) - 1;
		ft_play(p4, y, player);
	}
}

void	ft_play(t_gboard *p4, int y, int player)
{
	int		save;

	save = p4->nb_lines - 1;
	if (player != 1 || player != 2)
		ft_putendl_fd("error with player", 2);
	else if (y >= 0 && y < p4->nb_columns)
	{
		while (save != -1 && p4->board[save][y] != 0)
			save--;
		if (save == -1)
			ft_putendl_fd("error lines", 2);
		else
			p4->board[save][y] = player;
	}
	else
		ft_putendl_fd("error columns", 2);
}
