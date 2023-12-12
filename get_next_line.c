/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aogbi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 16:55:20 by aogbi             #+#    #+#             */
/*   Updated: 2023/12/12 17:43:46 by aogbi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *catline(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
			line[i] = '\0';
		i++;
	}
	return line;
}
static char	*readfromfile(int	fd, char **stavar)
{
	char		buffer[BUFFER_SIZE + 1];
	char			*line;
	int				bytesRead;
	int 	x;


	if (*stavar)
	{
		line = ft_strdup(*stavar);
		free(*stavar);
	}
	else
		line = NULL;
	x = 1;
	while (x)
	{
		bytesRead = read(fd, buffer, BUFFER_SIZE);
		if (bytesRead == -1)
		{
			free(*stavar);
			free(line);
			return (NULL);
		}
		else if (bytesRead == 0) break ;
		buffer[bytesRead] = '\0';
		*stavar = ft_strdup(ft_strchr(buffer, '\n'));
		if (*stavar) x = 0;
		if (line)
			line = catline(ft_strjoin(line, buffer));
		else
			line = catline(ft_strdup(buffer));
	}
	return (line);
}
char *get_next_line(int fd)
{
	static char			*stavar;
	char				*line;

	stavar = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = readfromfile(fd, &stavar);
	return (line);
}


int main (void)
{
	int	fd;
	fd = open("test.txt", O_RDONLY);
	printf("%s\n",get_next_line(fd));
	return 0;
}
