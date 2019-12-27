/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 14:35:51 by mmonahan          #+#    #+#             */
/*   Updated: 2019/12/27 12:33:16 by mmonahan         ###   ########.fr       */
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
	if (argc == 1)
	{
		put_exception(&file, ERR_NO_ATRIBUTE);
		return (0);
	}

	while (i < argc)
	{
		file.namefile = ft_strdup(argv[i]);
		err = validation(&file);
		if (err)
		{
			put_exception(&file, err);
			free(file.namefile);
			i++;
			continue ;
		}
		cmd_to_byte_code(&file);
		err = creat_fill_file(&file);
		if (err)
		{
			put_exception(&file, err);
			i++;
			free(file.namefile);
			continue ;
		}

		put_exception(&file, err);
		free(file.namefile);
		i++;
	}
	return 0;
}
