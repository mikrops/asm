/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 11:37:56 by mmonahan          #+#    #+#             */
/*   Updated: 2019/11/06 20:20:22 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static char	*creat_name_file(const char *old_name)
{
	int 	length;
	char	*new_name;

	length = ft_strlen(old_name);
	new_name = ft_memalloc(length + 2);
	ft_strcpy(new_name, old_name);
	new_name[length - 1] = 'c';
	new_name[length] = 'o';
	new_name[length + 1] = 'r';
	return (new_name);
}

/*
**	Возвращает 0, если имя файла нормальное, в противном случае 1
*/
int		check_name_file(const char *name_file)
{
	int 	length;

	length = ft_strlen(name_file);
	if (name_file[length - 1] != 's')
		return (1);
	if (name_file[length - 2] != '.')
		return (1);
	if (!ft_isdigit(name_file[length - 3]) && ft_isalpha(name_file[length]))
		return (1);
	return (0);
}

int validation(char *namefile)
{
	int		fd_open;
	int		fd_creat;
	char	*name;

	if (check_name_file(namefile))
		return (ERR_BAD_NAME_FILE);
	fd_open = open(namefile, O_RDONLY);
	if (fd_open < 1)
	{
		close(fd_open);
		return (ERR_NO_OPEN_FILE);
	}

	name = creat_name_file(namefile);
	fd_creat = creat(name, 755);
	if (fd_creat < 1)
	{
		close(fd_creat);
		return (ERR_NO_CREAT_FILE);
	}

	return (ERR_NORM);
}
