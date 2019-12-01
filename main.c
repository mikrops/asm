/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 14:35:51 by mmonahan          #+#    #+#             */
/*   Updated: 2019/11/29 20:33:03 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int main(int argc, char **argv)
{
	int			err;
	t_file		file;
	//t_header	header;

	err = 0;
//	initialization(&header);
	initialization(&file);
	if (argc == 2)
		err = validation(file.header, argv[1]);
	else
		err = ERR_ONE_ATRIBUTE;
	put_exception(err);
	return 0;
}

/*
**	выводить 3 строки, 1-я до, 2-я где зафиксированная ошибка, 3-я после
**	Для нее можно сделать структурку))
*/