/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 14:35:51 by mmonahan          #+#    #+#             */
/*   Updated: 2019/12/07 17:30:19 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int main(int argc, char **argv)
{
	int			err;
	t_file		file;

	err = 0;
	ft_memset(&file, 0, sizeof(t_file));
	file.namefile = ft_strdup(argv[1]);

	if (argc == 2)
		err = validation(&file);
	else
		err = ERR_ONE_ATRIBUTE;
	put_exception(err);

	free(file.namefile);
	return 0;
}

/*int main(int argc, char **argv)
{
	int			err;
	t_file		file;

	err = 0;
	ft_memset(&file, 0, sizeof(t_file));
	if (argc == 2)
		err = validation(&file.header, argv[1]);
	else
		err = ERR_ONE_ATRIBUTE;
	put_exception(err);
	return 0;
}*/

/*
**	выводить 3 строки, 1-я до, 2-я где зафиксированная ошибка, 3-я после
**	Для нее можно сделать структурку))
*/