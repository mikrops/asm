/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 17:16:58 by mmonahan          #+#    #+#             */
/*   Updated: 2019/09/24 20:03:36 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	unsigned long long	tmp;
	int					minus;

	tmp = 0;
	while (ft_isspace(*str))
		str++;
	if ((*str == '-' || *str == '+') && ft_isdigit(*(str + 1)))
		str++;
	minus = *(str - 1) == '-' ? -1 : 1;
	while (ft_isdigit(*str))
	{
		if (tmp != (tmp * 10 / 10))
			return (minus == 1 ? -1 : 0);
		tmp = tmp * 10 + (*str - '0');
		str++;
	}
	if (tmp > 9223372036854775807)
		return (minus == 1 ? -1 : 0);
	return (tmp * minus);
}
