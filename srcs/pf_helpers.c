/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_helpers.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/07 13:56:00 by avuorio       #+#    #+#                 */
/*   Updated: 2021/01/14 11:36:55 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** converts single character to string.
*/

char	*char_to_str(char c)
{
	char	*s;

	s = ft_calloc(2, sizeof(char));
	s[0] = c;
	return (s);
}

void	add_prefix(t_data *s)
{
	if (s->conversion == 'x')
	{
		adding_to_buffer(s, "0x", 2);
		s->len = s->len - 2;
	}
	if (s->conversion == 'X')
	{
		adding_to_buffer(s, "0X", 2);
		s->len = s->len - 2;
	}
}

void	add_sign(t_data *s)
{
	if (s->n < 0)
	{
		s->len--;
		adding_to_buffer(s, "-", 1);
	}
	else if (s->plus && (s->n >= 0))
	{
		s->len--;
		adding_to_buffer(s, "+", 1);
	}
	else if (s->space && !s->plus && (s->n >= 0))
	{
		s->len--;
		adding_to_buffer(s, " ", 1);
	}
}

/*
** joiner function creates the output to add to buffer.
** also adds signs and prefix if needed.
*/

void	joiner(char *str, char *padding, t_data *s)
{
	if (s->is_int && s->zero)
		add_sign(s);
	if (s->zero && s->conversion == 'p')
	{
		adding_to_buffer(s, "0x", 2);
		s->len = s->len - 2;
	}
	if (s->hash && s->u && s->zero && s->prec_w < s->len)
		add_prefix(s);
	if (padding && !s->minus)
		adding_to_buffer(s, padding, s->padding_len);
	if (!s->zero && s->conversion == 'p')
	{
		adding_to_buffer(s, "0x", 2);
		s->len = s->len - 2;
	}
	if (s->hash && s->u && !s->zero && s->prec_w < s->len)
		add_prefix(s);
	if (s->is_int && !s->zero)
		add_sign(s);
	adding_to_buffer(s, str, s->len);
	if (padding && s->minus)
		adding_to_buffer(s, padding, s->padding_len);
	free(str);
	free(padding);
}

/*
** modified strdup checks adds a check for the use of
** precision flag for a string conversion.
*/

char	*strdup_p(char *str, t_data *s)
{
	char	*ptr;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(str);
	if (s->prec && s->prec_w < len)
		len = s->prec_w;
	ptr = ft_calloc(len + 1, sizeof(char));
	if (!ptr)
		return (NULL);
	while (i < len)
	{
		ptr[i] = str[i];
		i++;
	}
	return (ptr);
}
