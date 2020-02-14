/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 04:36:59 by mmonahan          #+#    #+#             */
/*   Updated: 2020/02/14 19:41:24 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Description: Takes as a parameter the address of a string that need to be
**	freed with free(3), then sets its pointer to NULL.
**
**	Param. #1: The string’s address that needs to be freed and its pointer
**	set to NULL.
**	Return value: None.
**	Libc functions: Free(3).
**
**
**	Описание: принимает в качестве параметра адрес строки, которую необходимо
**	освободить с помощью free(3), а затем устанавливает ее указатель на NULL.
**
**	Пар. # 1: адрес строки, который должен быть освобожден, и указатель на
**	него равен NULL.
**	Возвращаемое значение: Нет.
**	Функции Libc: Free(3).
*/

void	ft_strdel(char **as)
{
	if (!as)
		return ;
	free(*as);
	*as = NULL;
}
