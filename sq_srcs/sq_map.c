/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sq_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saxiao <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 11:15:35 by saxiao            #+#    #+#             */
/*   Updated: 2017/11/20 12:20:11 by saxiao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "sq_fillit.h"
#include "../includes/libft/libft.h"

int		mini_sq(int nb_retri)
{
	int		i;

	i = 1;
	while ( i * i <= nb_retri * 4)
		i++;
	return (i);
}

void	print_tetri(unsigned short t)
{
	int		i;

	i = 15;
	while (i >= 0)
	{
		if (t & (1 << i))
			printf("1");
		else
			printf("0");
	}
	printf("\n");
}

int		main(int ac, char **av)
{
	tetri_list	*list;


	if(ac != 2)
		ft_exit("not valie file number");
	list = ft_readfile(av[1]);

	while(list)
	{
		print_tetri(list->tetri_value);
		list = list->next;
	}
	
	return (0);
}
