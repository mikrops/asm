/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 18:11:41 by mmonahan          #+#    #+#             */
/*   Updated: 2020/02/14 19:41:24 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	**str;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	if (!(str = ft_memalloc(sizeof(char*) * (ft_wordcount(s, c) + 1))))
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			if (!(str[i] = ft_strsub(s, 0, ft_charcount(s, c))))
			{
				ft_strfree(str, i);
				return (NULL);
			}
			i++;
			s += ft_charcount(s, c);
		}
		else
			s++;
	}
	str[i] = NULL;
	return (str);
}
