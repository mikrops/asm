/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 20:44:56 by mmonahan          #+#    #+#             */
/*   Updated: 2019/11/28 21:01:53 by mmonahan         ###   ########.fr       */
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

void	initialization(t_header *header)
{
	initialization_header(header);
}