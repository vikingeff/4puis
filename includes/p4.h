/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p4.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 12:15:33 by gleger            #+#    #+#             */
/*   Updated: 2014/03/08 12:48:52 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __P4_H__
# define __P4_H__

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

# define	P4_ERROR "\033[0;31m#Error\033[0;37m"
# define	P4_WARNING "\033[0;33;m#Warning\033[0;37m"
# define	P4_USAGE "\033[0;31mUsage\033[0;37m"
# define	P4_RULE " ./puissance4 nb_lines, nb_columns"
# define	P4_SIZE " The board must be at least 6 lines and 7 columns big."
# define	P4_COORDS " Lines and columns must be numbers."

typedef struct s_gboard		t_gboard;

struct						s_gboard
{
	int		nb_lines;
	int		nb_columns;
	int		**board;
};

size_t			ft_strlen(const char *str);
void			ft_putstr(const char *str);
void			ft_putchar(const char c);
void			ft_puterr(const char *str);
void			ft_putendl(const char *str);
void			ft_putnbr(const int number);
void			ft_putstr_fd(const char *str, int fd);
void			ft_putchar_fd(const char c, int fd);
void			ft_putendl_fd(const char *str, int fd);
int				ft_atoi(const char *src);
t_gboard		*init_game();
void			check_size(char *line, char *col, t_gboard *board);
int				check_args(char *line, char *col);
int				memset_board(t_gboard *grid);
void			bzero_board(t_gboard *grid);

#endif		/* !__P4_H__ */
