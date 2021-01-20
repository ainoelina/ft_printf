/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_format.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/07 11:55:37 by avuorio       #+#    #+#                 */
/*   Updated: 2021/01/18 13:56:58 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** function checks for different flags and
** in case of encounterinf one sets them to 1.
*/

void	check_more_flags(char *format, t_data *s)
{
	if (format[s->index] == '.')
		set_precision(s);
	if (format[s->index] == ' ')
		s->space = 1;
	if (format[s->index] == '+')
		s->plus = 1;
	if (format[s->index] == '#')
		s->hash = 1;
}

/*
** flags *, 0, width and minus are checked in this function.
** also if previously '.' precision flag has been encountered,
** precision width is being defined.
*/

void	check_flags(char *format, va_list ap, t_data *s)
{
	if (format[s->index] == '*')
	{
		if (s->prec)
			s->prec_w = va_arg(ap, int);
		else
			s->width = va_arg(ap, int);
	}
	if (format[s->index] == '0' && !s->minus && !s->prec)
		s->zero = 1;
	if (format[s->index] > '0' && format[s->index] <= '9' && !s->prec)
		s->width = atoi_printf(format, &s->index);
	if (format[s->index] >= '0' && format[s->index] <= '9' && s->prec)
		s->prec_w = atoi_printf(format, &s->index);
	if (format[s->index] == '-')
	{
		s->zero = 0;
		s->minus = 1;
	}
	check_more_flags(format, s);
}

/*
** processes the format string by checking if there are any flags
** and setting the struct flag variables to correct values.
** also deals with undefined behaviour by returning a zero.
*/

int		parse_further(char *format, va_list ap, t_data *s)
{
	while (!conversion_type(format[s->index]))
	{
		check_flags(format, ap, s);
		if (format[s->index + 1] == '\0')
			return (0);
		if (!modifier_type(format[s->index + 1]))
			return (0);
		s->index++;
	}
	return (1);
}

/*
** the first parse function resets the flags in case there was
** previous function call. after checking the flags in the other
** parse function, s->conversion is set to the conversion specifier
** at index, and conversion handler function is called.
*/

void	parse(char *format, va_list ap, t_data *s)
{
	s->index++;
	flags_reset(s);
	if (!parse_further(format, ap, s))
		return ;
	if (s->width < 0)
	{
		s->minus = 1;
		s->zero = 0;
		s->width = -s->width;
	}
	if (s->prec_w < 0)
		s->prec = 0;
	if (s->prec && s->prec_w >= 0)
		s->zero = 0;
	s->conversion = format[s->index];
	handle_conversion(format, ap, s);
}
