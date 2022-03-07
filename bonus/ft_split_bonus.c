/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoetess <bpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 04:51:06 by bpoetess          #+#    #+#             */
/*   Updated: 2022/03/07 15:31:37 by bpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static char	**ft_spliterr(char **res)
{
	int	i;

	i = 0;
	while (res && res[i])
		free(res[i++]);
	if (res)
		free(res);
	return (0);
}

static size_t	ft_countwords(char const *s, char c)
{
	size_t	i;
	size_t	res;

	i = 0;
	res = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			res++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (res);
}

static char	*ft_newword(char const	*s, char c)
{
	size_t	i;
	char	*res;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	res = ft_substr(s, 0, i);
	return (res);
}

static char	**ft_splitloop(char const *s, char c, char ***res)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			(*res)[j++] = ft_newword(s + i, c);
		if (!(*res)[j - 1])
			return (ft_spliterr(*res));
		while (s[i] && s[i] != c)
			i++;
	}
	(*res)[j] = 0;
	return (*res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;

	res = (char **) malloc ((sizeof(char *)) * (ft_countwords (s, c) + 1));
	if (res == 0)
		return (0);
	if (!ft_countwords (s, c))
	{
		*res = 0;
		return (res);
	}
	return (ft_splitloop(s, c, &res));
}
