/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_instruction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 20:17:13 by mmonahan          #+#    #+#             */
/*   Updated: 2019/12/07 20:46:51 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
int	check_name(t_file *file, const char *instr)
{
	int	i;
	int k;
	int fclose;

	i = 0;
	k = 0;
	fclose = 0;
	while (ft_isspace(file->string[i]))
		i++;
	while (*instr)
		if (file->string[i++] != *instr++)
			return (ERR_BEAD_HEADER + 10);
	while (ft_isspace(file->string[i]))
		i++;
	if (file->string[i++] != '"')
		return (ERR_BEAD_HEADER + 20);

	while (file->string[i])
	{
		if (!fclose && file->string[i] == '"')
		{
			fclose = 1;
			i++;
			continue ;
		}

		if (fclose == 1 &&
			(file->string[i] == COMMENT_CHAR || file->string[i] == ALT_COMMENT_CHAR))
			return (ERR_NORM);

		if (fclose == 1 && !ft_isspace(file->string[i]))
			return (ERR_BEAD_HEADER + 30);

		if (k == PROG_NAME_LENGTH)
			return (ERR_BEAD_HEADER + 40);

		if (fclose == 0 && file->string[i] == '\0')
			return (ERR_BEAD_HEADER + 50);

		if (fclose == 0)
			file->header.prog_name[k++] = file->string[i];
		i++;
	}

	if (file->string[i+1] != '\0')
		return (ERR_BEAD_HEADER + 60);
	return (ERR_NORM);
}
*/

// fclose  = 0, 1, 2. 1 - multistring,

/*int	check_name(t_file *file, const char *instr)
{
	int	i;
	int k;
	int status;
	//0 до начала команды
	//1 до начала параметра
	//2 в параметре
	//3 после параметра
	//4 закончили параметр
	i = 0;
	k = file->iter;
	status = file->status;

	while (file->string[i])
	{
		if ((status == 0 || status == 1 || status == 3)
			&& ft_isspace(file->string[i]))
			i++;
		else if (status  == 0 && file->string[i] == '.')
		{
			//добваить проверку на имя или комент и изменять их флаги
			// 0 = void, 1 = start, 2 = finish
			while (*instr)
				if (file->string[i++] != *instr++)
					return (ERR_BEAD_HEADER + 10);
			status = 1;
		}
		else if ((status == 1 || status == 2 ) && file->string[i] == '"')
		{
			status = (status == 1) ? 2 : 3;
			i++;
		}
		else if (status == 2 && ft_isascii(file->string[i]))
		{
			if (k > PROG_NAME_LENGTH)
				return (ERR_BEAD_HEADER + 20);
			file->header.prog_name[k++] = file->string[i++];
			if (file->string[i] == '\0')
				file->header.prog_name[k++] = '\n';
		}
		else if (status == 3 && file->string[i] == COMMENT_CHAR)
		{
			status = 4;
			break ;
		}
		else
			return (ERR_BEAD_HEADER + 1000);
	}

	if (status == 4)
	{
		file->iter = 0;
		file->status = 0;
	}
	else
	{
		file->iter = k;
		file->status = status;
	}

	return (ERR_NORM);
}*/

int	check_name(t_file *file, const char *instr)
{
	int	i;
	int k;
	int status;
	//0 до начала команды
	//1 до начала параметра
	//2 в параметре
	//3 после параметра
	//4 закончили параметр
	i = 0;
	k = file->iter;
	status = file->status;

	while (file->string[i])
	{
		if ((status == 0 || status == 1 || status == 3) &&
			ft_isspace(file->string[i]))
			i++;
		else if (status  == 0 && file->string[i] == '.')
		{
			//добваить проверку на имя или комент и изменять их флаги
			// 0 = void, -1 = start, 1 = finish
			if (!file->flag_name && ft_strstr(file->string, NAME_CMD_STRING))
				file->flag_name = -1;
			if (!file->flag_comment && ft_strstr(file->string,
					COMMENT_CMD_STRING))
				file->flag_comment = -1;
			while (*instr)
				if (file->string[i++] != *instr++)
					return (ERR_BEAD_HEADER + 10);
			status = 1;
		}
		else if ((status == 1 || status == 2 ) && file->string[i] == '"')
		{
			status = (status == 1) ? 2 : 3;
			i++;
		}
		else if (status == 2 && ft_isascii(file->string[i]))
		{
			if (k > PROG_NAME_LENGTH)
				return (ERR_BEAD_HEADER + 20);
			file->header.prog_name[k++] = file->string[i++];
			if (file->string[i] == '\0')
				file->header.prog_name[k++] = '\n';
		}
		else if (status == 3 && (file->string[i] == COMMENT_CHAR ||
			file->string[i] == ALT_COMMENT_CHAR))
		{
			status = 4;
			break ;
		}
		else
			return (ERR_BEAD_HEADER + 1000);
	}

	if (status == 4)
	{
		file->iter = 0;
		file->status = 0;
		file->flag_name = 1;
	}
	else
	{
		file->iter = k;
		file->status = status;
	}

	return (ERR_NORM);
	// УБАРТЬ в ВАЛИДАЦИИ ФЛАГ КОМЕНТА 1 !!!!!!!!!!!!!!!!!!!!
}

/*
**	Возвращает валидную инструкцию в 16-й системе счисления
*/


char	*get_instruction(t_file *file)
{
//	int 		start;
//	int 		i;

//	i = 0;
//	while(ft_isspace(string[i]))
//		i++;
//	start = i;
	//int chk = ft_strstr(string, NAME_CMD_STRING);

	printf("NULL == %d\n", file->header.prog_name[0] == '\0' ? 1 : 0);
	if (ft_strstr(file->string, NAME_CMD_STRING))
		;
	else
		;

	int ch;
	//int ch1;

	ch = check_name(file, NAME_CMD_STRING);
	//ch1 = check_name(header, string, COMMENT_CMD_STRING);
	//if (!ch)
	{
		printf("check = >%d< Name = >%s<\t>%s<\n", ch, file->header.prog_name,
			   file->string);
	}
	if (ch)
	{
		file->iter = 0;
		file->flag_name = 0;
	}

	return (NULL);
}

/*
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
}*/
