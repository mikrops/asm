/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_fill_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 20:38:48 by mmonahan          #+#    #+#             */
/*   Updated: 2020/01/26 17:44:13 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void print_bits(unsigned char octet);
unsigned int reverse_bits_int(unsigned int octet);

#include "asm.h"

int write_header(t_file *file)
{
//	записал magic в файл))) !!!!!!!!!!!!! ИСПРАВИТЬ  !!!!!!!!!!!!!!

//orig >>
	/*
	unsigned int i = COREWAR_EXEC_MAGIC;
	file->header.magic = i << 8;
	write(file->fd_creat, &file->header.magic, 4);
	*/
//orig <<

//laponin >>
	unsigned int i = COREWAR_EXEC_MAGIC;
	file->header.magic = i;
	//file->header.magic = reverse_bits_int(i);
	/*
------------------------------------------------
	 0000 0000 1110 1010 1000 0011 1111 0011
>> 24
	 0000 0000 0000 0000 0000 0000 0000 0000
<< 0
	 0000 0000 0000 0000 0000 0000 0000 0000
|	 0000 0000 0000 0000 0000 0000 0000 0000
=	 0000 0000 0000 0000 0000 0000 0000 0000
------------------------------------------------
	 0000 0000 1110 1010 1000 0011 1111 0011
>> 16
	 0000 0000 0000 0000 0000 0000 1110 1010
<< 8
	 0000 0000 0000 0000 1110 1010 0000 0000
|	 0000 0000 0000 0000 0000 0000 0000 0000
=	 0000 0000 0000 0000 1110 1010 0000 0000
------------------------------------------------
	 0000 0000 1110 1010 1000 0011 1111 0011
>> 8
	 0000 0000 0000 0000 1110 1010 1000 0011
<< 16
	 1000 0011 0000 0000 0000 0000 0000 0000
>> 8
	 0000 0000 1000 0011 0000 0000 0000 0000
|	 0000 0000 0000 0000 1110 1010 0000 0000
=	 0000 0000 1000 0011 1110 1010 0000 0000
------------------------------------------------
	 0000 0000 1110 1010 1000 0011 1111 0011
>> 0
	 0000 0000 1110 1010 1000 0011 1111 0011
<< 24
	 1111 0011 0000 0000 0000 0000 0000 0000
|	 0000 0000 1000 0011 1110 1010 0000 0000
=	 1111 0011 1000 0011 1110 1010 0000 0000
------------------------------------------------
	 * */
	file->header.magic |= i >> 24 << 0;
	file->header.magic |= i >> 16 << 8;
	file->header.magic |= i >> 8 << 16;
	file->header.magic |= i << 0 << 24;

//	unsigned int g[3] = COREWAR_EXEC_MAGIC;
//	unsigned int g[2] = COREWAR_EXEC_MAGIC;
//	unsigned int g[1] = COREWAR_EXEC_MAGIC;
//	unsigned int g[0] = COREWAR_EXEC_MAGIC;
	write(file->fd_creat, &file->header.magic, 4);
//laponin <<

//	записал name в файл)))
	write(file->fd_creat, &file->header.prog_name, PROG_NAME_LENGTH);
//	записал 4 нуля в файл)))
	i = 0;
	write(file->fd_creat, &i, 4);
//	записал размер кода в файл)))
	file->header.prog_size = 16;
	file->header.prog_size = file->header.prog_size << 24;
	write(file->fd_creat, &file->header.prog_size, 4);
//	записал comment в файл)))
	write(file->fd_creat, &file->header.comment, COMMENT_LENGTH);
//	записал 4 нуля в файл)))
	i = 0;
	write(file->fd_creat, &i, 4);
	return (ERR_NORM);
}

/*
**	Возврящает имя нового файла
*/

static char	*creat_name_file(const char *old_name)
{
	int		length;
	char	*new_name;

	length = ft_strlen(old_name);
	new_name = ft_memalloc(length + 3);
	ft_strcpy(new_name, old_name);
	new_name[length - 1] = 'c';
	new_name[length] = 'o';
	new_name[length + 1] = 'r';
	return (new_name);
}

/*
**	Возврящает 0 если файл создался и заполнился, иначе номер ошибки
*/

int			creat_fill_file(t_file *file)
{
	char *new_name;

	new_name = creat_name_file(file->namefile);
	file->fd_creat = creat(new_name, 00777);
	//free(new_name);
	if (file->fd_creat < 1)
		return (ERR_NO_CREAT_FILE);

	write_header(file);

//ЗАПИСАТЬ ОСТАЛЬНОЙ КОД ИЗ КАКОГО НИБУДЬ СПИСКА!!!!
// ...
	//*** yjohns ***
	//write(fd, file->exec_str, file->exec_size);
	write(file->fd_creat, file->exec_str, file->exec_size);
	close(file->fd_creat);
	return (ERR_NORM);
}


void print_bits(unsigned char octet)
{
	int i;
	unsigned char bit;

	i = 8;
	while (i--)
	{
		bit = (octet >> i & 1) + '0';
		write(1, &bit, 1);
	}
}

unsigned int reverse_bits_int(unsigned int octet)
{
	return (((octet >> 0) & 1) << 31) |
		   (((octet >> 1) & 1) << 30) |
		   (((octet >> 2) & 1) << 29) |
		   (((octet >> 3) & 1) << 28) |
		   (((octet >> 4) & 1) << 27) |
		   (((octet >> 5) & 1) << 26) |
		   (((octet >> 6) & 1) << 25) |
		   (((octet >> 7) & 1) << 24) |

		   (((octet >> 8) & 1) << 23) |
		   (((octet >> 9) & 1) << 22) |
		   (((octet >> 10) & 1) << 21) |
		   (((octet >> 11) & 1) << 20) |
		   (((octet >> 12) & 1) << 19) |
		   (((octet >> 13) & 1) << 18) |
		   (((octet >> 14) & 1) << 17) |
		   (((octet >> 15) & 1) << 16) |

		   (((octet >> 16) & 1) << 15) |
		   (((octet >> 17) & 1) << 14) |
		   (((octet >> 18) & 1) << 13) |
		   (((octet >> 19) & 1) << 12) |
		   (((octet >> 20) & 1) << 11) |
		   (((octet >> 21) & 1) << 10) |
		   (((octet >> 22) & 1) << 9) |
		   (((octet >> 23) & 1) << 8) |

		   (((octet >> 24) & 1) << 7) |
		   (((octet >> 25) & 1) << 6) |
		   (((octet >> 26) & 1) << 5) |
		   (((octet >> 27) & 1) << 4) |
		   (((octet >> 28) & 1) << 3) |
		   (((octet >> 29) & 1) << 2) |
		   (((octet >> 30) & 1) << 1) |
		   (((octet >> 31) & 1) << 0);
}