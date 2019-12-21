/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_instruction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 20:17:13 by mmonahan          #+#    #+#             */
/*   Updated: 2019/12/21 15:43:01 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

// fclose  = 0, 1, 2. 1 - multistring,

/*
**	Возвращает 0 если имя или коментария бота валидны, иначе номер ошибки
*/
int	check_header(t_file *file)
{
	int	i;
	int k;
	int status;
	int flag;
	//0 до начала команды
	//1 до начала параметра
	//2 в параметре
	//3 после параметра
	//4 закончили параметр
	i = 0;
	k = file->iter;
	status = file->status;

	flag = 0;
	if (file->flag_name == -1)
		flag = 1;
	if (file->flag_comment == -1)
		flag = 2;

	while (file->string[i])
	{
		if ((status == 0 || status == 1 || status == 3) &&
			ft_isspace(file->string[i]))
		{
			i++;
			if (status == 3 && file->string[i] == '\0')
				file->header.comment[k++] = '\n';
		}
		else if (status  == 0 && file->string[i] == '.')
		{
			//добваить проверку на имя или комент и изменять их флаги
			// 0 = void, -1 = start, 1 = finish
			if (!file->flag_name &&
				ft_strnequ(file->string, NAME_CMD_STRING, 5))
			{
				file->flag_name = -1;
				printf(" >NAME< ");
				flag = 1;
				i += 5;
			}
			else if (!file->flag_comment &&
				ft_strnequ(file->string, COMMENT_CMD_STRING, 8))
			{
				file->flag_comment = -1;
				printf(" >COMMENT< ");
				flag = 2;
				i += 8;
			}
			else
				return (ERR_BAD_HEADER + 12);
			status = 1;
		}
		else if ((status == 1 || status == 2 ) && file->string[i] == '"')
		{
			status = (status == 1) ? 2 : 3;
			i++;
			if (status == 3 && file->string[i] == '\0')
				status = 4;
		}
		else if (status == 2)
		{
			if (flag == 1)
			{
				if (k > PROG_NAME_LENGTH)
					return (ERR_BAD_HEADER + 20);
				file->header.prog_name[k++] = file->string[i++];
				if (file->string[i] == '\0')
					file->header.prog_name[k++] = '\n';
			}
			else if (flag == 2)
			{
				if (k > COMMENT_LENGTH)
					return (ERR_BAD_HEADER + 21);
				file->header.comment[k++] = file->string[i++];
				if (file->string[i] == '\0')
					file->header.comment[k++] = '\n';
			}
		}
		else if (status == 3 && (file->string[i] == COMMENT_CHAR ||
			file->string[i] == ALT_COMMENT_CHAR))
		{
			status = 4;
			break ;
		}
		else
			return (ERR_BAD_HEADER + 1000);
	}

	if (status == 4)
	{
		file->iter = 0;
		file->status = 0;
		if (flag == 1)
			file->flag_name = 1;
		else if (flag == 2)
			file->flag_comment = 1;
	}
	else
	{
		file->iter = k;
		file->status = status;
	}

	return (ERR_NORM);
}

/*
**	Елси label валидный, то возвращает его длину, иначе -1
*/

int check_label(const char *string)
{
	int	i;

	i = 0;
	// временоо для теста	>>
	while (ft_isspace(*string))
		string++;
	// 						<<
	while (string[i])
	{
		if (ft_strchr(LABEL_CHARS, string[i]))
			i++;
		else if (string[i] == LABEL_CHAR)
			return (i);
		else
			return (0);
	}
	return (0);
}

/*
**	Если команда валидна, то возвращает ее код, иначе -1
**	string - строка, без пробелов и табов вначале
*/

int	check_inst(const char *string)
{
	int i;

	i = 0;
	while (ft_islower(string[i]))
		i++;
	return (i);
}

/*
**	Возвращает имя команды
*/

char	*get_name(const char *string, int len_instr)
{
	int		i;
	char	*instr;

	i = 0;
	instr = ft_memalloc(len_instr + 1);
	while (i < len_instr)
	{
		instr[i] = *string++;
		i++;
	}
	instr[i] = '\0';
	return (instr);
}

/*
**	Делить строку на токены
*/

