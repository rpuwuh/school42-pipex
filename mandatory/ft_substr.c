/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikhail <mikhail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 01:55:02 by bpoetess          #+#    #+#             */
/*   Updated: 2022/03/03 02:02:16 by mikhail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*res;

	if (start >= ft_strlen(s))
	{
		res = (char *) malloc (sizeof(char));
		return (res);
	}
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	res = (char *) malloc ((len + 1) * sizeof(char));
	if (res == 0)
		return (0);
	i = 0;
	while (i < len && s[start + i])
	{
		res[i] = s[start + i];
		i++;
	}
	res [i] = (char) 0;
	return (res);
}
