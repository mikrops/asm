/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_instruction.c                                  :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: yjohns <yjohns@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 00:17:40 by yjohns            #+#    #+#             */
/*   Updated: 2019/12/27 16:55:54 by mmonahan         ###   ########.fr       */
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

void	check_arg(t_file *file, int num, int dir_s, int len)
{
	char	**args;
	int 	i;

	dir_s = 0; // нужна для тогото тогото
	i = 0;
	args = ft_strsplit(file->string + len + 1, SEPARATOR_CHAR);
	while (i < num)
	{
		if (get_reg(args[i]) == T_REG)
			FT->op[i][0] = REG_CODE;
		else if (get_dir(args[i]) == T_DIR)
			FT->op[i][0] = DIR_CODE;
		else if (get_ind(args[i]) == T_IND)
			FT->op[i][0] = IND_CODE;
		else
			exit(1);
		i++;
	}
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
			check_arg(file, op_tab[op_i].arguments,
					  (op_tab[op_i].code5 == 1 ? 2 : 4), i);
			return (1);
		}
	return (0);
}

int	check_instruction(t_file *file)
{
	int		i;

	i = 0;
	FS = ft_strcut(FS, '#');
	while (ft_isspace(FS[i]))
		i++;
	if (!FS[i])
		return (ERR_NORM);
	if (!(check_inst(file, i)) && !(FL->len = check_label(file, &i)))
	{
		printf(">%d<", ERR_CHOOOOO);
//		return (ERR_CHOOOOO);
//		exit (1);
	}
	if (FL->len)
		check_inst(file, i);
	i++;
	return (ERR_NORM);
}
