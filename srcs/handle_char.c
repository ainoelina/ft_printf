/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_char.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/07 14:32:06 by avuorio       #+#    #+#                 */
/*   Updated: 2021/01/14 11:35:02 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_char(va_list ap, t_data *s)
{
	char	*str;
	char	*padding;

	str = NULL;
	s->len = 1;
	if (s->conversion == 'c')
		str = char_to_str(va_arg(ap, int));
	if (s->conversion == '%')
		str = char_to_str('%');
	padding = add_padding(s);
	joiner(str, padding, s);
}

void	handle_string(va_list ap, t_data *s)
{
	char	*str;
	char	*padding;

	if (s->prec && s->prec_w < 0)
		s->prec_w = -s->prec_w;
	str = va_arg(ap, char *);
	if (!str)
		str = strdup_p("(null)", s);
	else
		str = strdup_p(str, s);
	s->len = ft_strlen(str);
	padding = add_padding(s);
	joiner(str, padding, s);
}

void	handle_pointer(va_list ap, t_data *s)
{
	char	*str;
	char	*padding;

	s->u = va_arg(ap, long unsigned);
	str = itoa_base(s->u, "0123456789abcdef");
	if (s->prec)
		s->zero = 0;
	s->len = ft_strlen(str);
	str = prec_num(str, s);
	s->len = ft_strlen(str) + 2;
	if (s->u == 0 && s->prec && s->prec_w == 0)
	{
		free(str);
		str = ft_strdup("");
		s->len = s->len - 1;
	}
	padding = add_padding(s);
	joiner(str, padding, s);
}

char	*define_hex_base(t_data *s)
{
	char	*str;

	if (s->conversion == 'x')
	{
		str = itoa_base(s->u, "0123456789abcdef");
		return (str);
	}
	if (s->conversion == 'X')
	{
		str = itoa_base(s->u, "0123456789ABCDEF");
		return (str);
	}
	else
		return (0);
}

void	handle_hex(va_list ap, t_data *s)
{
	char	*str;
	char	*padding;

	str = NULL;
	s->is_int = 1;
	s->u = (unsigned long long)va_arg(ap, unsigned int);
	str = define_hex_base(s);
	s->len = ft_strlen(str);
	str = prec_num(str, s);
	s->len = ft_strlen(str);
	if (s->u == 0 && s->prec && s->prec_w == 0 && !s->width)
	{
		free(str);
		return ;
	}
	if (s->u == 0 && s->prec && s->prec_w == 0)
	{
		free(str);
		str = ft_strdup(" ");
	}
	if (s->hash && s->u)
		s->len = s->len + 2;
	padding = add_padding(s);
	joiner(str, padding, s);
}
