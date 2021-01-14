/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_atoi_printf.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/07 13:30:10 by avuorio       #+#    #+#                 */
/*   Updated: 2021/01/14 11:41:19 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** modified atoi to convert the ascii character to integer
** by passing in the format string and pointer to the index.
** index is decreased once after the loop to acquire the position
** of last character that was converted.
*/

int		atoi_printf(char *format, int *index)
{
	int	atoi;

	atoi = 0;
	while (format[*index] >= '0' && format[*index] <= '9')
	{
		atoi = atoi * 10 + format[*index] - 48;
		(*index)++;
	}
	(*index)--;
	return (atoi);
}
