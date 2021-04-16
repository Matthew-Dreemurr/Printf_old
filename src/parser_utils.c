/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 15:28:19 by mhadad            #+#    #+#             */
/*   Updated: 2021/04/07 11:59:53 by mhadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

/*
**  `%-` | `min`  | Left align the result within the given field width
**  `%0` | `zero` | Shorter numbers are padded out with leading zeros
**  `%.` | `dot` | How many placesshould be shown after the decimal point
**  `%*` | `arg`  | an int width argument must precede the value that's being
**                   formatted in the argument list, exemple 
**                   `printf("%0*d", 5, 3); ` 00003 is output`
*/

void	data_init(t_data *data)
{
	data->minus = 0;
	data->zero = 0;
	data->dot = 0;
	data->arg = 0;
	data->skip = 0;
	data->width = 0;
	data->x_up = 0;
}

/*
**
*/

int	dummy_arg(t_data *data, va_list *args)
{
	(void)data;
	(void)args;
#ifdef DEBUG_TRUE
	BR;
#endif
	return (TRUE);
}

/*
**
*/

int	dummy_flag(const char *str, t_data *data, va_list *args)
{
	(void)str;
	(void)data;
	(void)args;
#ifdef DEBUG_TRUE
	BR;
#endif
	return (TRUE);
}

/*
**
*/

int		flag_min(const char *str, t_data *data, va_list *args)
{
	(void)str;
	data->skip++;
	(void)args;
#ifdef DEBUG_TRUE
	BR;
#endif
	return (TRUE);
}

/*
**
*/

int		flag_zero(const char *str, t_data *data, va_list *args)
{
	(void)str;
	data->skip++;
	(void)args;
#ifdef DEBUG_TRUE
	BR;
#endif
	return (TRUE);
}

/*
**
*/

int		flag_dot(const char *str, t_data *data, va_list *args)
{
	(void)str;
	data->skip++;
	(void)args;
#ifdef DEBUG_TRUE
	BR;
#endif
	return (TRUE);
}

/*
**
*/

int		flag_arg(const char *str, t_data *data, va_list *args)
{
	(void)str;
	data->skip++;
	(void)args;
#ifdef DEBUG_TRUE
	BR;
#endif
	return (TRUE);
}