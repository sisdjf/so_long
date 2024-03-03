/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sizitout <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 20:07:41 by sizitout          #+#    #+#             */
/*   Updated: 2024/02/25 18:29:00 by sizitout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_all(t_stock *stock)
{
	free_tab(stock->map);
	check_xpm(stock);
	mlx_clear_window(stock->mlx, stock->window);
	mlx_destroy_window(stock->mlx, stock->window);
	mlx_destroy_display(stock->mlx);
	free(stock->mlx);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_stock	stock;

	ft_bzero(&stock, sizeof(t_stock));
	if (argc != 2)
		return (ft_printf("Error\nWrong number of arguments"), 0);
	{
		if (!check_ber(argv[1]))
			return (ft_printf("ERROR \nFile is not a .ber\n"), 1);
		if (!stock_map(argv[1], &stock))
			return (ft_printf("Error \nWrong file"), 1);
		stock_map_size(&stock);
		coord_player(&stock);
		if (!check_parsing(&stock))
			return (free_tab(stock.map), 1);
		stock.mlx = mlx_init();
		if (!stock.mlx)
			return (free_tab(stock.map), 1);
		init_img(&stock);
		stock.window = mlx_new_window(stock.mlx,
				stock.map_width * 64, stock.map_height * 64, "SO LONG TENNIS");
		if (!stock.window)
			return (free_all(&stock), 1);
		check_mlx(&stock);
	}
	return (0);
}
