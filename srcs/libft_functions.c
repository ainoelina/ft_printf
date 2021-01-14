/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft_functions.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: avuorio <avuorio@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/11 10:13:50 by avuorio       #+#    #+#                 */
/*   Updated: 2021/01/11 10:14:47 by avuorio       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t lenght;

	lenght = 0;
	while (*s != '\0')
	{
		lenght++;
		s++;
	}
	return (lenght);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*pointer;

	pointer = (unsigned char*)s;
	while (n > 0)
	{
		*pointer = 0;
		pointer++;
		n--;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*pointer;

	pointer = malloc(size * count);
	if (pointer == NULL)
		return (NULL);
	ft_bzero(pointer, size * count);
	return (pointer);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*destination;
	const char	*source;
	size_t		i;

	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	destination = (char *)dst;
	source = (const char*)src;
	while (i < n)
	{
		destination[i] = source[i];
		i++;
	}
	return (dst);
}

char	*ft_strdup(const char *s1)
{
	char	*pointer;
	int		lenght;

	lenght = ft_strlen(s1);
	pointer = malloc(lenght + 1);
	if (pointer == NULL)
	{
		return (NULL);
	}
	ft_memcpy(pointer, s1, lenght);
	pointer[lenght] = '\0';
	return (pointer);
}