int get_tokens(t_file *file)
{
	int		i;
	int 	len_lab;
	int 	len_inst;
//	t_label	label;

	i = 0;
	len_lab = 0;
	len_inst = 0;
//	ft_memset(&label, 0, sizeof(t_label));

	//ищу лабел до :
	//если 'нет'
	//ищу команду до isspace
	//понимаю, сколько должно быть аргументов
	//	если 1
	//		пропуская все isspace
	//		ищу первый аргумент
	//		пропуская все isspace до \n
	//	если 2
	//		пропуская все isspace
	//		ищу первый аргумент
	//		пропуская все isspace
	//		ищу ,
	//		дальше как в 1
	//	если 3
	//		пропуская все isspace
	//		ищу первый аргумент
	//		пропуская все isspace
	//		ищу ,
	//		дальше как в 2

	// пропускаем пробелы
	while (ft_isspace(file->string[i]))
		i++;

	// определяем label
	len_lab = check_label(&file->string[i]);
	if (len_lab > 0)
	{
		file->token.label = get_name(&file->string[i], len_lab);
		i += len_lab + 1;
	}
	//file->label.content = *ft_lstnew(void const *content, size_t
	// content_size);
//	label.name = file->token.label;
//	file->label.next = ft_lstnew(&label, sizeof(t_label));

	printf("проверка отстатка от нахождения LABEL = >%s<\n", &file->string[i]);

	// пропускаем пробелы
	while (ft_isspace(file->string[i]))
		i++;

	// определяем команду
	len_inst = check_inst(&file->string[i]);
	printf("Проверка начала команды, ее длина = >%d<\n", len_inst);
	if (len_inst > 0)
	{
		file->token.inst = get_name(&file->string[i], len_inst);
		i += len_inst + 1;
	}
	else
		return (ERR_BAD_TOKEN_INSTRUCTION + 10);

	// пропускаем пробелы
	while (ft_isspace(file->string[i]))
		i++;
	printf("проверка отстатка от нахождения INSTR = >%s<\n", &file->string[i]);

	// определяем валидность команды, если она определена
	int	k;

	k = 0;
	if (file->token.inst)
		while (k < 17)
		{
			if (ft_strequ(file->token.inst, op_tab[k].name))
			{
				file->token.code = op_tab[k].code;
				break ;
			}
			k++;
		}
	else
		return (ERR_BAD_TOKEN_INSTRUCTION + 20);

	// если команда валидная, то определяем количество аргументов
	k = 0;
	if (file->token.code > 0)
	{
		file->token.args = ft_strsplit(&file->string[i], SEPARATOR_CHAR);
		k = 0;
		printf("\n");
		while (file->token.args[k])
		{
			printf("[%d] >%s<\t", k, file->token.args[k]);
			k++;
		}
		file->token.count_args = k;
		printf("\n\n");
	}
	else
		return (ERR_BAD_TOKEN_INSTRUCTION + 30);

	// проверяем на валидное количество аргументов в инструкции
	if (op_tab[file->token.code - 1].arguments == file->token.count_args)
		printf("NORM ARGS [%d/%d]\n", op_tab[file->token.code - 1].arguments,
				file->token.count_args);
	else
	{
		printf("BAD ARGS [%d/%d]\n", op_tab[file->token.code - 1].arguments,
			   file->token.count_args);
		return (ERR_BAD_TOKEN_INSTRUCTION + 40);
	}

	//определяем аргументы
	//три функции будет для (r1-99, %, int)



// потом сохранить строку с атрибутами и разбить ее на отдельные - почти есть!
// проверить каждый атрибут в соответствии с валидной командой

	//free(label);
	return (ERR_NORM);
}

/*
**	Возвращает валидную инструкцию в 16-й системе счисления
*/

int	get_instruction(t_file *file)
{
	int check;

	check = 0;
	if (!file->flag_name || !file->flag_comment)
		check = check_header(file);
	else
	{
		get_tokens(file);
		printf("LABEL[%zu]\t", file->token.label ? ft_strlen(file->token
			.label) : 0);
		printf(">%s<\t", file->token.label);
		printf("нашли - >%s<\t", file->token.inst);
		printf("определили - >%s<\t", file->token.code > 0 ?
			op_tab[file->token.code - 1].name : "NO");
		printf("нашли - >%s<\t", file->token.inst);
		printf("кол-во арг. - >%d<\t", file->token.count_args);

// ОПАСНО!!!!!!  тут free INST и LABEL из структуры!!!!!!
		if (file->token.label)
			free(file->token.label);
		if (file->token.inst)
			free(file->token.inst);
		ft_memset(&file->token, 0, sizeof(t_token));

	}
	printf("\n************************%d************************\n", check);
	return (check);
}
