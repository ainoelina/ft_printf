/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_process_output.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/13 13:52:22 by avuorio       #+#    #+#                 */
/*   Updated: 2021/01/13 13:54:10 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** adds padding of zeroes or spaces
** based on modifier.
*/

char	*add_padding(t_data *s)
{
	char	*str;
	int		i;

	i = 0;
	if (s->width < s->len)
		return (NULL);
	str = ft_calloc((s->width - s->len + 1), sizeof(char));
	if (!str)
		return (NULL);
	if (s->prec && s->prec_w > s->len)
		s->zero = 0;
	while (i < s->width - s->len)
	{
		if (s->zero)
			str[i] = '0';
		else
			str[i] = ' ';
		i++;
	}
	s->padding_len = i;
	return (str);
}

/*
** adds zeroes to string based on the precision modifier
*/

char	*prec_num(char *str, t_data *s)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s->prec || s->prec_w < s->len)
		return (str);
	temp = ft_calloc(s->prec_w + s->len + 1, sizeof(char));
	if (!temp)
		return (NULL);
	while (i < s->prec_w - s->len)
	{
		temp[i] = '0';
		i++;
	}
	while (str[j])
	{
		temp[i + j] = str[j];
		j++;
	}
	free(str);
	return (temp);
}
