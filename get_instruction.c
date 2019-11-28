/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_instruction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 20:17:13 by mmonahan          #+#    #+#             */
/*   Updated: 2019/11/28 21:01:53 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	check_name(t_header *header, const char *string, const char *instr)
{
	int	i;
	int k;

	i = 0;
	k = 0;
	while (ft_isspace(string[i]))
		i++;
	while (*instr)
		if (string[i++] != *instr++)
			return (ERR_BEAD_HEADER + 1);
	if (ft_isspace(string[i]))
		while (ft_isspace(string[i]))
			i++;
	if (string[i++] == '"')
		while (string[i] != '"')
			header->prog_name[k++] = string[i++];
	else
		return (ERR_BEAD_HEADER + 2); // продолжить от сюда!!!! 2019.11.28
	return (ERR_NORM);
}

/*
**	Возвращает валидную инструкцию в 16-й системе счисления
*/

char	*get_instruction(t_header *header, const char *string)
{
//	int 		start;
//	int 		i;
//

//	i = 0;
//	while(ft_isspace(string[i]))
//		i++;
//	start = i;
	//int chk = ft_strstr(string, NAME_CMD_STRING);
//	if (ft_strstr(string, NAME_CMD_STRING))
//		printf("\n->%s<-\n", ft_strstr(string, NAME_CMD_STRING));
//	else
//		printf("\n->%s<-\n", ft_strstr(string, COMMENT_CMD_STRING));

	int ch;
	int ch1;

	ch = check_name(header, string, NAME_CMD_STRING);
	ch1 = check_name(header, string, COMMENT_CMD_STRING);

	printf("check = >%d< Name = >%s<\t>%s<\n", ch, header->comment, string);
//	while(string[i])
//	{
//
//		i++;
//	}
	return (NULL);
}