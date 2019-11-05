/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 14:35:51 by mmonahan          #+#    #+#             */
/*   Updated: 2019/11/05 17:32:08 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_operation	op_tab[17] = {
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

int validation(char *namefile)
{
	int fd;
	int rez;

	fd = open(namefile, O_RDONLY);
	rez = ERR_NORM;
	if (fd < 1)
		rez = ERR_INCORECT_FILE;
	close(fd);
	return (rez);
}

int main(int argc, char **argv)
{
	int err;

	err = 0;
	if (argc == 2)
		err = validation(argv[1]);
	else
		err = ERR_ONE_ATRIBUTE;
	put_exception(err);
	return 0;
}

/*
**	выводить 3 строки, 1-я до, 2-я где зафиксированная ошибка, 3-я после
**	Для нее можно сделать структурку))
*/