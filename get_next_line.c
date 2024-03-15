/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcantell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 17:28:32 by mcantell          #+#    #+#             */
/*   Updated: 2024/03/15 20:04:46 by mcantell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*road(int fd, char *left_line)
{
	char		*buf;
	int			number_byte;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	number_byte = 1;
	while (!ft_strachr(left_line, '\n') && number_byte != 0)
	{
		number_byte = read(fd, buf, BUFFER_SIZE);
		if (number_byte == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[number_byte] = '\0';
		left_line = ft_strjoint(left_line, buf);
	}
	free(buf);
	return (left_line);
}

char	*get_next_line(int fd)
{
	char		*linea;
	static char	*left_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	left_line = road(fd, left_line);
	if (!left_line)
		return (NULL);
	linea = take(left_line);
	left_line = checkpoint(left_line);
	return (linea);
}
