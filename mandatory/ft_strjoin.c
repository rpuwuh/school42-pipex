/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikhail <mikhail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 03:57:35 by bpoetess          #+#    #+#             */
/*   Updated: 2022/03/03 03:08:28 by mikhail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	i;
	size_t	t;

	res = (char *) malloc (ft_strlen (s1) + ft_strlen (s2) + 1);
	if (res == 0)
		return (res);
	i = 0;
	while (s1 [i])
	{
		res [i] = s1 [i];
		i++;
	}
	i = 0;
	t = ft_strlen(s1);
	while (s2 [i])
	{
		res [t + i] = s2 [i];
		i++;
	}
	res [ft_strlen (s1) + ft_strlen (s2)] = '\0';
	return (res);
}
