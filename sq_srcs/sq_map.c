/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sq_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saxiao <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 11:15:35 by saxiao            #+#    #+#             */
/*   Updated: 2017/11/20 11:30:33 by saxiao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int		main(int ac, char **av)
{
	tetri_list	*list;


	if(ac != 2)
		ft_exit("not valie file number");
	list = ft_readfile(av[1]);

	
	return (0);
}
