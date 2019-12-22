/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dir.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 14:48:49 by mmonahan          #+#    #+#             */
/*   Updated: 2019/12/22 16:54:10 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** get T_DIR [%int] [%:label]
*/

int	get_dir(const char *str)
{
	int i;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i++] != DIRECT_CHAR)
		return (0);
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
		return (0);
	while (ft_isspace(str[i]))
		i++;
	if (str[i] != '\0')
		return (0);
	return (T_DIR);
}
