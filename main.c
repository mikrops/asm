/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 14:35:51 by mmonahan          #+#    #+#             */
/*   Updated: 2019/11/02 18:43:11 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include <stdio.h>

int validation(int fd, char *namefile)
{
	if (fd < 1)
		return (2);
	if (namefile[0] == '-')
		return (3);



	return (0);
}

int main(int argc, char **argv)
{
	printf("Hello, asm!\n");

	int fd;

	fd = 0;
	if (argc != 2)
		return (1);
	fd = open(argv[1], O_RDONLY);
	// check fd!!!!!
	// check argv[1]???


	close(fd);
	return 0;
}