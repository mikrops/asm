/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 19:42:45 by mmonahan          #+#    #+#             */
/*   Updated: 2020/02/14 19:41:24 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Уточнить на счет ft_isspace(c), что проверять на пробелы
*/

char	*ft_strtrim(char const *s)
{
	char	*str;
	char	*tmp;
	size_t	len;

	if (!s)
		return (NULL);
	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	len = ft_strlen(s);
	while (len && (s[len - 1] == ' ' || s[len - 1] == '\n'
				|| s[len - 1] == '\t'))
		len--;
	str = ft_memalloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	tmp = str;
	while (len)
	{
		*str++ = *s++;
		len--;
	}
	return (tmp);
}
