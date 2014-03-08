/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p4.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 15:03:18 by gleger            #+#    #+#             */
/*   Updated: 2014/03/08 11:40:16 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <p4.h>

void			show_usage()
{
	ft_puterr(P4_USAGE);
	ft_puterr(P4_RULE);
	ft_puterr("\n");
}

t_gboard		*init_game()
{
	t_gboard			*board;

	board = malloc(sizeof (t_gboard));
	if (board == NULL)
		return NULL;
	return (board);
}

int				main(int argc, char **argv)
{
	t_gboard			*p4;

	if ((p4 = init_game()) == NULL)
		return (-1);
	if (argc != 3)
	{
		show_usage();
		return (-1);
	}
	else
	{
		check_size(argv[1], argv[2], p4);
	}
	return (0);
}
