/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurodrig <aurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:21:34 by aurodrig          #+#    #+#             */
/*   Updated: 2024/08/11 19:15:05 by aurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			i;
	int			j;
	int			flag;

	if (BUFFER_SIZE <= 0 || (read(fd, 0, 0) < 0))
		return (NULL);
	line = NULL;
	flag = 0;
	while (!flag && (buffer[0] || (read(fd, buffer, BUFFER_SIZE) > 0)))
	{
		line = ft_strjoin(line, buffer);
		i = 0;
		j = 0;
		while (buffer[i])
		{
			if (flag)
				buffer[j++] = buffer[i];
			if (buffer[i] == '\n')
				flag = 1;
			buffer[i++] = 0;
		}
	}
	return (line);
}
