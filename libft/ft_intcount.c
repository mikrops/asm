/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 16:31:44 by mmonahan          #+#    #+#             */
/*   Updated: 2019/11/21 19:37:55 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_intcount(int n)
{
	size_t count;

	count = 0;
	if (n == 0)
		count++;
	else
		while (n)
		{
			n /= 10;
			count++;
		}
	return (count);
}
