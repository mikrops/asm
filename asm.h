/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 20:40:49 by mmonahan          #+#    #+#             */
/*   Updated: 2019/12/16 20:33:36 by mmonahan         ###   ########.fr       */
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
# define ERR_BAD_TOKEN_INSTRUCTION 6

// статусы Хедера под это переделать
# define CHK_HEADER_BEGIN 0
# define CHK_HEADER_BEFORE 1
# define CHK_HEADER_IN 2
# define CHK_HEADER_STRING 2
# define CHK_HEADER_AFTER 3
# define CHK_HEADER_END 4

// Токены инструкций
# define LABEL 10

# define INSTRUCTION 20

# define REGISTER 30 		//	T_REG	'r'	01	1
# define DIRECT 40			//	T_DIR	'%'	10	T_DIR*
# define DERICT_LABEL 45	//	T_DIR	'%'	10	T_DIR*
# define INDIRECT 50		//	T_IND	''	11	2
# define INDERICT_LABEL 55	//	T_IND	''	11	2

# define SEPARATOR 60



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


// после валидации будет массив на n-е количество инструкций
typedef struct	s_token
{
	char		*label;
	char		*inst;
	int 		number;
	int 		count_args;
	char 		**args;
/*	int 		arg_1;
	int 		arg_2;
	int 		arg_3;*/
}				t_token;

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
	t_token		token;
//	t_list		label;
}				t_file;



/*typedef struct	s_operation
{
	int			name;
	int 		code1;
	int 		op[3];
	int			code2;
	int 		round;
	int			code3;
	int			code4;
}				t_operation;

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
};*/


typedef struct	s_operation
{
	char		*name;
	int 		arguments;
	int 		op[3];
	int			code;
	int			cycle;
	int			code4;
	int			code5;
}				t_operation;

static t_operation	op_tab[17] =
{
	{"live", 1, {T_DIR}, 1, 10, 0, 0},
	{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, 1, 0},
	{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, 1, 0},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, 1, 0},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, 1, 0},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
  		1, 0},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6, 1,
  		0},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
  		1, 0},
	{"zjmp", 1, {T_DIR}, 9, 20, 0, 1},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25, 1, 1},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25, 1, 1},
	{"fork", 1, {T_DIR}, 12, 800, 0, 1},
	{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, 1, 0},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50, 1, 1},
	{"lfork", 1, {T_DIR}, 15, 1000, 0, 1},
	{"aff", 1, {T_REG}, 16, 2, 1, 0},
	{0, 0, {0}, 0, 0, 0, 0}
};

void			put_exception(int error);
int				get_instruction(t_file *file);
int				validation(t_file *file);

#endif
