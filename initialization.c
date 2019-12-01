/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 20:44:56 by mmonahan          #+#    #+#             */
/*   Updated: 2019/12/01 17:54:09 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	initialization_header(t_header *header)
{
	ft_memset(header, 0, sizeof(t_header));
	header->magic = COREWAR_EXEC_MAGIC;
	header->magic = header->magic << 8;
	header->prog_size = 0;
}

void	initialization_file(t_file *file)
{
	ft_memset(file, 0, sizeof(t_file));
	ft_memset(&file->file, 0, sizeof(char *));
//	char 		*file;
//	char 		*string;
	ft_memset(&file->string, 0, sizeof(char *));
//	char 		*namefile;
	ft_memset(&file->namefile, 0, sizeof(char *));
	initialization_header(file->header);
}

//void	initialization(t_header *header)
void	initialization(t_file *file)
{
//	initialization_header(header);
	initialization_file(file);
}