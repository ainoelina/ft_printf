/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/15 11:18:34 by avuorio       #+#    #+#                 */
/*   Updated: 2020/12/15 20:25:19 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putchar(char c)
{
	ft_putchar_fd(c, 1);
}

void	putnbr_i(int n, int *p)
{
	if (n == -2147483648)
	{
		ft_putchar('-');
		n = n % 1000000000;
		n = -n;
	}
	else if (n < 0)
	{
		*p = *p + 1;
		ft_putchar('-');
		n = -n;
	}
	else if (n > 9)
	{
		putnbr_i((n / 10), p);
		putnbr_i((n % 10), p);
	}
	else
	{
		*p = *p + 1;
		ft_putchar(n + 48);
	}
}

void	putnbr_ui(unsigned int n, int *p)
{
	if (n > 9)
	{
		putnbr_ui((n / 10), p);
		putnbr_ui((n % 10), p);
	}
	else
	{
		*p = *p + 1;
		ft_putchar(n + 48);
	}
}

void	puthex(unsigned int n, int *p)
{
	if (n > 15)
	{
		puthex((n / 16), p);
		puthex((n % 16), p);
	}
	else if (n < 10)
	{
		*p = *p + 1;
		ft_putchar(n + 48);
	}
	else
	{
		if (n == 10)
			ft_putchar('a');
		if (n == 11)
			ft_putchar('b');
		if (n == 12)
			ft_putchar('c');
		if (n == 13)
			ft_putchar('d');
		if (n == 14)
			ft_putchar('e');
		if (n == 15)
			ft_putchar('f');
	}
}

void	putuhex(unsigned int n, int *p)
{
	if (n > 15)
	{
		puthex((n / 16), p);
		puthex((n % 16), p);
	}
	else if (n < 10)
	{
		*p = *p + 1;
		ft_putchar(n + 48);
	}
	else
	{
		if (n == 10)
			ft_putchar('A');
		if (n == 11)
			ft_putchar('B');
		if (n == 12)
			ft_putchar('C');
		if (n == 13)
			ft_putchar('D');
		if (n == 14)
			ft_putchar('E');
		if (n == 15)
			ft_putchar('F');
	}
}

void	flags_unsigned_int(va_list arg, int *p)
{
	unsigned int output;

	output = va_arg(arg, unsigned int);
	putnbr_ui(output, p);
}

void	flags_int(va_list arg, int *p)
{
	int output;

	output = va_arg(arg, int);
	putnbr_i(output, p);
}

void	flags_hex(va_list arg, int *p)
{
	unsigned int	output;

	output = va_arg(arg, unsigned int);
	puthex(output, p);
}

void	flags_uhex(va_list arg, int *p)
{
	unsigned int	output;

	output = va_arg(arg, unsigned int);
	putuhex(output, p);
}

void	int_parse_flags(int *i, const char *str, va_list arg, int *p)
{
	*i = *i + 1;
	if (str[*i] == 'd' || str[*i] == 'i')
		flags_int(arg, p);
	if (str[*i] == 'u')
		flags_unsigned_int(arg, p);
	if (str[*i] == 'x')
		flags_hex(arg, p);
	if (str[*i] == 'X')
		flags_uhex(arg, p);
	else
		return ;
}

int		ft_printf(const char *str, ...)
{
	va_list	arg;
	int		i;
	int		p;

	i = 0;
	p = 0;
	va_start(arg, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
			int_parse_flags(&i, str, arg, &p);
		else
			write(1, &str[i], 1);
		i++;
	}
	va_end(arg);
	return (p);
}

int		main(void)
{
	int		i = 5;

	printf("this should be printed: %i\n", i);
	ft_printf("this should be printed: %i", i);
	printf("this should be printed: %i\n", i);
	ft_printf("this should be printed: %i", i);
	return (0);
}
