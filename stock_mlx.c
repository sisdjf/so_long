/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sizitout <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 23:41:45 by sizitout          #+#    #+#             */
/*   Updated: 2024/02/22 16:36:26 by sizitout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	coord_player(t_stock *stock)
{
	int	i;
	int	j;

	i = 0;
	while (stock->map[i])
	{
		j = 0;
		while (stock->map[i][j])
		{
			if (stock->map[i][j] == 'P')
			{
				stock->coord_i = i;
				stock->coord_j = j;
			}
			j++;
		}
		i++;
	}
}

int	check_xpm(t_stock *stock)
{
	if (stock->img_player)
		mlx_destroy_image(stock->mlx, stock->img_player);
	if (stock->img_exit)
		mlx_destroy_image(stock->mlx, stock->img_exit);
	if (stock->img_coin)
		mlx_destroy_image(stock->mlx, stock->img_coin);
	if (stock->img_background)
		mlx_destroy_image(stock->mlx, stock->img_background);
	if (stock->img_wall)
		mlx_destroy_image(stock->mlx, stock->img_wall);
	if (stock->copy_map)
		free_tab(stock->copy_map);
	return (1);
}
