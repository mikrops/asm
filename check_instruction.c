/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_instruction.c                                  :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: yjohns <yjohns@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 00:17:40 by yjohns            #+#    #+#             */
/*   Updated: 2020/02/29 04:23:41 by yjohns           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
**	Если label валидный, то возвращает его длину, иначе 0
*/

int		check_label(t_file *file, int *i)
{
	int		start;

	start = *i;
	while (FS[*i])
	{
		if (ft_strchr(LABEL_CHARS, FS[*i]))
			(*i)++;
		else if (FS[*i] == LABEL_CHAR)
		{
			if (!FL && (FL = ft_memalloc(sizeof(t_label))))
				file->start_label = FL;
			else
			{
				FL->next = ft_memalloc(sizeof(t_label));
				FL = FL->next;
			}
			FL->name = ft_strncpy(ft_strnew(*i), FS, (*i)++);
			FL->offset = file->exec_size;
			return (*i - start);
		}
		else
			break ;
	}
	*i = start;
	return (0);
}

int		read_arg_reg(const char *str, t_file *file, int arg)
{
	int i;
	int	num;

	i = 0;
	while (str[i] != 'r')
		i++;
	i++;
	num = ft_atoi(str + i);
	if (num > REG_NUMBER || num < 0)
	{
		printf("error read_arg_reg");
		exit(1);
	}
	else
	{
		FT->op[arg][1] = num;
	}
	return (T_REG);
}

void	read_arg_label(const char *str, t_file *file, int i, int num)
{
	while (str[i] && !ft_strnstr(LABEL_CHARS, &str[i], 1))
		i++;
	if (!FT->label && (FT->label = ft_memalloc(sizeof(t_label))))
		FT->start_label = FT->label;
	else
	{
		FT->label->next = ft_memalloc(sizeof(t_label));
		FT->label = FT->label->next;
	}
	FT->label->name = (char *)malloc(i - num);
	FT->label->name = ft_strncpy(FT->label->name, str + num, i - num);
	FT->label->len = i - num;
}

int		read_arg_dir(const char *str, t_file *file, int arg)
{
	int i;
	int	num;

	i = 0;
	while (str[i] != '%')
		i++;
	i++;
	if (ft_isdigit(str[i]))
	{
		num = ft_atoi(str + i);
		FT->op[arg][1] = num;
		return (T_DIR);
	}
	else if (str[i] == ':')
	{
		num = ++i;
		read_arg_label(str, file, i, num);
		return (DIR_L_CODE);
	}
	return (0);
}

int		read_arg_ind(const char *str, t_file *file, int arg)
{
	int i;
	int	num;

	i = 0;
	while (!ft_isdigit(str[i]) && str[i] != ':')
		i++;
	if (ft_isdigit(str[i]))
	{
		num = ft_atoi(str + i);
		FT->op[arg][1] = num;
		return (T_IND);
	}
	else if (str[i] == ':')
	{
		num = ++i;
		read_arg_label(str, file, i, num);
		return (IND_L_CODE);
	}
	return (0);
}

int	check_arg(t_file *file, int op_i, int dir_s, int *len)
{
	char	**args;
	int 	i;

	dir_s = 0; // нужна для тогото тогото
	i = 0;
	args = ft_strsplit(file->string + *len + 1, SEPARATOR_CHAR);
	while (i < op_tab[op_i].arguments)
	{
		if (get_reg(args[i], file) && read_arg_reg(args[i], file, i))
			FT->op[i][0] = T_REG;
		else if (get_dir(args[i]))
			FT->op[i][0] = read_arg_dir(args[i], file, i);
		else if (get_ind(args[i]) == T_IND)
			FT->op[i][0] = read_arg_ind(args[i], file, i);
		else
			return (ERR_CHOOOOO);
		if ((FT->op[i][0] & op_tab[op_i].op[i]) == 0)
			return(ERR_CHOOOOO);
		i++;
	}
	*len += i;
	return (ERR_NORM);
}

int		check_inst(t_file *file, int i)
{
	int	op_i;

	op_i = -1;
	while (op_tab[++op_i].name)
		if (ft_strncmp(op_tab[op_i].name, file->string + i,
					   ft_strlen(ft_strcut(file->string + i, ' '))) == 0 ||
				ft_strncmp(op_tab[op_i].name, file->string + i,
						ft_strlen(ft_strcut(file->string + i, '\t'))) == 0 ||
			ft_strncmp(op_tab[op_i].name, file->string + i,
					   ft_strlen(ft_strcut(file->string + i, '%'))) == 0)
		{
			if (!FT && (FT = ft_memalloc(sizeof(t_token))))
				file->start_token = FT;
			else
			{
				FT->next = ft_memalloc(sizeof(t_token));
				FT = FT->next;
			}
			FT->code = op_i + 1;
			i += ft_strlen(op_tab[op_i].name);
			if (check_arg(file, op_i,
					  (op_tab[op_i].code5 == 1 ? 2 : 4), &i) != ERR_NORM)
				return (0);
			return (i);
		}
	return (0);
}

int	check_instruction(t_file *file)
{
	int		i;
	int		len;

	i = 0;
	FS = ft_strcut(FS, '#');
	while (ft_isspace(FS[i]))
		i++;
	if (!FS[i])
		return (ERR_NORM);
	if (!(check_inst(file, i)))
	{
		if (!(len = check_label(file, &i)))
			return(ERR_CHOOOOO);//error не инструкция и не команда
		else
		{
			FL->len = len;
			while (ft_isspace(FS[i]))
				i++;
			if (FS[i])
				check_inst(file, i);
		}
	}
	i++;
	return (ERR_NORM);
}
