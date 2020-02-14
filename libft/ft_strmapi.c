/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 21:20:54 by mmonahan          #+#    #+#             */
/*   Updated: 2020/02/14 19:41:24 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Description: Applies the function f to each character of the string passed
**	as argument by giving its index as x argument to create a “fresh” new
**	string (with malloc(3)) resulting from the successive applications of f.
**
**	Param. #1: The string to map.
**	Param. #2: The function to apply to each character of s and its index.
**	Return value: The “fresh” string created from the successive
**	applications of f.
**	Libc functions: malloc(3)
**
**
**	Описание: Применяет функцию f к каждому символу строки, переданной в
**	качестве аргумента, указав ее индекс в качестве первого аргумента, чтобы
**	создать «свежую» новую строку (с malloc (3)), полученную в результате
**	последовательных применений f.
**
**	Пар. # 1: Строка для сопоставления.
**	Пары. # 2: функция, применяемая к каждому символу s и его индексу.
**	Возвращаемое значение: «свежая» строка, созданная из последовательных
**	приложений f.
**	Функции Libc: malloc (3)
*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*tmp;

	i = 0;
	if (!s || !f)
		return (NULL);
	tmp = ft_memalloc(ft_strlen(s) + 1);
	if (!tmp)
		return (NULL);
	while (s[i])
	{
		tmp[i] = f(i, s[i]);
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}
