/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoetess <bpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 18:11:19 by bpoetess          #+#    #+#             */
/*   Updated: 2022/03/13 10:49:09 by bpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	ft_initializeerr(t_global *glb)
{
	int	i;

	i = 0;
	if (!glb)
		exit (2);
	if (glb->paths)
	{
		while (glb->paths[i])
			free (glb->paths[i++]);
		free (glb->paths);
	}
	i = 0;
	if (glb->infile)
		free(glb->infile);
	if (glb->outfile)
		free(glb->outfile);
	if (glb->cmds)
	{
		while (glb->cmds[i])
			free (glb->cmds[i++]);
		free (glb->cmds);
	}
	free(glb);
	exit(2);
}

t_global	*ft_initialize(int argc, char **argv, char **env)
{
	int			i;
	t_global	*glb;

	glb = (t_global *) malloc (sizeof(t_global));
	if (!glb)
		ft_initializeerr(glb);
	glb->paths = ft_getpaths(env);
	glb->infile = ft_strdup(argv[1]);
	glb->cmds = (char **) malloc (sizeof(char *) * (argc - 2));
	if (!glb->paths || !glb->infile || !glb->cmds)
		ft_initializeerr(glb);
	i = 2;
	while (i < argc - 1)
	{
		glb->cmds[i - 2] = ft_strdup(argv[i]);
		if (!glb->cmds[(i++) - 2])
			ft_initializeerr(glb);
	}
	glb->cmds[i - 2] = 0;
	glb->outfile = ft_strdup(argv[i]);
	if (!glb->outfile)
		ft_initializeerr(glb);
	return (glb);
}

void	ft_glbclear(t_global **glb)
{
	size_t	i;

	if (!*glb)
		return ;
	i = 0;
	while ((*glb)->paths && (*glb)->paths[i])
		ft_cleanfreestring(&(*glb)->paths[i++]);
	if ((*glb)->paths)
		free((*glb)->paths);
	i = 0;
	while ((*glb)->cmds && (*glb)->cmds[i])
		ft_cleanfreestring(&(*glb)->cmds[i++]);
	if ((*glb)->cmds)
		free((*glb)->cmds);
	if ((*glb)->infile)
		ft_cleanfreestring(&(*glb)->infile);
	if ((*glb)->outfile)
		ft_cleanfreestring(&(*glb)->outfile);
	free (*glb);
}
