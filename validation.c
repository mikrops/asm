/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 11:37:56 by mmonahan          #+#    #+#             */
/*   Updated: 2019/12/09 20:19:30 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
**	Возврящает имя нового файла
*/

static char	*creat_name_file(const char *old_name)
{
	int		length;
	char	*new_name;

	length = ft_strlen(old_name);
	new_name = ft_memalloc(length + 3);
	ft_strcpy(new_name, old_name);
	new_name[length - 1] = 'c';
	new_name[length] = 'o';
	new_name[length + 1] = 'r';
	return (new_name);
}

/*
**	Возврящает 0 если файл создался и заполнился, иначе номер ошибки
*/

static int	creat_fill_file(const char *namefile, const char *file)
{
	char *new_name;
	int fd;

	new_name = creat_name_file(namefile);
	fd = creat(new_name, S_IRWXO);
	//free(new_name);
	if (fd < 1)
		return (ERR_NO_CREAT_FILE);
	// записываем команды в 16-и ричной системе счисления в файл
	// *** супер функция записи строки в этот файл
	// fill_new_file(fd, file);
	if (file)
	{
		;
	}
// записал magic в файл)))
	unsigned int i = COREWAR_EXEC_MAGIC;
	i = i << 8;
	write(fd, (char *)&i, 4);
//	write(fd, "\nhello\n", 7);
//	int len = printf("\n%s\n", file);
//	write(fd, file, len - 2);

	close(fd);
	return (ERR_NORM);
}

/*
**	Возвращает 0, если имя файла нормальное, в противном случае 1
*/

static int	check_name_file(const char *name_file)
{
	int	length;

	length = ft_strlen(name_file);
	if (name_file[length - 1] != 's')
		return (1);
	if (name_file[length - 2] != '.')
		return (1);
	if (!ft_isdigit(name_file[length - 3]) &&
		!ft_isalpha(name_file[length - 3]))
		return (1);
	return (0);
}

/*
**	Валидация файла
*/
int	validation(t_file *file)
{
	int error_header;

	error_header = 0;
	if (check_name_file(file->namefile))
		return (ERR_BAD_NAME_FILE);
	file->fd_open = open(file->namefile, O_RDONLY);
	if (file->fd_open < 1)
		return (ERR_NO_OPEN_FILE);
	// УБРАТЬ!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//file->flag_comment = 1;
	//
	// сохраненяем файл в массив построчно и проверяем его
	while (get_next_line(file->fd_open, &file->string))
	{
		// check_string(string);

//		if (!file->flag_name || !file->flag_comment)
		error_header = get_instruction(file);
		if (error_header)
			return (ERR_BAD_HEADER);

		file->file = ft_str_rejoin(file->file, file->string);
		ft_strdel(&file->string);
		file->file = ft_str_rejoin(file->file, "\n");
	}
	ft_strdel(&file->string);
	close(file->fd_open);

	//создание и заполнение файла только после проюождения валидации
	//можно вообще в отдельный файл жахнуть
	creat_fill_file(file->namefile, file->file);

	printf("\n\nfile = >%s<\nnamefile = >%s<\nflag_name = >%d<\nflag_comment = "
		">%d<\nprog_name = >%s<\ncomment = >%s<\n",
			file->file,
			file->namefile,
			file->flag_name,
			file->flag_comment,
			file->header.prog_name,
			file->header.comment);
	return (ERR_NORM);
}

/*

int	validation(t_header *header, char *namefile)
{
	int		fd_open;
	char 	*string;
	char 	*file;

	string = NULL;
	file = ft_memalloc(1);
	if (check_name_file(namefile))
		return (ERR_BAD_NAME_FILE);
	fd_open = open(namefile, O_RDONLY);
	if (fd_open < 1)
		return (ERR_NO_OPEN_FILE);
	// сохраненяем файл в массив построчно и проверяем его
	while (get_next_line(fd_open, &string))
	{
		// check_string(string);
//		get_instruction(header, string);
		get_instruction(header, string);
		file = ft_str_rejoin(file, string);
		ft_strdel(&string);
		file = ft_str_rejoin(file, "\n");
	}
	ft_strdel(&string);
	close(fd_open);

	//создание и заполнение файла только после проюождения валидации
	//можно вообще в отдельный файл жахнуть
	creat_fill_file(namefile, file);

	return (ERR_NORM);
}
*/
