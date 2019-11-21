/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 19:32:33 by mmonahan          #+#    #+#             */
/*   Updated: 2019/11/21 19:37:55 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*tempdst;
	const unsigned char	*tempsrc;
	unsigned char		chr;
	size_t				i;

	tempdst = dst;
	tempsrc = src;
	chr = c;
	i = 0;
	while (n)
	{
		tempdst[i] = tempsrc[i];
		if (tempsrc[i] == chr)
			return (dst + i + 1);
		i++;
		n--;
	}
	return (NULL);
}
