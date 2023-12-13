/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aogbi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 01:57:48 by aogbi             #+#    #+#             */
/*   Updated: 2023/12/13 18:42:37 by aogbi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_strjoin(char **s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*new;

	if(!*s1 && !s2)
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
