/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sizitout <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 16:35:20 by sizitout          #+#    #+#             */
/*   Updated: 2024/02/23 00:05:20 by sizitout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_rectangular(t_stock *stock)
{
	int	i;

	i = 0;
	while (stock->map[i])
	{
		if (ft_strlenlong(stock->map[i]) != stock->map_width)
			return (0);
		i++;
	}
	return (1);
}

// Verifier si les caractere ne sont pas indesirable

int	check_char(t_stock *stock)
{
	int	i;
	int	j;

	i = 0;
	while (stock->map[i])
	{
		j = 0;
		while (stock->map[i][j])
		{
			if (stock->map[i][j] != 'E' && stock->map[i][j] != 'P'
				&& stock->map[i][j] != 'C')
			{
				if (stock->map[i][j] != '1' && stock->map[i][j] != '0')
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

// Si la carte contient 1 sortie 1 item
//et 1 player la carte est good sinon false OK
int	check_epc(t_stock *stock)
{
	int	i;
	int	j;

	i = 0;
	while (stock->map[i])
	{
		j = 0;
		while (stock->map[i][j])
		{
			if (stock->map[i][j] == 'E')
				stock->exit++;
			if (stock->map[i][j] == 'P')
				stock->player++;
			if (stock->map[i][j] == 'C')
				stock->item++;
			j++;
		}
		i++;
	}
	if (!(check_epc_count(stock)))
		return (0);
	return (1);
}

int	check_epc_count(t_stock *stock)
{
	if (stock->exit != 1)
		return (0);
	if (stock->player != 1)
		return (0);
	if (stock->item < 1)
		return (0);
	return (1);
}
