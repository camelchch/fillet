/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_it.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:28:14 by fsabatie          #+#    #+#             */
/*   Updated: 2017/11/10 16:28:16 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILL_IT_H
# define FILL_IT_H
# include "libft.h"
# define BUFF_SIZE 21

typedef struct	s_etrimino
{
	short int	c_tet;
	short int	width;
	short int	height;
}				t_etrimino;

t_list			*ft_read_entry(const char *filename);
void			ft_printbytetetri(short int c);
t_etrimino		*ft_newtetri(char *tet);

#endif
