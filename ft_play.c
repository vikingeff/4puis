/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_play.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 14:36:04 by fle-bach          #+#    #+#             */
/*   Updated: 2014/03/08 17:54:42 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <p4.h>
#include <stdio.h>

int			ft_player(void)
{
	int		temp_val;
	char	buff[BUFF_SIZE];
	char	*value;

	temp_val = 0;
	value = "";
	ft_putendl_fd("Where you wanna play:", 1);
	while (temp_val != -1 && temp_val != 1)
	{
		read(0, buff, BUFF_SIZE);
		if (ft_isdigit(buff[0]))
			value = ft_strjoin(value, buff);
		else if (buff[0] != 10)
			temp_val = -1;
		else
			temp_val = 1;
	}
	if (temp_val != -1)
		return (ft_atoi(value) - 1);
	return (temp_val);
}

int			ft_play(t_gboard *p4, int y, int player)
{
	int		save;

	save = p4->nb_lines - 1;
	if (player != 1 && player != 2)
		ft_putendl("This player doesn't exist.");
	else if (y >= 0 && y < p4->nb_columns)
	{
		while (save != -1 && p4->board[save][y] != 0)
			save--;
		if (save == -1)
			ft_putendl("Column is full");
		else
			p4->board[save][y] = player;
	}
	else
		ft_putendl("This column doesn't exist.");
	return (0);
}
