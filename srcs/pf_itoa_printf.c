/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_itoa_printf.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/08 11:05:29 by avuorio       #+#    #+#                 */
/*   Updated: 2021/01/13 13:35:45 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		uinteger_len(unsigned long long n)
{
	size_t	len;

	len = 1;
	while (n >= 10)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

int		integer_len(long long n)
{
	size_t	len;

	len = 0;
	if (!n)
		len++;
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*itoa_printf(long long n)
{
	char	*str;
	size_t	intlen;

	intlen = integer_len(n);
	str = ft_calloc((intlen + 1), sizeof(char));
	if (!str)
		return (NULL);
	while (intlen)
	{
		if (n < 0)
		{
			intlen = intlen - 1;
			str[intlen] = -(n % 10) + 48;
			n = n / 10;
			n = -n;
		}
		else
		{
			intlen = intlen - 1;
			str[intlen] = n % 10 + 48;
			n = n / 10;
		}
	}
	return (str);
}

char	*uitoa_printf(unsigned long long n)
{
	char	*str;
	size_t	uintlen;

	uintlen = uinteger_len(n);
	str = ft_calloc((uintlen + 1), sizeof(char));
	if (!str)
		return (NULL);
	while (uintlen)
	{
		uintlen = uintlen - 1;
		str[uintlen] = n % 10 + 48;
		n = n / 10;
	}
	return (str);
}
