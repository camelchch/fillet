/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sq_rdfile_save_tetri.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saxiao <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 09:03:21 by saxiao            #+#    #+#             */
/*   Updated: 2017/11/20 12:20:07 by saxiao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <sys/fcntl.h>
#include <unistd.h>
#include <string.h>
#include "sq_fillit.h"
#include "../includes/libft/libft.h"

void	ft_exit(char const *s)
{
	ft_putendl(s);
	exit(1);
}

unsigned	short	tetri_value(char *s, int len)
{
	unsigned short	value;
	int					i;

	value = 0;
	i = 0;
	while (len - 2 > 0 )
	{
		if ((len -1) % 5)
		{
			if (s[len - 2] == '#')
				value = value | (1 << i);
			i++;
		}
		len--;
	}
	return (value);
}



void	only_dot_hash(char *s, int len)
{
	int		hash_count;
	int		index;

	hash_count = 0;
	index = 0;
	while (index < len)
	{
		if ((!((index + 1) % 5) || index == len -1))
		{
			if (s[index] != '\n')
				ft_exit("error");
		}
		else
		{
			if (s[index] != '.' && s[index] != '#')
				ft_exit("error");
			if (s[index] == '#')
				hash_count++;
		}
		index++;
	}
	if (hash_count != 4)
		ft_exit("error");
}

void	valid_tetri(unsigned short value)
{
	int		touch_count;
	int		i;

	touch_count = 0;
	i = 15;
	while (i >= 1)
	{
		if (value & (1 << i))
		{
			if((i - 4 >= 0) && (value & (1 << (i - 4))))
				touch_count++;
			if (i % 4 && (value & (1 << (i - 1))))
				touch_count++;
		}
		i--;
	}
	if (touch_count != 3 && touch_count != 4)
		ft_exit("error");
}

void  mv_left_top_calcu(tetri_list *list)
{
	int		length;
	int		height;

	length = 0;
	height = 0;
	while((0x7777 | list->tetri_value) == 0x7777)
	{
		list->tetri_value = list->tetri_value << 1;
		length++;
	}
	while((0X0FFF | list->tetri_value) == 0x0FFF)
	{
		list->tetri_value = list->tetri_value << 4;
		height++;
	}
	list->length = 4 - length;
	list->height = 4 - height;
}


tetri_list	*add_tetri(unsigned short value, int nb, tetri_list *old_list)
{
	tetri_list	*list;

	if(!(list = (tetri_list *)malloc(sizeof(*list))))
		return (NULL);
	list->tetri_value = value;
	list->letter = 'A' + nb;
	list->length = 0;
	list->height = 0;
	list->next = NULL;
	mv_left_top_calcu(list);
	if(!old_list)
		old_list = list;
	else 
		old_list->next = list;
	return (old_list);
}

tetri_list	*ft_readfile(char const *file_name)
{
	char				*buff;
	int				fd;
	unsigned	short	value_tetri;
	int				nb_tetri;
	tetri_list		*list;

	nb_tetri = 0;
	list = NULL;
	fd = open(file_name, O_RDONLY);
	if(fd == -1)
		ft_exit("error");
	if(!(buff = (char *)malloc(BUFF_SIZE)))
		return (NULL);
	while (read(fd, buff, BUFF_SIZE))
	{
		if (nb_tetri > 25)
			ft_exit("maxi tetri is 26");
		only_dot_hash(buff,BUFF_SIZE);
		value_tetri = tetri_value(buff, BUFF_SIZE);
		valid_tetri(value_tetri);
		list = add_tetri(value_tetri, nb_tetri, list);
		nb_tetri++;
	}
	return (list);
}

/*
   int	main(void)
   {
   char *s="....\n...#\n..##\n...#\n\n";
   only_dot_hash(s, 21);
   unsigned short t = tetri_value(s, 21);
   valid_tetri(t);
   int i = 15;
   while (i >= 0)
   {
   if (t & ( 1 << i))
   printf("1");
   else
   printf("0");
   i--;
   }
   printf("\n");
   t = mv_left_top(t);
   i = 15;
   while (i >= 0)
   {
   if (t & ( 1 << i))
   printf("1");
   else
   printf("0");
   i--;
   }
   }
   */
