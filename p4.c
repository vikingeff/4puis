/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p4.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 15:03:18 by gleger            #+#    #+#             */
/*   Updated: 2014/03/08 21:38:15 by fle-bach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <p4.h>

void			show_usage(void)
{
	ft_puterr(P4_USAGE);
	ft_puterr(P4_RULE);
	ft_puterr("\n");
}

int				check_poss(t_gboard *p4)
{
	int		y;
	int		check;

	check = 0;
	y = 0;
	while (y != p4->nb_columns)
	{
		if (p4->board[0][y] == 0)
			check++;
		y++;
	}
	if (check == 0)
		ft_putendl("match null");
	return (check);
}

int				main(int argc, char **argv)
{
	t_gboard			*p4;
	int					move;
	int					win;

	win = 0;
	if ((p4 = init_game()) == NULL)
		return (-1);
	if (argc != 3)
	{
		show_usage();
		return (-1);
	}
	else
	{
		if (check_size(argv[1], argv[2], p4) == -1)
			return (-1);
		bzero_board(p4);
		print_board(p4);
		while (win == 0 && check_poss(p4))
		{
			if ((move = ft_player()) == -1)
				ft_putendl_fd("Columns are only numbers between ", 2);
			else
				move = ft_play(p4, move, 1);
			if (move != -1)
			{
				win = check_win(p4, 1);
				print_board(p4);
			}
		}
	}
	return (0);
}
