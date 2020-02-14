/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 20:11:36 by mmonahan          #+#    #+#             */
/*   Updated: 2020/02/14 19:41:24 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Возвращает строрку до символа 'c'
*/

char	*ft_strcut(const char *str, int c)
{
	int		i;
	int		len;
	char	*rezult;

	i = 0;
	len = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == c)
			break ;
		i++;
		len++;
	}
	i = 0;
	rezult = ft_memalloc(len + 1);
	while (i < len)
	{
		rezult[i] = str[i];
		i++;
	}
	rezult[i] = '\0';
	return (rezult);
}
