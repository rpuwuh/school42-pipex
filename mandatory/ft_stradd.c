/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stradd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoetess <bpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 17:41:06 by bpoetess          #+#    #+#             */
/*   Updated: 2022/03/05 04:20:04 by bpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_stradd(char	**dest, char *src)
{
	char	*res;

	if (!dest)
		return (0);
	if (!src && *dest)
		return (*dest);
	if (!(*dest))
		return (ft_strdup(src));
	res = ft_strjoin(*dest, src);
	free(*dest);
	*dest = res;
	return (res);
}
