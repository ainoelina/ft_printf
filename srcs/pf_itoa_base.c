/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_itoa_base.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/08 10:15:13 by avuorio       #+#    #+#                 */
/*   Updated: 2021/01/13 13:41:02 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** !!! find out why len starts at 1 and not 0
*/

size_t	ft_intlen_base(unsigned long long n, char *base)
{
	size_t				len;
	unsigned long long	baselen;

	len = 1;
	baselen = ft_strlen(base);
	while (n >= baselen)
	{
		n = n / baselen;
		len++;
	}
	return (len);
}

char	*itoa_base(unsigned long long n, char *base)
{
	char	*str;
	int		numlen;
	int		baselen;

	numlen = ft_intlen_base(n, base);
	baselen = ft_strlen(base);
	str = ft_calloc((numlen + 1), sizeof(char));
	if (!str)
		return (NULL);
	while (numlen)
	{
		numlen = numlen - 1;
		str[numlen] = base[n % baselen];
		n = n / baselen;
	}
	return (str);
}
