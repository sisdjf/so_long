/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sizitout <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 16:00:31 by sizitout          #+#    #+#             */
/*   Updated: 2024/02/10 19:04:51 by sizitout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_first_line(t_stock *stock)
{
	int	j;

	j = 0;
	while (stock->map[0][j])
	{
		if (stock->map[0][j] != '1')
		{
			return (0);
		}
		j++;
	}
	return (1);
}

int	check_last_line(t_stock *stock)
{
	int	i;
	int	j;

	i = stock->map_height - 1;
	j = 0;
	while (stock->map[i][j])
	{
		if (stock->map[i][j] != '1')
		{
			return (0);
		}
		j++;
	}
	return (1);
}

int	check_first_col(t_stock *stock)
{
	int	i;

	i = 0;
	while (stock->map[i])
	{
		if (stock->map[i][0] != '1')
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_last_col(t_stock *stock)
{
	int	i;
	int	j;

	i = 0;
	j = stock->map_width - 1;
	while (stock->map[i])
	{
		if (stock->map[i][j] != '1')
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_walls(t_stock *stock)
{
	if (!check_first_line(stock))
		return (0);
	if (!check_last_line(stock))
		return (0);
	if (!check_first_col(stock))
		return (0);
	if (!check_last_col(stock))
		return (0);
	return (1);
}
