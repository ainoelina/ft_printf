/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/15 15:54:22 by avuorio       #+#    #+#                 */
/*   Updated: 2020/12/15 18:49:48 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*
** ~~~~~ HEADERS ~~~
*/

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

//#include "libft.h"

typedef struct	s_print
{
	int		flags;
	char	c;
	char	*buffer;
	va_list	arg;
}				t_print;

#endif
