/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdawai <cdawai@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:31:42 by cdawai            #+#    #+#             */
/*   Updated: 2024/12/05 17:49:23 by cdawai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_line(buffer);
	buffer = ft_next(buffer);
	return (line);
}

char	*read_file(int fd, char *buf)
{
	char	*temp;
	ssize_t	byte_read;

	if (!buf)
		buf = ft_calloc(1, 1);
	temp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read(fd, temp, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(buf);
			free(temp);
			return (NULL);
		}
		temp[byte_read] = 0;
		buf = ft_free(buf, temp);
		if (ft_strchr(temp, '\n'))
			break ;
	}
	free(temp);
	return (buf);
}

char	*ft_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*ft_next(char *buffer)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	line = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	i++;
	while (buffer[i])
		line[j++] = buffer[i++];
	free(buffer);
	return (line);
}

char	*ft_free(char *buf, char *temp)
{
	char	*newstr;

	newstr = ft_strjoin(buf, temp);
	free(buf);
	return (newstr);
}

// #include <fcntl.h>
// #include <stdio.h>

// int    main(void)
// {
//     int fd = open("test", O_RDONLY);
//     if (fd == -1)
//         return (1);

//     char *result;
//     while ((result = get_next_line(fd)) != NULL) 
// 	// Continue until get_next_line returns NULL
//     {
//         printf("%s", result);
//         free(result); // Free the memory allocated for the line
//     }
//     close(fd);
//     return(0);
// }