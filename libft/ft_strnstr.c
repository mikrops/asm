/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 22:55:08 by mmonahan          #+#    #+#             */
/*   Updated: 2020/02/14 19:41:24 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	i = 0;
	if (!*needle)
		return ((char*)haystack);
	while (*haystack && len)
	{
		if (*haystack == *needle)
		{
			while (haystack[i] == needle[i] && needle[i] && len - i)
				i++;
			if (!needle[i])
				return ((char*)haystack);
		}
		haystack++;
		len--;
		i = 0;
	}
	return (NULL);
}
