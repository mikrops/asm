/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_fill_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 20:38:48 by mmonahan          #+#    #+#             */
/*   Updated: 2020/01/28 19:41:31 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int write_header(t_file *file)
{
//	записал magic в файл)))

	unsigned int i = COREWAR_EXEC_MAGIC;
	file->header.magic = (i >> 24) |
						 (i << 8 >> 24 << 8) |
						 (i >> 8 << 24 >> 8) |
						 (i << 24);
	write(file->fd_creat, &file->header.magic, 4);

//	записал name в файл)))
	write(file->fd_creat, &file->header.prog_name, PROG_NAME_LENGTH);
//	записал 4 нуля в файл)))
	i = 0;
	write(file->fd_creat, &i, 4);
//	записал размер кода в файл)))
	file->header.prog_size = 16;
	file->header.prog_size = file->header.prog_size << 24;
	write(file->fd_creat, &file->header.prog_size, 4);
//	записал comment в файл)))
	write(file->fd_creat, &file->header.comment, COMMENT_LENGTH);
//	записал 4 нуля в файл)))
	i = 0;
	write(file->fd_creat, &i, 4);
	return (ERR_NORM);
}

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

int			creat_fill_file(t_file *file)
{
	char *new_name;

	new_name = creat_name_file(file->namefile);
	file->fd_creat = creat(new_name, 00777);
	//free(new_name);
	if (file->fd_creat < 1)
		return (ERR_NO_CREAT_FILE);

	write_header(file);

//ЗАПИСАТЬ ОСТАЛЬНОЙ КОД ИЗ КАКОГО НИБУДЬ СПИСКА!!!!
// ...
	//*** yjohns ***
	//write(fd, file->exec_str, file->exec_size);
	write(file->fd_creat, file->exec_str, file->exec_size);
	close(file->fd_creat);
	return (ERR_NORM);
}
