/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sizitout <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 21:27:40 by sizitout          #+#    #+#             */
/*   Updated: 2024/02/25 18:19:12 by sizitout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	totalcharinfile(int file)
{
	char	tmp[1024];
	int		len;
	int		byte;

	len = 0;
	while (1)
	{
		byte = read(file, tmp, 1024);
		if (byte <= 0)
			break ;
		len += byte;
	}
	close(file);
	return (len);
}

int	stock_map(char *path, t_stock *stock)
{
	int		file;
	int		nbchar;
	char	*map_line;
	int		i;

	file = open(path, O_RDONLY);
	if (file < 0)
		return (0);
	nbchar = totalcharinfile(file);
	file = open(path, O_RDONLY);
	if (file < 0)
		return (0);
	map_line = ft_calloc(sizeof(char), nbchar + 1);
	if (!map_line)
		return (0);
	i = 0;
	if (read(file, map_line, nbchar) < 1)
		return (free(map_line), 0);
	check_empty_line(map_line, stock);
	stock->map = ft_split(map_line, '\n');
	free(map_line);
	if (!stock->map)
		return (0);
	close (file);
	return (1);
}

void	stock_map_size(t_stock *stock)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (stock->map[i][j])
	{
		j++;
	}
	stock->map_width = j;
	while (stock->map[i])
	{
		i++;
	}
	stock->map_height = i;
}
