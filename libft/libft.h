/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 21:16:18 by mmonahan          #+#    #+#             */
/*   Updated: 2020/02/14 19:41:24 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIBFT_H
# define FT_LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>

/*
** V.2 Part 1 - Libc functions
** V.2 Часть 1 - Функции Libc
*/

void				*ft_memset(void *s, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack, const char *needle,
					size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);

/*
** V.3 Part 2 - Additional functions
** V.3 Часть 2 - Дополнительные функции
*/

void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);

/*
** The structure of a single-linked list t_list
** Структура односвязного списка t_list
*/

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

/*
** Bonus part
** Бонусная часть
*/

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(f)(t_list *elem));

/*
**	My functions
**	Мои функции
*/

size_t				ft_wordcount(char const *s, char c);
size_t				ft_charcount(char const *s, char c);
void				ft_strfree(char **s, size_t n);
size_t				ft_intcount(int n);
int					ft_isupper(int n);
int					ft_islower(int n);
int					ft_isspace(int c);
size_t				ft_lstlen(t_list *lst);
void				ft_del(void *content, size_t size);

/*
**	My extra functions (filler)
**	Мои подопнительные функции (filler)
**
**	2019/09/23 14:47:07
*/

char				**ft_map_char(int row, int col);
int					**ft_map_int(int row, int col);
void				ft_put_map_int_fd(int **map, int row, int col, int fd);
void				ft_put_map_chr_fd(char **map, int row, int col, int fd);
void				ft_map_int_del(int **map, size_t row);
void				ft_map_chr_del(char **map, size_t row);

/*
**	My extra functions (fdf)
**	Мои подопнительные функции (fdf)
**
**	2019/10/14 18:59:07
*/

int					ft_pow(int number, int pow);
int					ft_atoi_base(char *str, int base);
void				**ft_map_void(int row, int col, size_t size_row,
					size_t size_col);
void				ft_map_void_del(void **map, size_t row);
double				ft_degtorad(double degree);
double				ft_radtodeg(double radian);
char				*ft_str_rejoin(char *s1, char const *s2);

/*
**	My extra functions (asm)
**	Мои подопнительные функции (asm)
**
**	yjohns заценила ft_strcut!!!
**
**	2019/12/25 20:13:43
*/

char				*ft_strcut(const char *str, int c);
#endif
