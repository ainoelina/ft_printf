/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   testmain.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/17 11:39:36 by avuorio       #+#    #+#                 */
/*   Updated: 2021/01/14 14:00:14 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	int				i;
	unsigned int	u;
	char			c;
	char			*ptr;
	char			*str;

	i = 42;
	u = 156;
	c = 'a';
	ptr = malloc(sizeof(char));
	str = "THIS SHOULD BE PRINTED :)";
	printf("\033[01;35m");
	printf("\nSIMPLE CONVERSIONS\n");
	printf("\033[m");
	printf("\033[38;5;48m");
	printf("\n(~~ integer i) built-in printf: %i\n", i);
	ft_printf("(~~ integer i) ft_printf: %i", i);
	printf("\033[m");
	printf("\033[38;5;50m");
	printf("\n\n(~~ integer d) built-in printf: %d\n", i);
	ft_printf("(~~ integer d) ft_printf: %d", i);
	printf("\033[m");
	printf("\033[38;5;136m");
	printf("\n\n(~~ unsigned integer u) built-in printf: %u\n", u);
	ft_printf("(~~ unsigned integer u) ft_printf: %u", u);
	printf("\033[01;0m");
	printf("\033[38;5;138m");
	printf("\n\n(~~ pointer p) built-in printf: %p\n", ptr);
	ft_printf("(~~ pointer p) ft_printf: %p", ptr);
	printf("\033[01;0m");
	printf("\033[38;5;128m");
	printf("\n\n(~~ hexadecimal x) built-in printf: %x\n", 4779);
	ft_printf("(~~ hexadecimal x) ft_printf: %x", 4779);
	printf("\033[01;0m");
	printf("\033[38;5;125m");
	printf("\n\n(~~ hexadecimal X) built-in printf: %X\n", 4779);
	ft_printf("(~~ hexadecimal X) ft_printf: %X", 4779);
	printf("\033[01;0m");
	printf("\033[38;5;130m");
	printf("\n\n(~~ character c) built-in printf: %c\n", c);
	ft_printf("(~~ character c) ft_printf: %c", c);
	printf("\033[01;0m");
	printf("\033[38;5;132m");
	printf("\n\n(~~ character %%) built-in printf: %%\n");
	ft_printf("(~~ character %%) ft_printf: %%");
	printf("\033[01;0m");
	printf("\033[38;5;178m");
	printf("\n\n(~~ string s) built-in printf: %s\n", str);
	ft_printf("(~~ string s) ft_printf: %s", str);
	printf("\033[01;0m");
	printf("\033[01;34m");
	printf("\n\nPRECISION");
	printf("\033[m");
	printf("\033[38;5;150m");
	printf("\n\n(~~ case %%.5s for string 'abcdefg') built-in printf: %.5s\n", "abcdefg");
	ft_printf("(~~ case %%.5s for string 'abcdefg') ft_printf: %.5s\n", "abcdefg");
	printf("\033[01;0m");
	printf("\033[38;5;154m");
	printf("\n\n(~~ case %%.3d for integer 42) built-in printf: %.3d\n", i);
	ft_printf("(~~ case %%.3d for integer 42) ft_printf: %.3d\n", i);
	printf("\033[01;0m");
	printf("\033[38;5;160m");
	printf("\n\n(~~ special case %%.0d) built-in printf: %.0d\n", 0);
	ft_printf("(~~ special case %%.0d) ft_printf: %.0d\n", 0);
	printf("\033[01;0m");
	printf("\033[01;93m");
	printf("\nWIDTH AND MINUS");
	printf("\033[m");
	printf("\033[38;5;150m");
	printf("\n\n(~~ case %%5s for string 'abc') built-in printf: %5s\n", "abc");
	ft_printf("(~~ case %%5s for string 'abc') ft_printf: %5s\n", "abc");
	printf("\033[01;0m");
	printf("\033[38;5;62m");
	printf("\n\n(~~ case %%20s for string 'testing width') built-in printf: %20s\n", "testing width");
	ft_printf("(~~ case %%20s for string 'testing width') ft_printf: %20s\n", "testing width");
	printf("\033[01;0m");
	printf("\033[38;5;68m");
	printf("\n\n(~~ case %%-20s for string 'testing width') built-in printf: %-20s\n", "testing width");
	ft_printf("(~~ case %%-20s for string 'testing width') ft_printf: %-20s\n", "testing width");
	printf("\033[01;0m");
	printf("\033[38;5;70m");
	printf("\n\n(~~ case %%20.5s for string 'testing width') built-in printf: %20.5s\n", "testing width");
	ft_printf("(~~ case %%20.5s for string 'testing width') ft_printf: %20.5s\n", "testing width");
	printf("\033[01;0m");
	printf("\033[38;5;74m");
	printf("\n\n(~~ case %%-20.5s for string 'testing width') built-in printf: %-20.5s\n", "testing width");
	ft_printf("(~~ case %%-20.5s for string 'testing width') ft_printf: %-20.5s\n", "testing width");
	printf("\033[01;0m");
	printf("\033[01;95m");
	printf("\nZERO FLAG");
	printf("\033[m");
	printf("\033[38;5;202m");
	printf("\n\n(~~ case %%05d for integer 42) built-in printf: %05d\n", i);
	ft_printf("(~~ case %%05d for integer 42) ft_printf: %05d\n", i);
	printf("\033[01;0m");
	printf("\033[38;5;204m");
	printf("\n(~~ case %%05d for integer -6) built-in printf: %05d\n", -6);
	ft_printf("(~~ case %%05d for integer -6) ft_printf: %05d\n", -6);
	printf("\033[01;0m");
	printf("\033[38;5;206m");
	printf("\n(~~ case %%08d for integer -12345678) built-in printf: %08d\n", -12345678);
	ft_printf("(~~ case %%08d for integer -12345678) ft_printf: %08d\n", -12345678);
	printf("\033[01;0m");
	printf("\033[01;94m");
	printf("\nPLUS FLAG");
	printf("\033[m");
	printf("\033[38;5;27m");
	printf("\n\n(~~ case %%+05d for integer 0) built-in printf: %+05d\n", 0);
	ft_printf("(~~ case %%+05d for integer 0) ft_printf: %+05d\n", 0);
	printf("\033[01;0m");
	printf("\033[38;5;30m");
	printf("\n(~~ case %%+05d for integer -7) built-in printf: %+05d\n", -7);
	ft_printf("(~~ case %%+05d for integer -7) ft_printf: %+05d\n", -7);
	printf("\033[01;0m");
	printf("\033[38;5;32m");
	printf("\n(~~ case %%+05d for integer -12345678) built-in printf: %+05d\n", 1560133635);
	ft_printf("(~~ case %%+05d for integer -12345678) ft_printf: %+05d\n", 1560133635);
	printf("\033[01;0m");
	printf("\033[01;92m");
	printf("\nSPACE FLAG");
	printf("\033[m");
	printf("\033[38;5;70m");
	printf("\n\n(~~ case %% -5d for integer 0) built-in printf: % -5d\n", 0);
	ft_printf("(~~ case %% -5d for integer 0) ft_printf: % -5d\n", 0);
	printf("\033[01;0m");
	printf("\033[38;5;72m");
	printf("\n(~~ case %% -5d for integer -7) built-in printf: % -5d\n", -7);
	ft_printf("(~~ case %% -5d for integer -7) ft_printf: % -5d\n", -7);
	printf("\033[01;0m");
	printf("\033[38;5;74m");
	printf("\n(~~ case %% -5d for integer -12345678) built-in printf: % -5d\n", 1560133635);
	ft_printf("(~~ case %% -5d for integer -12345678) ft_printf: % -5d\n", 1560133635);
	printf("\033[01;0m");
	printf("\033[01;31m");
	printf("\nASTERISK");
	printf("\033[m");
	printf("\033[38;5;197m");
	printf("\n\n(~~ case %%*d for integer 10) built-in printf: %*d\n", 5, 10);
	ft_printf("(~~ case %%*d for integer 10) ft_printf: %*d\n", 5, 10);
	printf("\033[01;0m");
	printf("\033[38;5;162m");
	printf("\n(~~ case %%.*s for string 'abcdef') built-in printf: %.*s\n", 3, "abcdef");
	ft_printf("(~~ case %%.*s for string 'abcdef') ft_printf: %.*s\n", 3, "abcdef");
	printf("\033[01;0m");
	printf("\033[01;36m");
	printf("\nHASH");
	printf("\033[m");
	printf("\033[38;5;111m");
	printf("\n\n(~~ case %%#x for integer 12) built-in printf: %#x\n", 12);
	ft_printf("(~~ case %%#x for integer 12) ft_printf: %#x\n", 12);
	printf("\033[01;0m");
	printf("\033[38;5;104m");
	printf("\n(~~ case %%#X for integer 16) built-in printf: %#X\n", 16);
	ft_printf("(~~ case %%#X for integer 16) ft_printf: %#X\n", 16);
	printf("\033[01;0m");
	printf("\033[01;93m");
	printf("\nEDGE CASES");
	printf("\033[m");
	printf("\033[38;5;226m");
	printf("\n\n(~~ case %%.i for integer 12) built-in printf: %.i\n", 12);
	ft_printf("(~~ case %%.i for integer 12) ft_printf: %.i\n", 12);
	printf("\033[01;0m");
	printf("\033[38;5;214m");
	printf("\n(~~ case %%s for empty string) built-in printf: %s\n", "");
	ft_printf("(~~ case %%s for empty string) ft_printf: %s\n", "");
	printf("\033[01;0m");
	printf("\033[38;5;229m");
	printf("\n(~~ case s for NULL string) built-in printf: %s\n", NULL);
	ft_printf("(~~ case s for NULL string) ft_printf: %s\n", NULL);
	printf("\033[01;0m");
	printf("\033[38;5;229m");
	printf("\n(~~ case hex for 0 with precision) built-in printf: %.x\n", 0);
	ft_printf("(~~ case hex for 0 with precision) ft_printf: %.x\n", 0);
	printf("\033[01;0m");
	printf("\n(~~ case for no conversion specifier, undefined behaviour) built-in printf: %.5apina\n", 3);
	ft_printf("(~~ case for no conversion specifier, undefined behaviour) ft_printf: %.5apina\n", 3);
	printf("\033[01;0m");
	return (0);
}
