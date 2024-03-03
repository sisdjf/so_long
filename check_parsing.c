/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sizitout <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:19:31 by sizitout          #+#    #+#             */
/*   Updated: 2024/02/23 00:47:17 by sizitout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_empty_line(char *str, t_stock *stock)
{
	int	i;

	i = 0;
	(void)stock;
	while (str[i])
	{
		if (str[i] == '\n' && str[i +1] == '\n')
		{
			free(str);
			ft_printf("ERROR - map has empty line(s)\n");
			exit (1);
		}
		i++;
	}
	return (1);
}

int	check_size(t_stock *stock)
{
	if (stock->map_width * 64 > 1924 || stock->map_height * 64 > 1024)
		return (0);
	return (1);
}

int	check_parsing(t_stock *stock)
{
	if (!check_size(stock))
		return (ft_printf("ERROR - map not good size\n"), 0);
	if (!check_rectangular(stock))
		return (ft_printf("ERROR - the map is not rectangle\n"), 0);
	if (!check_epc(stock))
		return (ft_printf("ERROR - with the Exit or Player or Coin\n"), 0);
	if (!check_char(stock))
		return (ft_printf("ERROR - unwanted character\n"), 0);
	if (!check_walls(stock))
		return (ft_printf("ERROR - invalid walls\n"), 0);
	if (!pathfinding(stock))
		return (0);
	return (1);
}
