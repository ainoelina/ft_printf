/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/07 11:40:09 by avuorio       #+#    #+#                 */
/*   Updated: 2021/01/18 13:55:55 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** dump_buffer function writes what has been processed
** in case of exceeding the buffer_size or end of format
** string and then sets counter to 0.
*/

void	dump_buffer(t_data *s)
{
	write(1, s->buffer, s->counter);
	s->counter = 0;
}

/*
** adds the processed part to buffer
*/

void	adding_to_buffer(t_data *s, char *str, int len)
{
	int i;

	i = 0;
	s->ret = s->ret + len;
	while (i < len)
	{
		s->buffer[s->counter] = str[i];
		s->counter++;
		if (s->counter == BUFFER_SIZE)
			dump_buffer(s);
		i++;
	}
}

/*
** the printing function processes the other parts that are
** not defined by a format specifier of any kind. if buffer size
** is exceeded the processed part is printed and counter reset.
*/

void	printing(t_data *s, char *format)
{
	int	p;

	p = 0;
	while (format[s->index] && format[s->index] != '%')
	{
		s->buffer[s->counter] = format[s->index];
		s->counter++;
		p++;
		if (s->counter == BUFFER_SIZE)
			dump_buffer(s);
		s->index++;
	}
	s->ret = s->ret + p;
	s->index--;
}

/*
** the ft_printf initialises the struct to zero, and takes the format
** as the start of the variadic argument.
** it loops through the format string and if it detects '%' if either breaks
** or checks if the next character is a type of flag or conversion specifier.
** if this is true, it calls the parser function with the format string,
** ap and struct. If '%' character is not encountered, 'printing'
** function is called, that saves the characters to struct.buffer.
** when exiting the loop, va_end is called and the buffer is written
** and counter reset. ft_printf returns the struct.ret whic is the total
** number of characters printed.
*/

int		ft_printf(const char *format, ...)
{
	t_data	s;
	va_list	ap;

	initialise_struct(&s);
	va_start(ap, format);
	while (format[s.index])
	{
		if (format[s.index] == '%')
		{
			if (format[s.index + 1] == '\0')
				break ;
			if (modifier_type(format[s.index + 1]))
				parse((char *)format, ap, &s);
		}
		else
			printing(&s, (char *)format);
		s.index++;
	}
	va_end(ap);
	dump_buffer(&s);
	return (s.ret);
}
