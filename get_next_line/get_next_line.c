/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 21:05:18 by mmonahan          #+#    #+#             */
/*   Updated: 2019/10/23 19:45:56 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
**	GNL in the shape of a glove of infinity welcomes You!
**
**	Calling your function get_next_line in a loop will then allow you to read
**	the text available on a file descriptor one line at a time until the end
**	of the text, no matter the size of either the text or one of its lines.
**
**	The return value can be 1, 0 or -1 depending on whether a line has been
**	read, when the reading has been completed, or if an error has happened
**	respectively.
**	Your function get_next_line must return its result without ’\n’.
**
**	The first parameter is the file descriptor that will be used to read.
**	The second parameter is the address of a pointer to a character that
**	will be used to save the line read from the file descriptor.
**
**
**	ГНЛ в форме перчатки бесконечности, приветствует Тебя!
**
**	Вызов вашей функции get_next_line в цикле позволит вам читать текст,
**	доступный в дескрипторе файла, по одной строке за раз до конца текста,
**	независимо от размера текста или одной из его строк.
**
**	Возвращаемое значение может быть 1, 0 или -1 в зависимости от того, была ли
**	прочитана строка, когда считывание было завершено или произошла ошибка,
**	соответственно.
**	Ваша функция get_next_line должна возвращать свой результат без '\ n'.
**
**	Первый параметр - это дескриптор файла, который будет использоваться
**	для чтения.
**	Второй параметр - это адрес указателя на символ, который будет
**	использоваться для сохранения строки, прочитанной из файлового дескриптора.
*/

int	get_next_line(const int fd, char **line)
{
	static char	*m[10240];
	int			ret;
	char		buf[BUFF_SIZE + 1];
	char		*tmp;

	if (fd < 0 || fd >= 10240 || line == NULL)
		return (-1);
	if (ft_memset(buf, 0, BUFF_SIZE + 1) && (ret = 1) && m[fd] == NULL)
		m[fd] = ft_memalloc(1);
	while (ft_strchr(m[fd], '\n') == NULL && (ret = read(fd, buf, BUFF_SIZE)))
	{
		if ((tmp = m[fd]) && ret < 0)
			return (-1);
		if ((m[fd] = ft_strjoin(tmp, buf)) && ft_memset(buf, 0, BUFF_SIZE + 1))
			ft_strdel(&tmp);
		if (ft_strchr(m[fd], '\n') != NULL || ret != BUFF_SIZE)
			break ;
	}
	*line = ft_strchr(m[fd], '\n') ? ft_strsub(m[fd], 0, ft_charcount(m[fd],
		'\n')) : ft_strsub(m[fd], 0, ft_strlen(m[fd]) + 1);
	tmp = m[fd];
	m[fd] = ft_strsub(tmp, ft_charcount(tmp, '\n') + 1, ft_strlen(tmp) -
		ft_charcount(tmp, '\n'));
	ft_strdel(&tmp);
	return (!(!ret && !ft_strlen(*line)));
}
