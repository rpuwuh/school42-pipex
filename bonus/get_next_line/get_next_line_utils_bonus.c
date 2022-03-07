/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoetess <bpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 17:19:48 by bpoetess          #+#    #+#             */
/*   Updated: 2022/03/05 03:58:48 by bpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr1(char *s, char c)
{
	size_t	i;

	i = 0;
	while (s [i])
	{
		if (s[i] == (unsigned char) c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == (unsigned char) c)
		return ((char *)(s + i));
	return (0);
}

char	*ft_strjoin1(char const *s1, char const *s2)
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

char	*ft_gnl_buffer(ssize_t *readc, int fd, char **str_p)
{
	char	bf[BUFFER_SIZE + 1];
	char	*temp;
	size_t	i;

	*readc = read (fd, bf, BUFFER_SIZE);
	bf[*readc] = '\0';
	temp = *str_p;
	*str_p = ft_strjoin1(temp, bf);
	if (!*str_p)
	{
		i = 0;
		while (temp[i])
			temp[i++] = '\0';
		free(temp);
		return (0);
	}
	i = 0;
	while (temp[i])
		temp[i++] = '\0';
	free(temp);
	return (*str_p);
}
