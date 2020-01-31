/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 21:05:54 by mmonahan          #+#    #+#             */
/*   Updated: 2020/01/31 19:46:19 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
**	В случае многострочных элементов хедэра бежит до первой двойной кавычки
*/

int new_string(t_file *file, char *string, int size)
{
	int i;
	int read;

	read = get_next_line(file->fd_open, &FS);
	while (read == 1)
	{
		i = 0;
		if (FS[i] == '\0')
			string[file->iter++] = '\n';
		if (ft_strchr(FS, '"'))
			break ;
		while (FS[i])
		{
			if (file->iter > size)
				break ;
			string[file->iter++] = FS[i++];
			if (FS[i] == '\0')
				string[file->iter++] = '\n';
		}
		ft_strdel(&FS);
		read = get_next_line(file->fd_open, &FS);
	}
	return (read);
}

/*
**	Валидность строки после второй ковычки
*/

int		check_end_string(const char *string)
{
	int i;

	i = 0;
	while (ft_isspace(string[i]))
		i++;
	if (string[i] == COMMENT_CHAR || string[i] == ALT_COMMENT_CHAR ||
		string[i] == '\0')
		return (ERR_NORM);
	else
		return (ERR_BAD_HEADER + 400);
}

/*
**	Получает комент или имя бота
*/

int get_all(t_file *file, char *string, int size, int i)
{
	while (ft_isspace(FS[i]))
		i++;
	if (FS[i++] == '"')
		while (FS[i])
		{
			if (FS[i] == '"')
			{
				file->iter = 0;
				return (check_end_string(&FS[++i]));
			}
			if (file->iter > size)
				return (ERR_BAD_HEADER + 150);
			string[file->iter++] = FS[i++];
			if (FS[i] == '\0')
			{
				string[file->iter++] = '\n';
				if (new_string(file, string, size)!= 1)
					return (ERR_BAD_HEADER + 180);
				i = 0;
			}
		}
	return (ERR_BAD_HEADER + 100);
}

/*
**	Получает имя и коментарий бота
*/

int		check_header(t_file *file)
{
	int i;

	i = 0;
	while (ft_isspace(FS[i]))
		i++;
	if (!FS[i])
	{ //УДАЛИТЬ
		printf("\t пропускаем строку\n"); //УДАЛИТЬ
		return (ERR_NORM);
	} //УДАЛИТЬ
	if (file->flag_name == 0 &&
		ft_strnequ(&FS[i], NAME_CMD_STRING, 5))
	{
		printf("\t обнаружили ИМЯ\n"); //УДАЛИТЬ
		i += 5;
		file->flag_name = CHK_START;
		return (get_all(file, file->header.prog_name, PROG_NAME_LENGTH, i));
	}
	else if (file->flag_comment == 0 &&
		ft_strnequ(&FS[i], COMMENT_CMD_STRING, 8))
	{
		printf("\t обнаружили КОММЕНТ\n"); //УДАЛИТЬ
		i += 8;
		file->flag_comment = CHK_START;
		return (get_all(file, file->header.comment, COMMENT_LENGTH, i));
	}
	else
		return (ERR_BAD_HEADER + 300);
}
