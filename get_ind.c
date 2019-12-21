/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ind.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 14:50:03 by mmonahan          #+#    #+#             */
/*   Updated: 2019/12/21 17:28:28 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** get T_IND [int] [:label]
*/

int	get_ind(const char *str)
{
	int i;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == LABEL_CHAR)
	{
		i++;
		while (str[i] != '\0' && ft_strchr(LABEL_CHARS, str[i]))
			i++;
	}
	else if (ft_isdigit(str[i]) || str[i] == '-')
	{
		i += str[i] == '-' ? 1 : 0;
		while (ft_isdigit(str[i]))
			i++;
	}
	else
		return (ERR_BAD_TOKEN_ARGUMENT);
	while (ft_isspace(str[i]))
		i++;
	if (str[i] != '\0')
		return (ERR_BAD_TOKEN_ARGUMENT);
	return (T_IND);
}
