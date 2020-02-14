/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 16:21:57 by mmonahan          #+#    #+#             */
/*   Updated: 2020/02/14 19:41:24 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	size_t	count;
	char	*str;

	count = n < 0 ? ft_intcount(n) + 1 : ft_intcount(n);
	if (!(str = ft_memalloc(sizeof(char) * count-- + 1)))
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		if (n == -2147483648)
		{
			n = -214748364;
			str[count--] = '8';
		}
		n *= -1;
	}
	if (n == 0)
		str[0] = '0';
	while (n)
	{
		str[count--] = n % 10 + '0';
		n /= 10;
	}
	return (str);
}
