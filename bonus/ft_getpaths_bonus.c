/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getpaths_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoetess <bpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 17:29:49 by bpoetess          #+#    #+#             */
/*   Updated: 2022/03/07 15:31:23 by bpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static char	**ft_givemenormalpath(char *env)
{
	char	**res;
	char	*s;

	s = ft_strdup(env);
	s = ft_stradd(&s, ":./");
	if (!s)
		return (0);
	res = ft_split(s + 5, ':');
	free (s);
	return (res);
}

char	**ft_getpaths(char **env)
{
	int		i;
	char	**res;

	if (!env || !env[0])
		return (0);
	i = 0;
	while (env[i])
	{
		if (env[i][0] == 'P' && env[i][1] == 'A' && env[i][2] == 'T'
			&& env[i][3] == 'H' && env[i][4] == '=')
			return (ft_givemenormalpath(env[i]));
		i++;
	}
	res = (char **) malloc (sizeof(char *) * 2);
	if (!res)
		return (0);
	res[0] = ft_strdup("./");
	res[1] = 0;
	return (res);
}
