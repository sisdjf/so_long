/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sizitout <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 00:55:44 by sizitout          #+#    #+#             */
/*   Updated: 2024/02/22 16:42:22 by sizitout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_img_mlx(t_stock *stock, int i, int j)
{
	i = -1;
	while (stock->map[++i])
	{
		j = -1;
		while (stock->map[i][++j])
		{
			if (stock->map[i][j] == 'C')
				mlx_put_image_to_window(stock->mlx, stock->window,
					stock->img_coin, j * 64, i * 64);
			else if (stock->map[i][j] == 'P')
				mlx_put_image_to_window(stock->mlx, stock->window,
					stock->img_player, j * 64, i * 64);
			else if (stock->map[i][j] == 'E')
				mlx_put_image_to_window(stock->mlx, stock->window,
					stock->img_exit, j * 64, i * 64);
			else if (stock->map[i][j] == '0')
				mlx_put_image_to_window(stock->mlx, stock->window,
					stock->img_background, j * 64, i * 64);
			else if (stock->map[i][j] == '1')
				mlx_put_image_to_window(stock->mlx, stock->window,
					stock->img_wall, j * 64, i * 64);
		}
	}
}

void	init_img(t_stock *stock)
{
	int	r;

	stock->img_player = mlx_xpm_file_to_image(stock->mlx, "picture/player.xpm",
			&r, &r);
	stock->img_exit = mlx_xpm_file_to_image(stock->mlx, "picture/exit.xpm", &r,
			&r);
	stock->img_coin = mlx_xpm_file_to_image(stock->mlx, "picture/coin.xpm", &r,
			&r);
	stock->img_wall = mlx_xpm_file_to_image(stock->mlx, "picture/mur.xpm", &r,
			&r);
	stock->img_background = mlx_xpm_file_to_image(stock->mlx, "picture/sol.xpm",
			&r, &r);
	if (!stock->img_player || !stock->img_background || !stock->img_exit
		|| !stock->img_coin || !stock->img_wall)
	{
		free_tab(stock->map);
		check_xpm(stock);
		mlx_destroy_display(stock->mlx);
		free(stock->mlx);
		ft_printf("Error initialising images\n");
		exit(1);
	}
}

int	quit_loop(t_stock *stock)
{
	mlx_loop_end(stock->mlx);
	return (0);
}

void	check_mlx(t_stock *stock)
{
	put_img_mlx(stock, 0, 0);
	mlx_hook(stock->window, 17, (1L << 17), quit_loop, stock);
	mlx_key_hook(stock->window, &keys, stock);
	mlx_loop(stock->mlx);
	check_xpm(stock);
	mlx_clear_window(stock->mlx, stock->window);
	mlx_destroy_window(stock->mlx, stock->window);
	mlx_destroy_display(stock->mlx);
	free(stock->mlx);
	free_tab(stock->map);
}
