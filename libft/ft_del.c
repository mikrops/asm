/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 20:11:56 by mmonahan          #+#    #+#             */
/*   Updated: 2019/09/24 20:03:36 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_del(void *content, size_t size)
{
	if (!content)
		return ;
	(void)size;
	free(content);
}
