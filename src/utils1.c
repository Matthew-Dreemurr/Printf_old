/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 13:43:13 by mhadad            #+#    #+#             */
/*   Updated: 2021/03/18 15:40:46 by mhadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

/*
**
*/

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

/*
**
*/

int	check_arg(const char *str, t_data *data)
{
	BR;
	
	return (TRUE);
}

/*
**
*/

void	data_init(t_data *data)
{
	BR;
	data->ret = 0;
}