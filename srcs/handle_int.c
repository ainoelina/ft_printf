/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_int.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/08 10:52:11 by avuorio       #+#    #+#                 */
/*   Updated: 2021/01/13 13:43:05 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_int(va_list ap, t_data *s)
{
	char	*str;
	char	*padding;

	s->is_int = 1;
	s->n = (long long)va_arg(ap, int);
	str = itoa_printf(s->n);
	s->len = integer_len(s->n);
	str = prec_num(str, s);
	s->len = ft_strlen(str);
	if (s->n < 0)
		s->len++;
	if ((s->n >= 0) && (s->plus || s->space))
		s->len++;
	if (s->n == 0 && s->prec && s->prec_w == 0 && !s->width)
	{
		free(str);
		return ;
	}
	if (s->n == 0 && s->prec && s->prec_w == 0)
	{
		free(str);
		str = ft_strdup(" ");
	}
	padding = add_padding(s);
	joiner(str, padding, s);
}

void	handle_uint(va_list ap, t_data *s)
{
	char	*str;
	char	*padding;

	s->is_int = 1;
	s->u = (unsigned long long)va_arg(ap, unsigned int);
	str = uitoa_printf(s->u);
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
	padding = add_padding(s);
	joiner(str, padding, s);
}
