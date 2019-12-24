/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_instruction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 20:17:13 by mmonahan          #+#    #+#             */
/*   Updated: 2019/12/24 20:28:32 by mmonahan         ###   ########.fr       */
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
**	Если строка содержит только "маленькие" символы, то возвращает ее длину,
**	иначе 0
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
**	Возвращает строрку до символа 'c'
*/

char	*ft_strcut(const char *str, int c)
{
	int		i;
	int		len;
	char	*rezult;

	i = 0;
	len = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == c)
			break ;
		i++;
		len++;
	}
	i = 0;
	rezult = ft_memalloc(len + 1);
	while (i < len)
	{
		rezult[i] = str[i];
		i++;
	}
	rezult[i] = '\0';
	return (rezult);
}

/*
**	Делить строку на токены
*/

int get_tokens(t_file *file)
{
	int		i;
	int 	len_lab;
	int 	len_inst;

	i = 0;
	len_lab = 0;
	len_inst = 0;

	//обрезаем комментарий
	file->string = ft_strcut(file->string, '#');
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

	printf("проверка отстатка от нахождения LABEL = >%s<\n", &file->string[i]);

	// пропускаем пробелы
	while (ft_isspace(file->string[i]))
		i++;

	// проверяем конец файла или начало комента после Lable
	if (file->string[i] == '\0' || file->string[i] == COMMENT_CHAR)
		return	(ERR_NORM);

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

	if (file->string[i] == '\0' || file->string[i] == COMMENT_CHAR)
		return	(ERR_BAD_TOKEN_INSTRUCTION + 100);

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

	// проверяем аргументы на валидность в команде
	// проверить каждый атрибут в соответствии с валидной командой
// занести результаты в file->token.op и сравнить в оригинальным op[3]
	i = 0;
	k = 0;
	while (i < file->token.count_args)
	{
		if (get_reg(file->token.args[i]) == T_REG)
			file->token.op[i] = T_REG;
		else if (get_dir(file->token.args[i]) == T_DIR)
			file->token.op[i] = T_DIR;
		else if (get_ind(file->token.args[i]) == T_IND)
			file->token.op[i] = T_IND;
		else
			return (ERR_BAD_TOKEN_ARGUMENT + 10);
			//file->token.op[i] = -1;
		i++;
	}

	//проверяем на соответствие типов аргументов

	i = 0;
	while (i < file->token.count_args)
	{
		if (op_tab[file->token.code - 1].op[i] & file->token.op[i])
			;
		else
			return (ERR_BAD_TOKEN_ARGUMENT + 20);
		i++;
	}

	//free(label);
	return (ERR_NORM);
}

/*
**	Возвращает валидную инструкцию в 16-й системе счисления
*/

int	get_instruction(t_file *file)
{
	int check;
	int i;

	check = 0;
	i = 0;
	if (!file->flag_name || !file->flag_comment)
		check = check_header(file);
	else
	{
		check = get_tokens(file);
		printf("LABEL[%zu]\t", file->token.label ? ft_strlen(file->token
			.label) : 0);
		printf(">%s<\t| ", file->token.label);
		printf("нашли - >%s<\t| ", file->token.inst);
		printf("определили - >%s<\t| ", file->token.code > 0 ?
			op_tab[file->token.code - 1].name : "NO");
		printf("нашли - >%s<\t| ", file->token.inst);
		printf("кол-во арг. - >%d<\t| ", file->token.count_args);
		while (i < file->token.count_args)
		{
			printf("[%d]>%d< ", i, file->token.op[i]);
			i++;
		}

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
