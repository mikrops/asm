/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_rejoin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 19:07:16 by mmonahan          #+#    #+#             */
/*   Updated: 2019/11/21 19:37:55 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_rejoin(char *s1, char const *s2)
{
	char *tmp;

	tmp = ft_strjoin(s1, s2);
	free(s1);
	return (tmp);
}
