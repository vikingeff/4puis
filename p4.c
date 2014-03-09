/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p4.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 15:03:18 by gleger            #+#    #+#             */
/*   Updated: 2014/03/09 01:30:18 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <p4.h>
#include <stdio.h>

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
		ft_putendl("It's a draw.");
	return (check);
}

int				main(int argc, char **argv)
{
	t_gboard			*p4;
	int					move;
	int					win;
	int					game_index;

	win = 0;
	game_index = 0;
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
		srand(time(NULL));
		p4->ia_id = rand() % 2 + 1;
		printf("%d\n",ia_id);
		while (win == 0 && check_poss(p4))
		{
			game_index++;
			move = -1;
			while (move == -1)
			{
				ft_putendl("player 1 :");
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
			move = -1;
			while (move == -1 && win != 1)
			{
				ft_putendl("player 2 :");
				if ((move = ft_player()) == -1)
					ft_putendl_fd("Columns are only numbers between ", 2);
				else
					move = ft_play(p4, move, 2);
				if (move != -1)
				{
					win = check_win(p4, 2);
					print_board(p4);
				}
			}
		}
	}
	return (0);
}
