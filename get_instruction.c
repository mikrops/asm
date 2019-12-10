/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_instruction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 20:17:13 by mmonahan          #+#    #+#             */
/*   Updated: 2019/12/10 20:42:24 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

// fclose  = 0, 1, 2. 1 - multistring,

int	check_name(t_file *file)
{
	int	i;
	int k;
	int status;
	int flag;
	//0 до начала команды
	//1 до начала параметра
	//2 в параметре
	//3 после параметра
	//4 закончили параметр
	i = 0;
	k = file->iter;
	status = file->status;

	flag = 0;
	if (file->flag_name == -1)
		flag = 1;
	if (file->flag_comment == -1)
		flag = 2;

	while (file->string[i])
	{
		if ((status == 0 || status == 1 || status == 3) &&
			ft_isspace(file->string[i]))
		{
			i++;
			if (status == 3 && file->string[i] == '\0')
				file->header.comment[k++] = '\n';
		}
		else if (status  == 0 && file->string[i] == '.')
		{
			//добваить проверку на имя или комент и изменять их флаги
			// 0 = void, -1 = start, 1 = finish
			if (!file->flag_name &&
				ft_strnequ(file->string, NAME_CMD_STRING, 5))
			{
				file->flag_name = -1;
				printf(" >NAME< ");
				flag = 1;
				i += 5;
			}
			else if (!file->flag_comment &&
				ft_strnequ(file->string, COMMENT_CMD_STRING, 8))
			{
				file->flag_comment = -1;
				printf(" >COMMENT< ");
				flag = 2;
				i += 8;
			}
			else
				return (ERR_BAD_HEADER + 12);
			status = 1;
		}
		else if ((status == 1 || status == 2 ) && file->string[i] == '"')
		{
			status = (status == 1) ? 2 : 3;
			i++;
			if (status == 3 && file->string[i] == '\0')
				status = 4;
		}
		else if (status == 2)
		{
			if (flag == 1)
			{
				if (k > PROG_NAME_LENGTH)
					return (ERR_BAD_HEADER + 20);
				file->header.prog_name[k++] = file->string[i++];
				if (file->string[i] == '\0')
					file->header.prog_name[k++] = '\n';
			}
			else if (flag == 2)
			{
				if (k > COMMENT_LENGTH)
					return (ERR_BAD_HEADER + 21);
				file->header.comment[k++] = file->string[i++];
				if (file->string[i] == '\0')
					file->header.comment[k++] = '\n';
			}
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// !!!!!       ВОССТАНОВИТЬ ЗАПИСЬ В ФАЙЛ БЛИН      !!!!!
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		}
		else if (status == 3 && (file->string[i] == COMMENT_CHAR ||
			file->string[i] == ALT_COMMENT_CHAR))
		{
			status = 4;
			break ;
		}
		else
			return (ERR_BAD_HEADER + 1000);
	}

	if (status == 4)
	{
		file->iter = 0;
		file->status = 0;
		if (flag == 1)
			file->flag_name = 1;
		else if (flag == 2)
			file->flag_comment = 1;
	}
	else
	{
		file->iter = k;
		file->status = status;
	}

	return (ERR_NORM);
}

/*
**	Возвращает валидную инструкцию в 16-й системе счисления
*/

int	get_instruction(t_file *file)
{
	int check;

	check = 0;
	if (!file->flag_name || !file->flag_comment)
		check = check_name(file);
	return (check);
}
