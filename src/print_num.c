/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 18:12:36 by mhadad            #+#    #+#             */
/*   Updated: 2021/04/22 13:07:47 by mhadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

/*
** //XXX Malloc !
*/

int	print_uint(unsigned int nbr, t_data *data)
{
	int		i;
	char	*str;

	i = 0;
	str = malloc(len_uint(nbr) + 1);
	if (!str)
		return (FALSE);
	while (nbr > 0)
	{
		str[i] = (nbr % 10) + '0';
		nbr /= 10;
		i++;
	}
	str[i] = '\0';
	putstr_rev(str, &(*data));
	free (str);
	return (TRUE);
}
