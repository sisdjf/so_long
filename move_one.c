/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sizitout <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 07:40:02 by sizitout          #+#    #+#             */
/*   Updated: 2024/02/25 18:26:52 by sizitout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up2(t_stock *stock)
{
	mlx_put_image_to_window(stock->mlx, stock->window, stock->img_player,
		stock->coord_j * 64, stock->coord_i * 64);
	mlx_put_image_to_window(stock->mlx, stock->window, stock->img_background,
		stock->coord_j * 64, (stock->coord_i + 1) * 64);
		stock->moves++;
	ft_printf("move count %d\n", stock->moves);
}

void	move_up(t_stock *stock)
{
	if (stock->map[stock->coord_i - 1][stock->coord_j] == '1')
		return ;
	else if (stock->map[stock->coord_i - 1][stock->coord_j] == '0')
	{
		stock->map[stock->coord_i][stock->coord_j] = '0';
		stock->map[stock->coord_i - 1][stock->coord_j] = 'P';
		stock->coord_i--;
	}
	else if (stock->map[stock->coord_i - 1][stock->coord_j] == 'C')
	{
		stock->item--;
		stock->map[stock->coord_i][stock->coord_j] = '0';
		stock->map[stock->coord_i - 1][stock->coord_j] = 'P';
		stock->coord_i--;
	}
	else if (stock->map[stock->coord_i - 1][stock->coord_j] == 'E')
	{
		if (stock->item != 0)
			return ;
		mlx_loop_end(stock->mlx);
		ft_printf("WINNER!!!\n");
		return ;
	}
	move_up2(stock);
}

void	move_down2(t_stock *stock)
{
	mlx_put_image_to_window(stock->mlx, stock->window, stock->img_player,
		stock->coord_j * 64, stock->coord_i * 64);
	mlx_put_image_to_window(stock->mlx, stock->window, stock->img_background,
		stock->coord_j * 64, (stock->coord_i - 1) * 64);
		stock->moves++;
	ft_printf("move count %d\n", stock->moves);
}

void	move_down(t_stock *stock)
{
	if (stock->map[stock->coord_i + 1][stock->coord_j] == '1')
		return ;
	else if (stock->map[stock->coord_i + 1][stock->coord_j] == '0')
	{
		stock->map[stock->coord_i][stock->coord_j] = '0';
		stock->map[stock->coord_i + 1][stock->coord_j] = 'P';
		stock->coord_i++;
	}
	else if (stock->map[stock->coord_i + 1][stock->coord_j] == 'C')
	{
		stock->item--;
		stock->map[stock->coord_i][stock->coord_j] = '0';
		stock->map[stock->coord_i + 1][stock->coord_j] = 'P';
		stock->coord_i++;
	}
	else if (stock->map[stock->coord_i + 1][stock->coord_j] == 'E')
	{
		if (stock->item != 0)
			return ;
		mlx_loop_end(stock->mlx);
		ft_printf("WINNER!!!\n");
		return ;
	}
	move_down2(stock);
}
