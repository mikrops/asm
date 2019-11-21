/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_instruction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 20:17:13 by mmonahan          #+#    #+#             */
/*   Updated: 2019/11/21 20:42:43 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
**	Возвращает валидную инструкцию в 16-й системе счисления
*/

char	*get_instruction(const char *string)
{
//	t_header	header;
//	int 		start;
//	int 		i;
//
//	ft_memset(&header, 0, sizeof(t_header));
//	i = 0;
//	while(ft_isspace(string[i]))
//		i++;
//	start = i;
	//int chk = ft_strstr(string, NAME_CMD_STRING);
	printf("\n->%c<-\n", ft_strstr(string, NAME_CMD_STRING)[0] == '.' ? '1' :
		'0');
//	while(string[i])
//	{
//
//		i++;
//	}
	return (NULL);
}