/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetri.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 20:31:49 by fsabatie          #+#    #+#             */
/*   Updated: 2017/11/12 20:31:52 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fill_it.h"
#include <stdlib.h>
#include <stdio.h>

/*
** Converts the char* string from input to a byte.
*/

static	short	int	ft_strtobyte(char *str)
{
	char		tet[BUFF_SIZE + 1];
	short	int i;
	short	int c;
	short	int n;

	c = 0;
	n = 0;
	i = 15;
	ft_strcpy(tet, str);
	ft_strrev(tet);
	while (n < (short)ft_strlen(tet))
	{
		if (tet[n] == '#')
			c = c | (1 << i);
		if (tet[n] == '.' || tet[n] == '#')
			i--;
		n++;
	}
	return (c);
}

/*
** Print bits of tetri.
*/

void				ft_printbytetetri(short int c)
{
	short int i;

	i = 0;
	while (i < 16)
	{
		if (c & 1 << i)
			ft_putnbr(1);
		else
			ft_putnbr(0);
		i++;
		if (!(i % 4) && i > 3)
			ft_putchar('\n');
	}
}

t_etrimino			*ft_newtetri(char *tet)
{
	t_etrimino	*tetrimino;

	if (!(tetrimino = (t_etrimino*)malloc(sizeof(tetrimino))))
		return (NULL);
	tetrimino->c_tet = ft_strtobyte(tet);
	tetrimino->width = 0;
	tetrimino->height = 0;
	return (tetrimino);
}
