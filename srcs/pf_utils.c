/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_utils.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/08 11:51:53 by avuorio       #+#    #+#                 */
/*   Updated: 2021/01/18 13:57:25 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	initialise_struct(t_data *s)
{
	s->counter = 0;
	s->ret = 0;
	s->width = 0;
	s->prec = 0;
	s->prec_w = 0;
	s->conversion = 0;
	s->minus = 0;
	s->zero = 0;
	s->plus = 0;
	s->hash = 0;
	s->space = 0;
	s->padding_len = 0;
	s->is_int = 0;
	s->n = 0;
	s->u = 0;
	s->len = 0;
	s->index = 0;
}

void	set_precision(t_data *s)
{
	s->prec = 1;
	s->prec_w = 0;
}

void	flags_reset(t_data *s)
{
	s->width = 0;
	s->prec = 0;
	s->prec_w = 0;
	s->conversion = 0;
	s->minus = 0;
	s->zero = 0;
	s->plus = 0;
	s->space = 0;
	s->hash = 0;
	s->len = 0;
	s->padding_len = 0;
	s->is_int = 0;
	s->n = 0;
	s->u = 0;
}

size_t	conversion_type(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' ||
			c == 'u' || c == 'x' || c == 'X' || c == '%');
}

size_t	modifier_type(char c)
{
	return (conversion_type(c) || (c >= '0' && c <= '9') || c == '-' ||
			c == '.' || c == '*' || c == ' ' || c == '+' || c == '#');
}
