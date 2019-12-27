/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_exception.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 17:04:26 by mmonahan          #+#    #+#             */
/*   Updated: 2019/12/27 09:20:53 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	init_exc(char **arr_exc)
{
	arr_exc[ERR_NORM] = "Writing output program to";
	arr_exc[ERR_NO_ATRIBUTE] = "need only one atribute, name file .s";
	arr_exc[ERR_BAD_NAME_FILE] = "invalid file name";
	arr_exc[ERR_NO_OPEN_FILE] = "unable to open file";
	arr_exc[ERR_NO_CREAT_FILE] = "unable to creat file";
	arr_exc[ERR_BAD_HEADER] = "bad header";
	arr_exc[ERR_BAD_TOKEN_INSTRUCTION] = "bad instruction";
	arr_exc[ERR_BAD_TOKEN_ARGUMENT] = "bad argument";
	arr_exc[ERR_INVALID_CODE] = "bad code";
}

void	put_exception(t_file *file, int error)
{
	char	*exception[100];
	if (file)
		;

	init_exc(exception);
	if (error)
	{
		printf("ERROR: %s\n", exception[error]);
	}
	else
	{
		printf("%s %s\n", exception[error], file->namefile);
	}
	//exit(0);
}
