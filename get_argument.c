/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_argument.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 20:39:08 by mmonahan          #+#    #+#             */
/*   Updated: 2019/12/25 20:49:19 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
**	возвращает тип и значение аргумента,
*/

int get_argument(t_file *file)
{
	if (file)
		;
	int i;
	i = 0;
//	while (i < file->token.count_args)
//	{
//		if (get_reg(file->token.args[i]) == T_REG)
//			file->token.op[i] = T_REG;
//		else if (get_dir(file->token.args[i]) == T_DIR)
//			file->token.op[i] = T_DIR;
//		else if (get_ind(file->token.args[i]) == T_IND)
//			file->token.op[i] = T_IND;
//		else
//			return (ERR_BAD_TOKEN_ARGUMENT + 10);
//		i++;
//	}

	return (ERR_NORM);
}
