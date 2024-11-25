/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdawai <cdawai@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:36:04 by cdawai            #+#    #+#             */
/*   Updated: 2024/11/25 17:13:06 by cdawai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// void	*ft_calloc(size_t count, size_t size)
// {
// 	void	*pointer;
// 	size_t	total_size;

// 	if (count == 0 || size == 0)
// 		return (malloc(1));
// 	total_size = count * size;
// 	if (total_size == 0 || total_size / count != size)
// 		return (NULL);
// 	pointer = malloc(total_size);
// 	if (!pointer)
// 	{
// 		free(pointer);
// 		return (NULL);
// 	}
// 	ft_memset(pointer, 0, total_size);
// 	return (pointer);
// }

// void	*ft_memset(void *b, int c, size_t len)
// {
// 	char	*str;

// 	str = b;
// 	while (len-- > 0)
// 	{
// 		*str++ = (char)c;
// 	}
// 	return (b);
// }

void	*ft_calloc(size_t count, size_t size)
{
	void	*pointer;
	size_t	total_size;
	char	*str;
	size_t	i;

	if (count == 0 || size == 0)
		return (malloc(1));
	total_size = count * size;
	if (total_size == 0 || total_size / count != size)
		return (NULL);
	pointer = malloc(total_size);
	if (!pointer)
	{
		free(pointer);
		return (NULL);
	}
	str = pointer;
	i = 0;
	while (i < total_size)
	{
		str[i] = 0;
		i++;
	}
	return (pointer);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	d = (char *)dest;
	s = (const char *)src;
	if (!dest && !src)
		return (NULL);
	if (n == 0)
		return (dest);
	while (n--)
	{
		*d++ = *s++;
	}
	return (dest);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	size_t	len1;
	size_t	len2;

	if (!s1 ||!s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	newstr = malloc(sizeof(char) *(len1 + len2 +1));
	if (!newstr)
		return (NULL);
	ft_memcpy(newstr, s1, len1);
	ft_memcpy(newstr + len1, s2, len2);
	newstr[len1 + len2] = '\0';
	return (newstr);
}

char	*ft_strchr(const char *str, int c)
{
	size_t	i;

	i = ft_strlen(str);
	while (i >= 0)
	{
		if (i == 0 && str[i] != c)
			return (NULL);
		if (str[i] == c)
			return ((char *)str + i);
		i--;
	}
	return (NULL);
}
