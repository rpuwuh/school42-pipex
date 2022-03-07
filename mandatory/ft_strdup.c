/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoetess <bpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 02:35:05 by bpoetess          #+#    #+#             */
/*   Updated: 2022/03/07 15:28:21 by bpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_cleanfreestring(char **s)
{
	size_t	i;

	if (!s)
		return ;
	i = 0;
	while (*s && *s[i])
		*s[i] = '\0';
	if (*s)
		free(*s);
	*s = 0;
	return ;
}

char	*ft_strdup(const char *s1)
{
	size_t	len;
	size_t	i;
	char	*res;

	len = ft_strlen(s1);
	res = (char *) malloc (len + 1);
	if (res == 0)
		return (0);
	i = 0;
	while (s1[i])
	{
		res [i] = s1 [i];
		i++;
	}
	res [len] = 0;
	return (res);
}
