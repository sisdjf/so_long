/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sizitout <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:56:58 by sizitout          #+#    #+#             */
/*   Updated: 2024/02/24 14:28:16 by sizitout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "mlx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stock
{
	void	*mlx;
	void	*window;
	void	*img;
	void	*img_background;
	void	*img_wall;
	void	*img_player;
	void	*img_exit;
	void	*img_coin;
	char	**map;
	char	**copy_map;
	int		player;
	int		exit;
	int		item;
	int		map_width;
	int		map_height;
	int		coord_i;
	int		coord_j;
	int		moves;
	int		total_coin;

}			t_stock;

//MAP
int			stock_map(char *path, t_stock *stock);

int			check_ber(char *str);
int			check_first_line(t_stock *stock);
int			check_last_line(t_stock *stock);
int			check_first_col(t_stock *stock);
int			check_last_col(t_stock *stock);
int			check_walls(t_stock *stock);
int			check_rectangular(t_stock *stock);
int			check_char(t_stock *stock);
int			check_epc(t_stock *stock);
int			check_epc_count(t_stock *stock);
int			flood_fill(char **copy_map, int i, int j);
void		stock_map_size(t_stock *stock);
void		free_tab(char **str);
void		free_all(t_stock *stock);
int			keys(int keysym, t_stock *stock);
void		coord_player(t_stock *stock);
int			check_parsing(t_stock *stock);
int			check_xpm(t_stock *stock);
void		init_img(t_stock *stock);
void		put_img_mlx(t_stock *stock, int i, int j);
int			check_parsing(t_stock *stock);
int			check_size(t_stock *stock);
void		move_up(t_stock *stock);
void		move_down(t_stock *stock);
void		move_left(t_stock *stock);
void		move_right(t_stock *stock);
int			pathfinding(t_stock *stock);
void		check_mlx(t_stock *stock);
int			quit_loop(t_stock *stock);
int			ft_strlenlong(char *s);
int			ft_strcmp(char *s1, char *s2);
int			check_empty_line(char *str, t_stock *stock);

#endif