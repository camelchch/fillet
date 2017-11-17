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

#include <stdlib.h>
#include "sq_fillit.h"

void	ft_exit(char const *s)
{
	ft_putendl(s);
	exit(1);
}

short	int
void	only_dot_hash(char *s, BUFF_SIZE)
{
	int		hash_count;
	int		index;

	hash_count = 0;
	index = 0;
	while (index < BUFF_SIZE)
	{
		if ((!((index + 1) % 5) || index == BUFF_SIZE -1))
		{
			if (tetri[index] != '\n')
				ft_exit("error");
		}
		else
		{
			if (tetri[index] != '.' || tetri[index] != '#')
				ft_exit("error");
			if (tetri[index] == '#')
				hash_count++;
		}
	}
	if (hash_count != 4)
		ft_exit("error");
}

void	valid_tetri(char *s)
{
	int		touch_count;

ft_readfile(char const *file_name)
{
	char	*buff;
	int		fd;

	fd = open(file_name, O_RDONLY);
	if(fd == -1)
		ft_exit("error");
	if(!(buff = (char *)malloc(BUFF_SIZE)))
		return (NULL);
	while ( read(fd, buff, BUFF_SIZE))
	{

		only_dot_hash(buff);


