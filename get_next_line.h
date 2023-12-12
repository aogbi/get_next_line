/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aogbi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 16:55:23 by aogbi             #+#    #+#             */
/*   Updated: 2023/12/12 15:49:58 by aogbi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 10


#define BUFFER_SIZE 10

char *get_next_line(int fd);

char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);

char	*ft_strdup(const char *s);

char	*ft_strchr(const char *s, int c);

size_t	ft_strlcat(char *dst, const char *src, size_t size);

char	*ft_strcpy(char *dest, const char *src);


#endif
