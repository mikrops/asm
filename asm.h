/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 20:40:49 by mmonahan          #+#    #+#             */
/*   Updated: 2019/12/27 08:39:03 by mmonahan         ###   ########.fr       */
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
# define ERR_NO_ATRIBUTE 1 // ---
# define ERR_BAD_NAME_FILE 2
# define ERR_NO_OPEN_FILE 3
# define ERR_NO_CREAT_FILE 4
# define ERR_BAD_HEADER 5
# define ERR_BAD_TOKEN_INSTRUCTION 6
# define ERR_BAD_TOKEN_ARGUMENT 7
# define ERR_INVALID_CODE 8
# define ERR_CHOOOOO 80000


# define CHK_NAME_START 1
# define CHK_NAME_END 2
# define CHK_COMMENT_START 1
# define CHK_COMMENT_END 2

/*
**	yjohns
*/

# define FT file->token
# define FL file->label
# define FS file->string


typedef struct		s_token
{
	unsigned char 	code;
	int 			size;
	int 			op[3][2];
	int 			flag;
	char 			*label;
	struct s_token	*next;
}					t_token;

typedef struct		s_label
{
	char 			*name;
	unsigned int	offset;
	int 			len;
	struct s_label	*next;
}					t_label;

typedef struct	s_file
{
	char 			*string;
	char 			*namefile;
	int 			fd_open;
	int 			fd_creat;

	int 			iter;
	int				flag_name;
	int 			flag_comment;

/*
 * В данном случае подразумевается, что токен - команда и её описание.
 * Токены стали ссылками, так как необходимо будет сохранять, а не перезаписывать команды.
 *
 * Строка str[652] - строка содержащая байт код для вывода в файл
 * Число exec_size - общее количество байт исполняемого кода. Актуально после замены меток на число
*/

//	t_list		label;
	unsigned char	exec_str[CHAMP_MAX_SIZE];
	int 			exec_size;

	t_header		header;
	t_token			*start_token;
	t_token			*token;
	t_label			*start_label;
	t_label			*label;
}					t_file;

typedef struct		s_operation
{
	char			*name;
	int 			arguments;
	int 			op[3];
	int				code;
	int				cycle;
	int				code4;
	int				code5;
}					t_operation;

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

void			cmd_to_byte_code(t_file *file);
void			put_exception(t_file *file, int error);
int				check_instruction(t_file *file);
int				creat_fill_file(t_file *file);

int				validation(t_file *file);
int				get_reg(const char *str);
int				get_dir(const char *str);
int				get_ind(const char *str);
int				get_argument(t_file *file);
int				check_header(t_file *file);


#endif
