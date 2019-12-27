/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comands.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjohns <yjohns@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 02:56:18 by yjohns            #+#    #+#             */
/*   Updated: 2019/12/27 00:00:40 by yjohns           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
 * Каждая функция описывается своим кодом и аргументами.
 * Код принимается в качестве одного байта типа чар
 * Для каждой функции существует своя подфункция, которая принимает
 * аргументы и находит полное битовое представление команды
 * и её размер в байтах.
 *
 * Так как при передаче аргументов в общую функцию неизвестно,
 * сколько должно быть аргументов и какая у них разрядность,
 * мы передаем в массиве int значения всех трех. Считается,
 * что все метки уже были заменены на числовые значения
 *
 * Главная функция find_cmd на данный момент является войд,
 * но при необходимости может возвращать код возникающей ошибки,
 * что можно использовать при валидации
 *
 */

unsigned char	get_argcode_sum(char op_0, char op_1, char op_2)
{
	unsigned char	sum_code;

	sum_code = 0;
	sum_code |= (unsigned char)(op_0 << 6);
	sum_code |= (unsigned char)(op_1 << 4);
	sum_code |= (unsigned char)(op_2 << 2);
	return (sum_code);
}

void        cmd_arg_to_byte(t_file *file, int num, int dir_s)
{
	int 	i;
	unsigned int	arg_s;

	i = 0;
	arg_s = 0;
	while (i < num)
	{
		switch (FT->op[i][0])
		{
			case 1:
				arg_s = 8;
				break ;
			case 2:
				arg_s = dir_s * 8;
				 break ;
			case 3:
				arg_s = 16;
		}
		while (arg_s != 0)
		{
			file->exec_str[file->exec_size++] |= FT->op[i][1] >> (arg_s - 8);
			arg_s -= 8;
		}
		i++;
	}
}

/*
 * Шаблон функций, обрабатывающих аргументы команды:
 * токен, количество аргументов, размер типа T_DIR
 *
 * Все функции записывают найденную последовательность байт непосредственно в строку.
 * Индекс массива для записи определяется текущим значением exec_size
 *
 * Если у нас не существует FT->op[1], значит в команде только один аргумент и
 * нам не нужно находить сумму кодов типа аргумента
 */

void		cmd_to_byte_code(t_file *file)
{
	unsigned char	sum_code;
	int 			start_size;

	start_size = (int)file->exec_size;
	file->token = file->start_token;
	while(FT)
	{
		/*
		 * ЗДЕСЬ НЕОБХОДИМО ПРОВЕРИТЬ НА СУЩЕСТВОВАНИЕ МЕТКИ
		 */
		file->exec_str[file->exec_size++] |= FT->code;
		if (FT->op[1])
		{
			sum_code = get_argcode_sum(FT->op[0][0], FT->op[1][0], FT->op[2][0]);
			file->exec_str[file->exec_size++] |= sum_code;
		}
		cmd_arg_to_byte(file, op_tab[FT->code - 1].arguments,
						(op_tab[FT->code - 1].code5 == 1 ? 2 : 4));
		FT = FT->next;
	}
}
