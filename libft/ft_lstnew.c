/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 20:34:12 by mmonahan          #+#    #+#             */
/*   Updated: 2020/02/14 19:41:24 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*list;

	list = ft_memalloc(sizeof(t_list));
	if (!list)
		return (NULL);
	if (content)
	{
		list->content_size = content_size;
		list->content = ft_memalloc(list->content_size);
		if (list->content)
			ft_memcpy(list->content, content, list->content_size);
	}
	else
	{
		list->content_size = 0;
		list->content = NULL;
	}
	list->next = NULL;
	return (list);
}
