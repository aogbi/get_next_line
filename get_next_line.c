/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aogbi <aogbi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 16:55:20 by aogbi             #+#    #+#             */
/*   Updated: 2023/12/13 01:33:20 by aogbi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*readfromfile(int fd, char **stavar)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*line;
	int		bytesRead;
	char	*tmp;

	line = NULL;
	if (*stavar)
	{
		line = ft_strdup(*stavar);
		free(*stavar);
		*stavar = NULL;
	}
	while ((bytesRead = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[bytesRead] = '\0';
		if ((tmp = ft_strchr(buffer, '\n')))
		{
			*stavar = ft_strdup(tmp);
			*tmp = '\0';
		}
		if (!line)
			line = ft_strdup(buffer);
		else
			line = ft_strjoin(line, buffer);
		if (*stavar)
			break;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stavar;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= INT_MAX)
		return (NULL);
	line = readfromfile(fd, &stavar);
	if (stavar)
		*stavar = '\n';
	return (line);
}

int	main(void)
{
	int	fd;

	fd = open("test.txt", O_RDONLY);
	char *line = get_next_line(fd);
	//printf("%s", line);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	//free(line);
	//system("leaks a.out");
	close(fd);	
	return (0);
}
