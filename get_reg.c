/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_reg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 14:47:04 by mmonahan          #+#    #+#             */
/*   Updated: 2019/12/22 16:54:10 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** get T_REG [r1-r99] [r01-r99]
*/

int	get_reg(const char *str)
{
	int i;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i++] != 'r')
		return (0);
	if (ft_isdigit(str[i]) && ft_isdigit(str[i + 1]))
	{
		if (str[i] == '0' && str[i + 1] == '0')
			return (0);
		i += 2;
	}
	else if (ft_isdigit(str[i]))
	{
		if (str[i++] == '0')
			return (0);
	}
	else
		return (0);
	while (ft_isspace(str[i]))
		i++;
	if (str[i] != '\0')
		return (0);
	return (T_REG);
}
