/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_reg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 14:47:04 by mmonahan          #+#    #+#             */
/*   Updated: 2019/12/21 14:47:04 by mmonahan         ###   ########.fr       */
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
		return (ERR_BAD_TOKEN_ARGUMENT);
	if (ft_isdigit(str[i]) && ft_isdigit(str[i + 1]))
	{
		if (str[i] == '0' && str[i + 1] == '0')
			return (ERR_BAD_TOKEN_ARGUMENT);
		i += 2;
	}
	else if (ft_isdigit(str[i]))
	{
		if (str[i++] == '0')
			return (ERR_BAD_TOKEN_ARGUMENT);
	}
	else
		return (ERR_BAD_TOKEN_ARGUMENT);
	while (ft_isspace(str[i]))
		i++;
	if (str[i] != '\0')
		return (ERR_BAD_TOKEN_ARGUMENT);
	return (ERR_NORM);
}
