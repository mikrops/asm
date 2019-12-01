/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_instruction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 20:17:13 by mmonahan          #+#    #+#             */
/*   Updated: 2019/12/01 16:13:24 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*int	check_name(t_header *header, const char *string, const char *instr)
{
	int	i;
	int k;

	i = 0;
	k = 0;
	while (ft_isspace(string[i]))
		i++;
	while (*instr)
		if (string[i++] != *instr++)
			return (ERR_BEAD_HEADER + 10);
	if (ft_isspace(string[i]))
		while (ft_isspace(string[i]))
			i++;
	if (string[i++] == '"')
		while (string[i] != '"')
		{
			header->prog_name[k++] = string[i++];
			if (k == PROG_NAME_LENGTH)
				return (ERR_BEAD_HEADER + 20);
			if (string[i] == '\0')
				return (ERR_BEAD_HEADER + 30);
		}
	else
		return (ERR_BEAD_HEADER + 40);
//	while (ft_isspace(string[i]))
//		i++;
	printf("-- %d   ", i);
	if (string[i+1] != '\0')
		return (ERR_BEAD_HEADER + 50);
	return (ERR_NORM);
}*/

int	check_name(t_header *header, const char *string, const char *instr)
{
	int	i;
	int k;
	int fclose;


	i = 0;
	k = 0;
	fclose = 0;
	while (ft_isspace(string[i]))
		i++;
	while (*instr)
		if (string[i++] != *instr++)
			return (ERR_BEAD_HEADER + 10);
	while (ft_isspace(string[i]))
		i++;
	if (string[i++] != '"')
		return (ERR_BEAD_HEADER + 20);

	while (string[i])
	{
		if (!fclose && string[i] == '"')
		{
			fclose = 1;
			i++;
			continue ;
		}

		if (fclose == 1 &&
			(string[i] == COMMENT_CHAR || string[i] == ALT_COMMENT_CHAR))
			return (ERR_NORM);

		if (fclose == 1 && !ft_isspace(string[i]))
			return (ERR_BEAD_HEADER + 30);

		if (k == PROG_NAME_LENGTH)
			return (ERR_BEAD_HEADER + 40);

		if (fclose == 0 && string[i] == '\0')
			return (ERR_BEAD_HEADER + 50);

		if (fclose == 0)
			header->prog_name[k++] = string[i];
		i++;
	}

	if (string[i+1] != '\0')
		return (ERR_BEAD_HEADER + 60);
	return (ERR_NORM);
}

/*
**	Возвращает валидную инструкцию в 16-й системе счисления
*/

char	*get_instruction(t_header *header, const char *string)
{
	int	flag_name;
	int flag_comment;
//	int 		start;
//	int 		i;

	flag_name = 0;
	flag_comment = 0;
//	i = 0;
//	while(ft_isspace(string[i]))
//		i++;
//	start = i;
	//int chk = ft_strstr(string, NAME_CMD_STRING);

	printf("NULL == %d\n", header->prog_name[0] == '\0' ? 1 : 0);
	if (ft_strstr(string, NAME_CMD_STRING))
		;
	else
		;

	int ch;
	//int ch1;


	ch = check_name(header, string, NAME_CMD_STRING);
	//ch1 = check_name(header, string, COMMENT_CMD_STRING);
	//if (!ch)
	{
		printf("check = >%d< Name = >%s<\t>%s<\n", ch, header->prog_name,
			   string);
	}

	return (NULL);
}