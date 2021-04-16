/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 13:43:13 by mhadad            #+#    #+#             */
/*   Updated: 2021/04/16 15:51:52 by mhadad           ###   ########.fr       */
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
	data->width = 0;
	data->max_print = 0;
	data->dot = 0;
	data->arg = 0;
	data->x_up = 0;
}


/*
**
**   index | flag | func
**   ------|------|------
**   [0]   | `c`  | arg_c
**   [1]   | `s`  | arg_s
**   [2]   | `p`  | arg_p
**   [3]   | `d`  | arg_d
**   [4]   | `i`  | arg_d
**   [5]   | `u`  | arg_u
**   [6]   | `x`  | arg_x
**   [7]   | `X`  | arg_x_up
**   [8]   | `%`  | dummy_arg
**
**   Return | Value
**   -------|------
**   TRUE   |  1
**   FALSE  |  0
*    ERR    | -1
**
*/

int	arg_check(const char *str, t_data *d, va_list *args)
{
	static t_func_arr	f[ARG_FUNC] = {
		arg_c,
		arg_s,
		arg_p,
		arg_d,
		arg_d,
		arg_u,
		arg_x,
		arg_x_up,
		dummy_arg
	};
	char				*list;
	int					index;

#ifdef DEBUG_TRUE
BM("arg_check");
#endif

	index = 0;
	list = "cspdiuxX%";
	while (list && list[index] && list[index] != str[d->skip])
		index++;

#ifdef DEBUG_TRUE
data_debug(&(*d));
D_STR(&(list[index]))
D_INT(index)
BR;
#endif

	if (list[index] == str[d->skip])
		if ((f[index](NULL, &(*d), &(*args))) == ERR)
			return (ERR);
	return (TRUE);
}

/*
**
**   Flag `-0.*`
**   index | flag | func
**   ------|------|------
**   [0]   | `-`  | flag_min
**   [1]   | `0`  | dummy_arg
**   [2]   | `.`  | dummy_arg
**   [3]   | `*`  | dummy_arg
**
**   Return | Value
**   -------|------
**   TRUE   |  1
**   FALSE  |  0
*/

int	flag_check(const char *str, t_data *data, va_list *args)
{
	int					index;
	int					ret;
	char				*list;
	static t_func_arr	f[FLAG_FUNC] = {
		flag_min,
		flag_zero,
		flag_dot,
		flag_arg,
		dummy_flag
	};

#ifdef DEBUG_TRUE
BM("Flag_check");
D_STR_DETAILS(&str[data->skip]);
BR;
#endif

	index = 0;
	ret = 0;
	list = "-0.*";
	while (str && str[data->skip])
	{
		if (str[data->skip] >= '1' && str[data->skip] <= '9')
		{
			data->width = chartoi(&str[data->skip], &(*data));
		}
		else
		{
			while (list[index] && str[data->skip] != list[index])
			{
#ifdef DEBUG_TRUE
				BM("check");
				D_STR(&list[index]);
				D_INT(index)
#endif
				index++;
			}
			ret = f[index](str, &(*data), &(*args));
			if (ret == ERR)
				return (FALSE);
			if (!ret)
				break;
			index = 0;
		}
	}

#ifdef DEBUG_TRUE
data_debug(&(*data));
BR;
#endif
	return (arg_check(str, &(*data), &(*args)));
}

/*
**   Flag `-0.*`
*/

int	parser(const char *str, t_data *data, va_list *args)
{
	if (!str[++data->skip])
		return (FALSE);
	data_init(&(*data));
#ifdef DEBUG_TRUE
BM("str++ ok");
D_STR_DETAILS(&str[data->skip]);
data_debug(&(*data));
#endif
	if (str[data->skip] == '%')
		ft_putchar(str[data->skip++], &(*data));
	else
		if (!flag_check(str, &(*data), &(*args)))
			return(FALSE);
	return (TRUE);
}
