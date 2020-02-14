/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 01:03:25 by mmonahan          #+#    #+#             */
/*   Updated: 2020/02/14 19:41:24 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Allocates (with malloc(3)) and returns a “fresh” substring
**	from the string given as argument. The substring begins at
**	indexstart and is of size len. If start and len aren’t refer-
**	ing to a valid substring, the behavior is undefined. If the
**	allocation fails, the function returns NULL.
**
**	Распределяет (с помощью malloc (3)) и возвращает «свежую» подстроку
**	из строки, заданной в качестве аргумента. Подстрока начинается с indexstart
**	и имеет размер len. Если start и len не ссылаются на допустимую подстроку,
**	поведение не определено. Если распределение завершается неудачно, функция
**	возвращает NULL.
*/

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*tmp;
	char	*ts;

	if (!s)
		return (NULL);
	s = s + start;
	tmp = ft_memalloc(sizeof(char) * len + 1);
	if (!tmp)
		return (NULL);
	ts = tmp;
	while (len)
	{
		*tmp++ = *s++;
		len--;
	}
	return (ts);
}
