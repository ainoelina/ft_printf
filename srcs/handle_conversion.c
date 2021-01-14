/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_conversion.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/07 14:26:21 by avuorio       #+#    #+#                 */
/*   Updated: 2021/01/07 14:29:34 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_conversion(char *format, va_list ap, t_data *s)
{
	if (format[s->index] == 'c')
		handle_char(ap, s);
	if (format[s->index] == 's')
		handle_string(ap, s);
	if (format[s->index] == 'p')
		handle_pointer(ap, s);
	if (format[s->index] == 'd' || format[s->index] == 'i')
		handle_int(ap, s);
	if (format[s->index] == 'u')
		handle_uint(ap, s);
	if (format[s->index] == 'x' || format[s->index] == 'X')
		handle_hex(ap, s);
	if (format[s->index] == '%')
		handle_char(ap, s);
}
