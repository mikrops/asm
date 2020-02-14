/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 17:45:54 by mmonahan          #+#    #+#             */
/*   Updated: 2020/02/14 19:41:24 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Description: Allocates (with malloc(3)) and returns a “fresh” string
**	endin with ’\0’, result of the concatenation of s1 and s2. If the allocation
**	fails the function returns NULL.
**
**	Param. #1: The prefix string.
**	Param. #2: The suffix string.
**	Return value: The “fresh” string result of the concatenation of
**	 the 2 strings.
**	Libc functions: malloc(3)
**
**
**	Описание: Распределяет (с помощью malloc (3)) и возвращает «свежую» строку,
**	оканчивающуюся на «0», результат объединения s1 и s2. Если распределение
**	завершается неудачно, функция возвращает NULL.
**
**	Пар. # 1: Строка префикса.
**	Пар. # 2: Строка суффикса.
**	Возвращаемое значение: «свежая» строка результата объединения двух строк.
**	Функции Libc: malloc (3)
*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	char	*t_str;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = ft_memalloc(sizeof(char) * (s1_len + s2_len) + 1);
	if (!str)
		return (NULL);
	t_str = str;
	while (s1_len)
	{
		*str++ = *s1++;
		s1_len--;
	}
	while (s2_len)
	{
		*str++ = *s2++;
		s2_len--;
	}
	*str = '\0';
	return (t_str);
}
