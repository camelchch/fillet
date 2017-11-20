/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sq_fillit.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saxiao <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 08:58:43 by saxiao            #+#    #+#             */
/*   Updated: 2017/11/20 11:30:42 by saxiao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FILLIT_H
#define	FILLIT_H

#define	BUFF_SIZE 21

typedef	struct	s_list
{
	unsigned short	tetri_value;
	char			letter;
	int				length;
	int				height;
	struct	s_list	*next;
}				tetri_list;

void	ft_exit(const char *s);
tetri_list	*ft_readfile(char const *file_name);

#endif
