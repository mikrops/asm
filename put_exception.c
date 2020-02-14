/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_exception.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 17:04:26 by mmonahan          #+#    #+#             */
/*   Updated: 2020/02/15 00:33:57 by mmonahan         ###   ########.fr       */
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

	//	--errors common--
	//	Наличия символа вне LABEL_CHARS и его местоположение - доработать
	arr_exc[ERR_LEXICAL] = "Lexical error at [X:Y]";
	//	Пусто полсе инструкции - доработать
	arr_exc[ERR_ENDLINE] = "Syntax error at token [TOKEN][00X:00Y] ENDLINE";
	arr_exc[ERR_NEWLINE] = "Syntax error - unexpected end of input (Perhaps "
		"you forgot to end with a newline ?)";

	//	--errors header--
	arr_exc[ERR_LONG_NAME] = "Champion name too long (Max length 128)";
	arr_exc[ERR_LONG_COMM] = "Champion comment too long (Max length 2048)";

/*
	//	--errors header--

  	//	нет первой ковычки
	arr_exc[ERR_SYNTAX_INS] = "Syntax error at token [TOKEN][00X:00Y] INSTRUCTION "Z"";

 	//	нет закрывающей кавычки вконце хедера
 	arr_exc[ERR_SYNTAX_END] = "Syntax error at token [TOKEN][00X:00Y] END";



*/
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
