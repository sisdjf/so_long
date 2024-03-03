/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sizitout <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 18:17:19 by sizitout          #+#    #+#             */
/*   Updated: 2024/02/21 04:01:05 by sizitout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Si la carte est bien un .ber elle est valide sinon non faux

int	check_ber(char *str)
{
	int	len;

	len = ft_strlenlong(str);
	if (!ft_strcmp(&str[len - 4], ".ber"))
		return (1);
	return (0);
}
