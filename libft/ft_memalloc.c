/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 05:14:06 by mmonahan          #+#    #+#             */
/*   Updated: 2020/02/14 19:41:24 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Description: Allocates (with malloc(3)) and returns a “fresh” memory area.
**	The memory allocated is initialized to 0. If the allocation fails,
**	the function returns NULL.
**
**	Param. #1: The size of the memory that needs to be allocated.
**	Return value: The allocated memory area.
**	Libc functions: malloc(3)
**
**
**	Описание: выделяет (с помощью malloc (3)) и возвращает «свежую» область
**	памяти. Выделенная память инициализируется равным 0. Если выделение не
**	выполняется, функция возвращает NULL.
**
**	Пар. # 1: Размер памяти, которая должна быть выделена.
**	Возвращаемое значение: выделенная область памяти.
**	Функции Libc: malloc (3)
*/

void	*ft_memalloc(size_t size)
{
	unsigned char	*tmp;

	tmp = (unsigned char*)malloc(sizeof(unsigned char) * size);
	if (!tmp)
		return (NULL);
	ft_memset(tmp, 0, size);
	return (tmp);
}
