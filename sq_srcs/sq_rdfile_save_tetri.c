/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sq_rdfile_save_tetri.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saxiao <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 09:03:21 by saxiao            #+#    #+#             */
/*   Updated: 2017/11/17 12:32:42 by saxiao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "sq_fillit.h"
#include "../includes/libft.h"

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
			if (i % 4 && (value & (1 << (i - 4))))
				touch_count++;
		}
		i--;
	}
	if (touch_count != 3 && touch_count != 4)
		ft_exit("error");
}

unsigned	short mv_left_top(unsigned short t)
{
	while((0x7777 | t) == 0x7777)
		t = t << 1;
	while((0X0FFF | t) == 0x0FFF)
		t = t << 4;
	return (t);
}







/*ft_readfile(char const *file_name)
  {
  char				*buff;
  int					fd;
  unsigned	short	value_tetri;

  fd = open(file_name, O_RDONLY);
  if(fd == -1)
  ft_exit("error");
  if(!(buff = (char *)malloc(BUFF_SIZE)))
  return (NULL);
  while ( read(fd, buff, BUFF_SIZE))
  {

  only_dot_hash(buff,BUFF_SIZE);
  value_tetri = tetri_value(buff, BUFF_SIZE);
  valid_tetri(value_tetri);
  */
int	main(void)
{
	char *s="....\n....\n..##\n..##\n\n";
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
