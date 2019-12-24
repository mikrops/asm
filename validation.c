/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 11:37:56 by mmonahan          #+#    #+#             */
/*   Updated: 2019/12/24 20:40:58 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		test_command();

#include "asm.h"

/*
**	Возвращает 0, если имя файла нормальное, в противном случае 1
*/

static int	check_name_file(const char *name_file)
{
	int	length;

	length = ft_strlen(name_file);
	if (name_file[length - 1] != 's')
		return (1);
	if (name_file[length - 2] != '.')
		return (1);
	if (!ft_isdigit(name_file[length - 3]) &&
		!ft_isalpha(name_file[length - 3]))
		return (1);
	return (0);
}

/*
**	Валидация файла
*/

int	validation(t_file *file)
{
	int error_header;
	int count_instr;

	error_header = 0;
	count_instr = 0;
	if (check_name_file(file->namefile))
		return (ERR_BAD_NAME_FILE);
	file->fd_open = open(file->namefile, O_RDONLY);
	if (file->fd_open < 1)
		return (ERR_NO_OPEN_FILE);

	// сохраненяем файл в массив построчно и проверяем его
	while (get_next_line(file->fd_open, &file->string))
	{
		if (file->string[0] != '\0')
			count_instr++;

		// check_string(string);
		error_header = get_instruction(file);
		if (error_header)
			break ;

		file->file = ft_str_rejoin(file->file, file->string);
		ft_strdel(&file->string);
		file->file = ft_str_rejoin(file->file, "\n");
	}
	ft_strdel(&file->string);
	close(file->fd_open);
	if (error_header)
		return (ERR_INVALID_CODE);//(error_header);

	//создание и заполнение файла только после проюождения валидации
	//можно вообще в отдельный файл жахнуть
	creat_fill_file(file);

	printf("\n\nfile = >%s<\nnamefile = >%s<\nflag_name = >%d<\nflag_comment = "
		">%d<\nprog_name = >%s<\ncomment = >%s<\n",
			file->file,
			file->namefile,
			file->flag_name,
			file->flag_comment,
			file->header.prog_name,
			file->header.comment);
	printf("количество интсрукций = >%d<\n", count_instr);

	//test_command();

	return (ERR_NORM);
}

void test_command()
{
	//***************************ЭКСПЕРЕМЕНТЫ*****************************

	printf("\n***********start get_reg*************************\n");
	char *check_reg[100] = {"r1", " r01 ", " r51 ", "r01", "r0", "r", "r00",
							" r99 ", "e99", "e r01", "r01 e", "r999", " r ",
							"rr1", "r1r1", ""};
	int arr_reg = 0;
	while (arr_reg < 15)
	{
		printf("n[%d]\t>%s<\t = %s\n", arr_reg, check_reg[arr_reg],
			   get_reg(check_reg[arr_reg]) ? "***" : "NORM");
		arr_reg++;
	}
	printf("*****************end get_reg*********************\n");
	printf("\n");
	printf("\n***********start get_dir*************************\n");
	char *check_dir[100] = {"%1", " %1 ", " %9812 ", "%0001", "%00009999",
							" %:live", "%:l", " %-1 ", "%-1", "%:li ", " %:l3",
							"%:l_2", "%:l_3_aa", "%-00002 ", " %-000009999",
							"%:999", "%9283498237", "%982374987234982743982743",
							"%00000000000000000000197823472349823469283649238838"};
	int arr_dir = 0;
	int flag_dir = 0;
	while (arr_dir < 19)
	{
		flag_dir = get_dir(check_dir[arr_dir]);
		printf("n[%d]\t>%s<\t = %s[%d]\n", arr_dir, check_dir[arr_dir],
			   flag_dir ? "***" : "NORM", flag_dir);
		arr_dir++;
	}
	printf("*****************end get_dir*********************\n");
	printf("\n");
	printf("\n***********start get_ind*************************\n");
	char *check_ind[100] = {"1", " 1 ", " 9812 ", "0001", "00009999",
							" :live", ":l", " -1 ", "-1", ":li ", " :l3",
							":l_2", ":l_3_aa", "-00002 ", " -000009999",
							":999", "9283498237", "982374987234982743982743",
							"00000000000000000000197823472349823469283649238838"};
	int arr_ind = 0;
	int flag_ind = 0;
	while (arr_ind < 19)
	{
		flag_ind = get_ind(check_ind[arr_ind]);
		printf("n[%d]\t>%s<\t = %s[%d]\n", arr_ind, check_ind[arr_ind],
			   flag_ind ? "***" : "NORM", flag_ind);
		arr_ind++;
	}
	printf("*****************end get_ind*********************\n");
}