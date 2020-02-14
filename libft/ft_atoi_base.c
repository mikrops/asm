/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 18:58:10 by mmonahan          #+#    #+#             */
/*   Updated: 2020/02/14 19:41:24 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	count_base(char *str)
{
	size_t	length;

	length = 0;
	while (ft_isdigit(str[length]) || ft_isalpha(str[length]))
		length++;
	return (length);
}

/*
**	Возвращает десятичное число переведенное из строки в системе счисления base
*/

int		ft_atoi_base(char *str, int base)
{
	int		rezult;
	size_t	len;
	int		i;

	i = 0;
	rezult = 0;
	if (base < 2 || base > 16)
		return (0);
	if (base == 16)
		i += 2;
	len = count_base(str) - i - 1;
	while (ft_isdigit(str[i]) || ft_isalpha(str[i]))
	{
		if (str[i] >= 'A' && str[i] <= 'F')
			rezult += (str[i] - 55) * ft_pow(base, len--);
		else if (str[i] >= 'a' && str[i] <= 'f')
			rezult += (str[i] - 87) * ft_pow(base, len--);
		else if (ft_isdigit(str[i]))
			rezult += (str[i] - 48) * ft_pow(base, len--);
		else
			return (0);
		i++;
	}
	return (rezult);
}
