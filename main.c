/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 14:35:51 by mmonahan          #+#    #+#             */
/*   Updated: 2019/12/27 06:51:49 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int main(int argc, char **argv)
{
	int		err;
	t_file	file;
	int		i;

	err = 0;
	i = 1;
	ft_memset(&file, 0, sizeof(t_file));


	while (i < argc)
	{
		file.namefile = ft_strdup(argv[i]);
		err = validation(&file);
		err = creat_fill_file(&file);

		put_exception(err);

		free(file.namefile);
		i++;
	}
	return 0;
}

/*
**	выводить 3 строки, 1-я до, 2-я где зафиксированная ошибка, 3-я после
**	Для нее можно сделать структурку))
*/