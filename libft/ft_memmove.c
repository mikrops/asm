/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 22:00:03 by mmonahan          #+#    #+#             */
/*   Updated: 2020/02/14 19:41:24 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*tempdst;
	const unsigned char	*tempsrc;
	size_t				i;

	if (dst == src)
		return (dst);
	tempdst = dst;
	tempsrc = src;
	i = 0;
	if (tempdst > tempsrc)
		while (len-- > 0)
			tempdst[len] = tempsrc[len];
	else
		while (i < len)
		{
			tempdst[i] = tempsrc[i];
			i++;
		}
	return (tempdst);
}
