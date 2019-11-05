/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 20:40:49 by mmonahan          #+#    #+#             */
/*   Updated: 2019/11/05 19:57:25 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_ASM_H
# define ASM_ASM_H

# include <stdio.h> // УДАЛТЬ !!! ПРИНТФ!!!

# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include "resources/op.h"

/*
**	Errors
*/

# define ERR_NORM 0
# define ERR_ONE_ATRIBUTE 1
# define ERR_BAD_NAME_FILE 2
# define ERR_INCORECT_FILE 3

typedef enum	e_command
{
	LIVE,
	LD,
	ST,
	ADD,
	SUB,
	AND,
	OR,
	XOR,
	ZJMP,
	LDI,
	STI,
	FORK,
	LLD,
	LLDI,
	LFORK,
	FFF
}				t_command;

typedef struct	s_operation
{
	int			name;
	int 		code1;
	int 		op[3];
	int			code2;
	int 		round;
	int			code3;
	int			code4;
}				t_operation;

void			put_exception(int error);

#endif
