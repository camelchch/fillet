/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_it.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 13:02:07 by fsabatie          #+#    #+#             */
/*   Updated: 2017/11/11 13:02:09 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fill_it.h"
#include "libft.h"

int	main(int argc, char const *argv[])
{
	t_list *tetrimino;

	if (argc != 2)
		return (ft_putendl_ret("usage: ./fillit [filename]"));
	tetrimino = ft_read_entry(argv[1]);
	while (tetrimino->next)
	{
		ft_printbytetetri(((t_etrimino*)(tetrimino->content))->c_tet);
		tetrimino = tetrimino->next;
		ft_putchar('\n');
	}
	return (0);
}
