/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 21:05:54 by mmonahan          #+#    #+#             */
/*   Updated: 2019/12/27 05:41:26 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
**	В случае многострочного параметра бежит до первой двойной кавычки
*/

void	new_string(t_file *file, int size)
{
	int i;

	while (get_next_line(file->fd_open, &FS))
	{
		i = 0;
		if (FS[i] == '\0')
			file->header.prog_name[file->iter++] = '\n';
		if (ft_strchr(FS, '"'))
			break ;
		while (FS[i])
		{
			if (file->iter > size)
				break ;
			file->header.prog_name[file->iter++] = FS[i++];
			if (FS[i] == '\0')
				file->header.prog_name[file->iter++] = '\n';
		}
		ft_strdel(&FS);
	}
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
**	Получает имя бота
*/

int		get_prog_name(t_file *file, int i)
{
	file->flag_name = CHK_NAME_START;
	while (ft_isspace(FS[i]))
		i++;
	if (FS[i++] == '"')
		while (FS[i])
		{
			if (FS[i] == '"')
			{
				file->flag_name = CHK_NAME_END;
				file->iter = 0;
				return (check_end_string(&FS[++i]));
			}
			if (file->iter > PROG_NAME_LENGTH)
				return (ERR_BAD_HEADER + 150);
			file->header.prog_name[file->iter++] = FS[i++];
			if (FS[i] == '\0')
			{
				file->header.prog_name[file->iter++] = '\n';
				new_string(file, PROG_NAME_LENGTH);
				i = 0;
			}
		}
	else
		return (ERR_BAD_HEADER + 100);
	return (ERR_NORM);
}

/*
**	Получает комментарий бота
*/

int		get_prog_comment(t_file *file, int i)
{
	file->flag_comment = CHK_COMMENT_START;
	while (ft_isspace(FS[i]))
		i++;
	if (FS[i++] == '"')
		while (FS[i])
		{
			if (FS[i] == '"')
			{
				file->flag_comment = CHK_COMMENT_END;
				file->iter = 0;
				return (check_end_string(&FS[++i]));
			}
			if (file->iter > COMMENT_LENGTH)
				return (ERR_BAD_HEADER + 250);
			file->header.comment[file->iter++] = FS[i++];
			if (FS[i] == '\0')
			{
				file->header.comment[file->iter++] = '\n';
				new_string(file, COMMENT_LENGTH);
				i = 0;
			}
		}
	else
		return (ERR_BAD_HEADER + 200);
	return (ERR_NORM);
}

int		check_header(t_file *file)
{
	int i;

	i = 0;
	while (ft_isspace(FS[i]))
		i++;
	if (file->flag_name == 0 &&
		ft_strnequ(&FS[i], NAME_CMD_STRING, 5))
	{
		i += 5;
		return (get_prog_name(file, i));
	}
	else if (file->flag_comment == 0 &&
		ft_strnequ(&FS[i], COMMENT_CMD_STRING, 8))
	{
		i += 8;
		return (get_prog_comment(file, i));
	}
	else
		return (ERR_BAD_HEADER + 300);
}
