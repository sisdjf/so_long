/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sizitout <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 15:56:47 by sizitout          #+#    #+#             */
/*   Updated: 2024/02/25 18:26:37 by sizitout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	keys(int keysym, t_stock *stock)
{
	if (keysym == XK_Escape)
		mlx_loop_end(stock->mlx);
	if (keysym == 119 || keysym == 65362)
		move_up(stock);
	if (keysym == 115 || keysym == 65364)
		move_down(stock);
	if (keysym == 97 || keysym == 65361)
		move_left(stock);
	if (keysym == 100 || keysym == 65363)
		move_right(stock);
	return (0);
}

void	move_left2(t_stock *stock)
{
	mlx_put_image_to_window(stock->mlx, stock->window, stock->img_player,
		stock->coord_j * 64, stock->coord_i * 64);
	mlx_put_image_to_window(stock->mlx, stock->window, stock->img_background,
		(stock->coord_j + 1) * 64, stock->coord_i * 64);
		stock->moves++;
	ft_printf("move count %d\n", stock->moves);
}

void	move_left(t_stock *stock)
{
	if (stock->map[stock->coord_i][stock->coord_j - 1] == '1')
		return ;
	else if (stock->map[stock->coord_i][stock->coord_j - 1] == '0')
	{
		stock->map[stock->coord_i][stock->coord_j] = '0';
		stock->map[stock->coord_i][stock->coord_j - 1] = 'P';
		stock->coord_j--;
	}
	else if (stock->map[stock->coord_i][stock->coord_j - 1] == 'C')
	{
		stock->item--;
		stock->map[stock->coord_i][stock->coord_j] = '0';
		stock->map[stock->coord_i][stock->coord_j - 1] = 'P';
		stock->coord_j--;
	}
	else if (stock->map[stock->coord_i][stock->coord_j - 1] == 'E')
	{
		if (stock->item != 0)
			return ;
		mlx_loop_end(stock->mlx);
		ft_printf("WINNER!!!\n");
		return ;
	}
	move_left2(stock);
}

void	move_right2(t_stock *stock)
{
	mlx_put_image_to_window(stock->mlx, stock->window, stock->img_player,
		stock->coord_j * 64, stock->coord_i * 64);
	mlx_put_image_to_window(stock->mlx, stock->window, stock->img_background,
		(stock->coord_j - 1) * 64, stock->coord_i * 64);
		stock->moves++;
	ft_printf("move count %d\n", stock->moves);
}

void	move_right(t_stock *stock)
{
	if (stock->map[stock->coord_i][stock->coord_j + 1] == '1')
		return ;
	else if (stock->map[stock->coord_i][stock->coord_j + 1] == '0')
	{
		stock->map[stock->coord_i][stock->coord_j] = '0';
		stock->map[stock->coord_i][stock->coord_j + 1] = 'P';
		stock->coord_j++;
	}
	else if (stock->map[stock->coord_i][stock->coord_j + 1] == 'C')
	{
		stock->item--;
		stock->map[stock->coord_i][stock->coord_j] = '0';
		stock->map[stock->coord_i][stock->coord_j + 1] = 'P';
		stock->coord_j++;
	}
	else if (stock->map[stock->coord_i][stock->coord_j + 1] == 'E')
	{
		if (stock->item != 0)
			return ;
		mlx_loop_end(stock->mlx);
		ft_printf("WINNER!!!\n");
		return ;
	}
	move_right2(stock);
}
