/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_instruction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 20:17:13 by mmonahan          #+#    #+#             */
/*   Updated: 2019/12/27 09:48:35 by mmonahan         ###   ########.fr       */
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
			if (!FL)
				FL = ft_memalloc(sizeof(t_label));
			else
			{
				FL->next = ft_memalloc(sizeof(t_label));
				FL = FL->next;
			}
			FL->name = ft_strncpy(ft_strnew(*i), FS, *i);
			FL->offset = file->exec_size;
			return (*i);
		}
		else
			break ;
	}
	*i = start;
	return (0);
}

void	check_arg(t_file *file, int num, int dir_s, int i)
{
	if (file || num || dir_s || i)
		;
}

int		check_inst(t_file *file, int i)
{
	int	op_i;

	op_i = -1;
	while (op_tab[++op_i].name)
		if (ft_strncmp(op_tab[op_i].name, file->string + i,
					   ft_strlen(ft_strcut(file->string + i, ' '))) == 0 ||
			ft_strncmp(op_tab[op_i].name, file->string + i,
					   ft_strlen(ft_strcut(file->string + i, '%'))) == 0)
		{
			if (!FT)
				FT = ft_memalloc(sizeof(t_token));
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

int		check_instruction(t_file *file)
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
		return (ERR_CHOOOOO);
	}
	i++;
	return (ERR_NORM);
}
