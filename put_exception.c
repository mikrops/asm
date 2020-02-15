/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_exception.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 17:04:26 by mmonahan          #+#    #+#             */
/*   Updated: 2020/02/15 11:41:55 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	init_exc(char **arr_exc)
{
	arr_exc[ERR_NORM] = "Writing output program to %s\n";

	arr_exc[ERR_BAD_NAME_FILE] = "invalid file name";
	arr_exc[ERR_NO_CREAT_FILE] = "unable to creat file";
	arr_exc[ERR_INVALID_CODE] = "bad code";

	//	--errors file--
	arr_exc[ERR_NO_OPEN_FILE] = "Can't read source file %s\n";
	// sourcefile.s полный путь до файла, если его нет
	arr_exc[ERR_NO_ATRIBUTE] = "Usage: %s [-a] <sourcefile.s>\n\t-a : Instead of creating a .cor file, outputs a stripped and annotated version of the code to the standard output";
	//
	//	--errors common--
	//	Наличия символа вне LABEL_CHARS и его местоположение - доработать
	arr_exc[ERR_LEXICAL] = "Lexical error at [%d:%d]\n";
	//	Пусто полсе инструкции - доработать
	arr_exc[ERR_ENDLINE] = "Syntax error at token [TOKEN][%.3d:%.3d] ENDLINE\n";
	arr_exc[ERR_NEWLINE] = "Syntax error - unexpected end of input (Perhaps "
		"you forgot to end with a newline ?)\n";

 	//	неверный токен
 	arr_exc[ERR_SYNTAX] = "Syntax error at token [%.3d:%.3d] %s\n";


	//	--errors header--
	arr_exc[ERR_LONG_NAME] = "Champion name too long (Max length 128)\n";
	arr_exc[ERR_LONG_COMM] = "Champion comment too long (Max length 2048)\n";
}

void	put_exception(t_file *file, int error)
{
	char	*exception[200];

	init_exc(exception);
	if (error == ERR_NO_OPEN_FILE)
		printf(exception[error], file->namefile);
	if (error == ERR_SYNTAX)
		printf(exception[error], file->namefile);
	else if (error)
		printf(exception[error], file->row, file->column);
	else
		printf(exception[error], file->namefile);
}
