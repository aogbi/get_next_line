/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   git_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aogbi <aogbi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 22:03:47 by aogbi             #+#    #+#             */
/*   Updated: 2023/12/11 22:32:44 by aogbi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "git_next_line.h"

char *readfromfile(int  fd)
{
    static char	buff[BUFF_SIZE];
    char    *str;

    
    return (str);
}

char *get_next_line(int fd)
{
    char    *line;

    line = readfromfile(fd);
    return (line);
}