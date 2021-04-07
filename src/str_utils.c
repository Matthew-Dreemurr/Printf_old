/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 15:16:18 by mhadad            #+#    #+#             */
/*   Updated: 2021/04/07 11:59:54 by mhadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

/*
**
*/

size_t	len_str(const char *str)
{
	int	i;

	i = -1;
	if(!str && !*str)
		return (0);
	while (str[++i])
		;
	return (i);
}

/*
**
*/

int	len_int(int nbr)
{
	int		len;
	long	nbr_c;

	len = 0;
	if (nbr < 0)
	{
		nbr_c = nbr * -1;
		len++;
	}
	else
		nbr_c = nbr;
	if (nbr_c == 0)
		return (0);
	while (nbr_c > 0)
	{
		nbr_c /= 10;
		len ++;
	}
	return (len);
}

/*
**
*/

int	len_uint(unsigned int nbr)
{
	int		len;

	len = 0;
	if (nbr == 0)
		return (0);
	while (nbr > 0)
	{
		nbr /= 10;
		len ++;
	}
	return (len);
}

/*
**
*/

int	width(const char *str, t_data *data)
{
	long	len;
	int		i;

	if (!str)
		return (ERR);
	i = 0;
	len = 0;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		len *= 10;
		len += (str[i] - '0');
		i++;
	}
	if (len > MAX_INT)
		return (ERR);
	data->width = len;
	data->skip += len_int(len);
	return (TRUE);
}

/*
**
*/

char*	ulongtohex(unsigned long nbr, t_data *data)
{
	char			*index[2];
	char			*ret;
	int				i;

	i = 0;
	index[0] = "0123456789abcdef";
	index[1] = "0123456789ABCDEF";
	ret = (char *)malloc(32);
	if (!ret)
		return (NULL);
	while (nbr > 0)
	{
		ret[i] = index[data->x_up][nbr % 16];
		nbr /= 16;
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
