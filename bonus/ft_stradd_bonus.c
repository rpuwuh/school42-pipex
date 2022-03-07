/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stradd_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoetess <bpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 17:41:06 by bpoetess          #+#    #+#             */
/*   Updated: 2022/03/07 15:31:40 by bpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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
