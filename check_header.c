/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 21:05:54 by mmonahan          #+#    #+#             */
/*   Updated: 2020/02/15 10:26:12 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
**	В случае многострочных элементов хедэра бежит до первой двойной кавычки
*/

int	new_string(t_file *file, char *string, int size)
{
	int i;
	int read;

	read = get_next_line(file->fd_open, &FS);
	while (read == 1)
	{
		i = 0;
		file->row++;
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

int	check_end_string(const char *string)
{
	int i;

	i = 0;
	while (ft_isspace(string[i]))
		i++;
	if (string[i] == COMMENT_CHAR || string[i] == ALT_COMMENT_CHAR ||
		string[i] == '\0')
		return (ERR_NORM);
	else
		return (ERR_SYNTAX);
}

/*
**	Получает коммент или имя бота
*/

int	get_all(t_file *file, char *string, int size, int i)
{
	if (i)
		;
	while (ft_isspace(FS[FC]))
		FC++;
	if (FS[FC++] == '"')
	{
		while (FS[FC] || FS[FC] == '\0')
		{
			if (file->iter > size)
				return (COMMENT_LENGTH == size ? ERR_LONG_COMM : ERR_LONG_NAME);
			if (FS[FC] == '\0')
			{
				string[file->iter++] = '\n';
				if (new_string(file, string, size) != 1)
					return (ERR_SYNTAX);
				FC = 0;
			}
			if (FS[FC] == '"')
			{
				file->iter = 0;
				return (check_end_string(&FS[++FC]));
			}
			string[file->iter++] = FS[FC++];
		}
	}
	return (ERR_ENDLINE);
}

/*
**	Получает имя и коментарий бота
*/

int	check_header(t_file *file)
{
	int i;

	i = 0;
	FC = 0;
	while (ft_isspace(FS[FC]))
		FC++;
	if (!FS[FC] || FS[FC] == COMMENT_CHAR || FS[FC] == ALT_COMMENT_CHAR)
		return (ERR_NORM);
	if (file->flag_name == 0 &&
		ft_strnequ(&FS[FC], NAME_CMD_STRING, 5))
	{
		FC += 5;
		file->flag_name = CHK_NAME;
		return (get_all(file, file->header.prog_name, PROG_NAME_LENGTH, FC));
	}
	else if (file->flag_comment == 0 &&
		ft_strnequ(&FS[FC], COMMENT_CMD_STRING, 8))
	{
		FC += 8;
		file->flag_comment = CHK_COMMENT;
		return (get_all(file, file->header.comment, COMMENT_LENGTH, FC));
	}
	else
		return (ERR_SYNTAX);
}
