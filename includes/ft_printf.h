/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/07 11:40:56 by avuorio       #+#    #+#                 */
/*   Updated: 2021/01/18 10:42:13 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*
** ~~~~~~~~~ HEADERS ~~~
*/

# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

/*
** buffer size is defined here so there's no
** need to malloc for the struct
*/

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 64
# endif

/*
** ~~~~~~~~~ STRUCT ~~~
*/

typedef struct	s_data
{
	char				buffer[BUFFER_SIZE + 1];
	int					counter;
	int					ret;

	int					width;
	int					prec;
	int					prec_w;
	int					conversion;
	int					minus;
	int					zero;
	int					plus;
	int					space;
	int					hash;
	int					len;
	int					padding_len;
	int					index;
	int					is_int;

	long long			n;
	unsigned long long	u;
}				t_data;

/*
** ~~~~~~~~~ INITIALISING STRUCT ~~~
*/

void			flags_reset(t_data *s);
void			initialise_struct(t_data *s);

/*
** ~~~~~~~~~ PARSING FORMAT ~~~
*/

void			parse(char *format, va_list ap, t_data *s);

size_t			conversion_type(char c);
size_t			modifier_type(char c);

/*
** ~~~~~~~~~ HANDLING CONVERSION ~~~
*/

void			handle_conversion(char *format, va_list ap, t_data *s);

void			handle_char(va_list ap, t_data *s);
void			handle_string(va_list ap, t_data *s);
void			handle_pointer(va_list ap, t_data *s);
void			handle_hex(va_list ap, t_data *s);
void			handle_int(va_list ap, t_data *s);
void			handle_uint(va_list ap, t_data *s);

/*
** ~~~~~~~~~ HELPER FUNCTIONS ~~~
*/

void			set_precision(t_data *s);

char			*add_padding(t_data *s);
char			*char_to_str(char c);
char			*strdup_p(char *str, t_data *s);
char			*itoa_printf(long long n);
char			*itoa_base(unsigned long long n, char *base);
char			*uitoa_printf(unsigned long long n);
char			*prec_num(char *str, t_data *s);

int				atoi_printf(char *format, int *index);
int				integer_len(long long n);
int				uinteger_len(unsigned long long n);

/*
** ~~~~~~~~~ CREATE OUTPUT ~~~
*/

void			joiner(char *str, char *sp, t_data *s);
void			dump_buffer(t_data *s);
void			adding_to_buffer(t_data *s, char *str, int len);

/*
** ~~~~~~~~~ FT_PRINTF ~~~
*/

int				ft_printf(const char *format, ...);

#endif
