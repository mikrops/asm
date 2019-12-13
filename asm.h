/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 20:40:49 by mmonahan          #+#    #+#             */
/*   Updated: 2019/12/13 20:18:12 by mmonahan         ###   ########.fr       */
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
# define ERR_BAD_HEADER 5

// статусы Хедера под это переделать
# define CHK_HEADER_BEGIN 0
# define CHK_HEADER_BEFORE 1
# define CHK_HEADER_IN 2
# define CHK_HEADER_STRING 2
# define CHK_HEADER_AFTER 3
# define CHK_HEADER_END 4

// Токены инструкций
# define LABEL 10
# define DERICT_LABEL 20

# define INSTRUCTION 30

# define REGISTRY 40
# define DIRECT 50
# define INDIRECT 60

# define SEPARATOR 70





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
	int 		iter;
	int 		status;
	int			flag_name;
	int 		flag_comment;

	t_header	header;
}				t_file;

static t_operation	op_tab[17] =
{
		{LIVE, 1, {T_DIR}, 1, 10, 0, 0},
		{LD, 2, {T_DIR | T_IND, T_REG}, 2, 5, 1, 0},
		{ST, 2, {T_REG, T_IND | T_REG}, 3, 5, 1, 0},
		{ADD, 3, {T_REG, T_REG, T_REG}, 4, 10, 1, 0},
		{SUB, 3, {T_REG, T_REG, T_REG}, 5, 10, 1, 0},
		{AND, 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6, 1, 0},
		{OR, 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6, 1, 0},
		{XOR, 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6, 1, 0},
		{ZJMP, 1, {T_DIR}, 9, 20, 0, 1},
		{LDI, 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25, 1, 1},
		{STI, 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25, 1, 1},
		{FORK, 1, {T_DIR}, 12, 800, 0, 1},
		{LLD, 2, {T_DIR | T_IND, T_REG}, 13, 10, 1, 0},
		{LLDI, 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50, 1, 1},
		{LFORK, 1, {T_DIR}, 15, 1000, 0, 1},
		{FFF, 1, {T_REG}, 16, 2, 1, 0},
		{0, 0, {0}, 0, 0, 0, 0}
};


/*typedef struct	s_operation
{
	char		*name;
	int 		code1;
	int 		op[3];
	int			code2;
	int			code3;
	char 		*round;
	int			code4;
	int			code5;
}				t_operation;

t_operation	op_tab[17] =
{
	{"live", 1, {T_DIR}, 1, 10, "alive", 0, 0},
	{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 0},
	{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 0},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 0},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
			"et (and  r1, r2, r3   r1&r2 -> r3", 1, 0},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
			"ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
			"ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0},
	{"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 1},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
			"load index", 1, 1},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
			"store index", 1, 1},
	{"fork", 1, {T_DIR}, 12, 800, "fork", 0, 1},
	{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 0},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
			"long load index", 1, 1},
	{"lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 1},
	{"aff", 1, {T_REG}, 16, 2, "aff", 1, 0},
	{0, 0, {0}, 0, 0, 0, 0, 0}
};*/

void			put_exception(int error);
int				get_instruction(t_file *file);
int				validation(t_file *file);

#endif
