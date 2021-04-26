/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_alpha_manager.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 12:10:44 by mhadad            #+#    #+#             */
/*   Updated: 2021/04/22 12:10:53 by mhadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

/*
**   .
*/

void	print_arg_s(const char *str, t_data *data)
{
	size_t	len;

	len = len_str(str);
	if (data->dot && len > data->prec)
		len = data->prec;
	if (!data->minus && data->fill)
		min_fill(len, data->fill, &(*data));
	ft_putstr(str, &(*data));
	if (data->minus && data->fill)
		min_fill(len, data->fill, &(*data));
}

/*
**   .
*/

void	print_arg_c(const char c, t_data *data)
{
	data->dot = FALSE;
	data->prec = FALSE;
	if (!data->minus && data->fill)
		min_fill(1, data->fill, &(*data));
	ft_putchar(c, &(*data));
	if (data->minus && data->fill)
		min_fill(1, data->fill, &(*data));
}