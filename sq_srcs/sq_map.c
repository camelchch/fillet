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

int		mini_sq(tetri_list *list)
{
	int		i;

	i = 1;
	while (list->next)
		list = list->next;
	while ( i * i <= (list->letter - 'A' + 1) * 4)
		i++;
	return (i);
}

short	int *fit_map(tetri_list *list)	
{
	short	int *map;

	if(!(map = (short int *)malloc(sizeof(*map) *mini_sq(list))))
	return (NULL);
	bzero(map,mini_sq(list) * sizeof(*map));






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
		i--;
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
