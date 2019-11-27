/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 20:40:49 by mmonahan          #+#    #+#             */
/*   Updated: 2019/11/27 20:36:24 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_ASM_H
# define ASM_ASM_H

# include <stdio.h> // УДАЛТЬ !!! ПРИНТФ!!!

# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include "op.h"

/*
**	Errors
*/

# define ERR_NORM 0
# define ERR_ONE_ATRIBUTE 1
# define ERR_BAD_NAME_FILE 2
# define ERR_NO_OPEN_FILE 3
# define ERR_NO_CREAT_FILE 4
# define ERR_BEAD_HEADER 5





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

typedef struct	s_file
{
	char 		*file;
	char 		*string;
	char 		*namefile;
	int 		fd_open;
	int 		fd_creat;
}				t_file;

void			put_exception(int error);
char			*get_instruction(const char *string);
int				validation(char *namefile);

#endif
