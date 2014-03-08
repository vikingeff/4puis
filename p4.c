/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p4.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 15:03:18 by gleger            #+#    #+#             */
/*   Updated: 2014/03/08 17:59:54 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <p4.h>

void			show_usage()
{
	ft_puterr(P4_USAGE);
	ft_puterr(P4_RULE);
	ft_puterr("\n");
}

int				main(int argc, char **argv)
{
	t_gboard			*p4;
	int					move;
	
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
		/*ft_putchar('\n');
		ft_play(p4, 2, 1);
		ft_play(p4, 2, 2);
		print_board(p4);
		ft_putchar('\n');
		ft_play(p4, 2, 1);
		ft_play(p4, 2, 2);
		print_board(p4);
		ft_putchar('\n');
		ft_play(p4, 2, 1);
		ft_play(p4, 2, 2);
		print_board(p4);
		ft_putchar('\n');
		ft_play(p4, 2, 3);
		ft_play(p4, 1, 2);
		print_board(p4);
		ft_putchar('\n');
		ft_play(p4, 2, 1);
		ft_play(p4, 2, 2);
		ft_play(p4, 10, 2);
		print_board(p4);
		ft_putchar('\n');*/
		if ((move = ft_player()) == -1)
			ft_putendl_fd("Columns are only numbers between ", 2);
		else
			ft_play(p4, move, 1);
		print_board(p4);
		ft_putchar('\n');
	}
	return (0);
}
