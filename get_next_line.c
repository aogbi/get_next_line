/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aogbi <aogbi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 16:55:20 by aogbi             #+#    #+#             */
/*   Updated: 2023/12/14 00:58:05 by aogbi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strdup(char *s)
{
	char	*copy;
	size_t	len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	copy = (char *)malloc(sizeof(char) * (len + 1));
	if (!copy)
		return (NULL);
	else
		ft_strlcpy(copy, s, len + 1);
	return (copy);
}

static void	ft_strjoin(char **s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*new;

	if (!*s1 && !s2)
		return ;
	len1 = 0;
	len2 = 0;
	if (*s1)
		len1 = ft_strlen(*s1);
	len2 = ft_strlen(s2);
	new = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!new)
		return ;
	if (*s1)
		ft_strlcpy(new, *s1, len1 + 1);
	free(*s1);
	*s1 = new;
	ft_strlcat(*s1, s2, len1 + len2 + 1);
}

static char	*helpreadfromfile(char *buffer, int bytesread, char **stavar,
		char *line)
{
	char	*tmp;

	buffer[bytesread] = '\0';
	tmp = ft_strchr(buffer, '\n');
	if (tmp)
	{
		*stavar = ft_strdup(tmp + 1);
		*(tmp + 1) = '\0';
	}
	ft_strjoin(&line, buffer);
	return (line);
}

static char	*readfromfile(int fd, char **stavar, char *line)
{
	char	buffer[BUFFER_SIZE + 1];
	int		bytesread;

	if (*stavar)
	{
		line = ft_strdup(*stavar);
		free_memory(stavar);
	}
	while (1)
	{
		bytesread = read(fd, buffer, BUFFER_SIZE);
		if (bytesread == -1 || (bytesread == 0 && !line))
		{
			free_memory(&line);
			return (NULL);
		}
		else if (bytesread == 0)
			break ;
		line = helpreadfromfile(buffer, bytesread, stavar, line);
		if (*stavar)
			break ;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stavar;
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= INT_MAX)
		return (NULL);
	line = readfromfile(fd, &stavar, line);
	if (!stavar && !line)
	{
		free_memory(&line);
		return (NULL);
	}
	return (line);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*line;

// 	fd = open("test.txt", O_RDONLY);
// 	line = get_next_line(fd);
// 	while (line)
// 	{
// 		printf("%s", line);
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// 	close(fd);
// 	return (0);
// }