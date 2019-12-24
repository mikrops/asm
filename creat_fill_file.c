/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_fill_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 20:38:48 by mmonahan          #+#    #+#             */
/*   Updated: 2019/12/24 20:38:48 by mmonahan         ###   ########.fr       */
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

int			creat_fill_file(t_file *file)
{
	char *new_name;
	int fd;

	new_name = creat_name_file(file->namefile);
	fd = creat(new_name, 00777);
	//free(new_name);
	if (fd < 1)
		return (ERR_NO_CREAT_FILE);
	// записываем команды в 16-и ричной системе счисления в файл
	// *** супер функция записи строки в этот файл
	// fill_new_file(fd, file);

// записал magic в файл)))
	unsigned int i = COREWAR_EXEC_MAGIC;
	file->header.magic = i << 8;
	write(fd, &file->header.magic, 4);
// записал name в файл)))
	write(fd, &file->header.prog_name, PROG_NAME_LENGTH);
// записал 4 нуля в файл)))
	i = 0;
	write(fd, &i, 4);
// записал размер кода в файл)))
	file->header.prog_size = 16;
	file->header.prog_size = file->header.prog_size << 24;
	write(fd, &file->header.prog_size, 4);
// записал comment в файл)))
	write(fd, &file->header.comment, COMMENT_LENGTH);
// записал 4 нуля в файл)))
	i = 0;
	write(fd, &i, 4);
//ЗАПИСАТЬ ОСТАЛЬНОЙ КОД ИЗ КАКОГО НИБУДЬ СПИСКА!!!!
// ...

	close(fd);
	return (ERR_NORM);
}
