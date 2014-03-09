/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_play.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 14:36:04 by fle-bach          #+#    #+#             */
/*   Updated: 2014/03/09 01:55:03 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <p4.h>

char		*ft_temp(char *value, char *buff)
{
	char	*temp;

	temp = value;
	value = ft_strjoin(temp, buff);
	free(temp);
	return (value);
}

int			ft_player(void)
{
	int		temp_val;
	char	buff[BUFF_SIZE + 1];
	char	*value;

	temp_val = 0;
	value = ft_strdup("");
	ft_putendl_fd("Where you wanna play:", 1);
	while (temp_val != -1 && temp_val != 1)
	{
		read(0, buff, BUFF_SIZE);
		buff[1] = '\0';
		if (ft_isdigit(buff[0]))
			value = ft_temp(value, buff);
		else if (buff[0] != 10)
			temp_val = -1;
		else
			temp_val = 1;
	}
	if (temp_val != -1)
		temp_val = ft_atoi(value) - 1;
	while (buff[0] != 10)
		read(0, buff, BUFF_SIZE);
	free(value);
	return (temp_val);
}

int			player(t_gboard *p4, char *cl, int player)
{
	int		move;
	int		win;

	move = -1;
	while (move == -1)
	{
		ft_putstr("player ");
		ft_putnbr(player);
		ft_putendl(" :");
		if ((move = ft_player()) == -1)
		{
			ft_putstr(cl);
			ft_putendl_fd("Columns are only numbers between ", 2);
		}
		else
		{
			ft_putstr(cl);
			move = ft_play(p4, move, player);
		}
		print_board(p4);
		if (move != -1)
			win = check_win(p4, player);
	}
	return (win);
}

int			ft_play(t_gboard *p4, int y, int player)
{
	int		save;
	int		check;

	check = -1;
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
		{
			check = 0;
			p4->board[save][y] = player;
		}
	}
	else
		ft_putendl("This column doesn't exist.");
	return (check);
}
