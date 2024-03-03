/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sizitout <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 22:50:11 by sizitout          #+#    #+#             */
/*   Updated: 2024/02/25 18:01:42 by sizitout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_nb_line_map(t_stock *stock)
{
	int	i;

	i = 0;
	while (stock->map[i] != NULL)
		i++;
	return (i);
}

int	check_path(char **copy_map)
{
	int	i;
	int	j;

	i = 0;
	while (copy_map[i])
	{
		j = 0;
		while (copy_map[i][j])
		{
			if (copy_map[i][j] == 'E')
				return (ft_printf("Error\nExit not accessible\n"), 0);
			if (copy_map[i][j] == 'C')
				return (ft_printf("Error\nCoin not accessible\n"), 0);
			j++;
		}
		i++;
	}
	return (1);
}

int	flood_fill(char **copy_map, int i, int j)
{
	if (copy_map[i][j] == '1' || copy_map[i][j] == 'Z' || copy_map[i][j] == 'E')
	{
		if (copy_map[i][j] == 'E')
			copy_map[i][j] = 'Z';
		return (0);
	}
	copy_map[i][j] = 'Z';
	if (flood_fill(copy_map, i - 1, j) || flood_fill(copy_map, i + 1, j)
		|| flood_fill(copy_map, i, j - 1) || flood_fill(copy_map, i, j + 1))
		return (1);
	return (0);
}

int	pathfinding(t_stock *stock)
{
	char	**copy_map;
	int		i;

	i = 0;
	copy_map = malloc(sizeof(char *) * (ft_nb_line_map(stock) +1));
	if (!copy_map)
		return (0);
	while (i < ft_nb_line_map(stock))
	{
		copy_map[i] = ft_strdup(stock->map[i]);
		if (!copy_map[i])
		{
			while (i > 0)
				free(copy_map[--i]);
			return (free(copy_map), 0);
		}
		i++;
	}
	copy_map[i] = NULL;
	flood_fill(copy_map, stock->coord_i, stock->coord_j);
	if (!check_path(copy_map))
		return (free_tab(copy_map), 0);
	free_tab(copy_map);
	return (1);
}
