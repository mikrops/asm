/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 20:51:43 by mmonahan          #+#    #+#             */
/*   Updated: 2020/02/14 19:41:24 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(f)(t_list *elem))
{
	t_list	*rezult;
	t_list	*tmp;

	if (!lst || !f)
		return (NULL);
	rezult = f(ft_lstnew(lst->content, lst->content_size));
	if (!rezult)
		return (NULL);
	tmp = rezult;
	lst = lst->next;
	while (lst)
	{
		rezult->next = f(ft_lstnew(lst->content, lst->content_size));
		if (!rezult)
		{
			ft_lstdel(&rezult, &ft_del);
			return (NULL);
		}
		rezult = rezult->next;
		lst = lst->next;
	}
	return (tmp);
}
