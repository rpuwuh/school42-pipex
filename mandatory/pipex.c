/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoetess <bpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:37:21 by bpoetess          #+#    #+#             */
/*   Updated: 2022/03/07 16:20:12 by bpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_heredocprocess(t_global *glb, int *fds, char *s2)
{
	int		i;
	pid_t	parent;

	i = pipe(fds);
	parent = fork();
	if (i < 0 || parent < 0)
	{
		ft_cleanfreestring(&s2);
		ft_glbclear(&glb);
		exit (9);
	}
	if (!parent)
	{
		close(fds[0]);
		write(fds[1], s2, ft_strlen(s2) + 1);
		ft_cleanfreestring(&s2);
		exit(0);
	}
	dup2(fds[0], 0);
	close(fds[1]);
	wait(0);
}

int	ft_choosebehaviour(int argc, char **argv, char **env, t_global **glb)
{
	if (argc != 5)
		exit (0);
	*glb = ft_initialize(argc, argv, env);
	ft_checkaccess(*glb);
	(*glb)->fdfiles[0] = open((*glb)->infile, O_RDONLY);
	dup2((*glb)->fdfiles[0], 0);
	return (0);
}

int	main(int argc, char **argv, char **env)
{
	t_global	*glb;
	int			i;
	int			fds[2];

	glb = 0;
	ft_choosebehaviour(argc, argv, env, &glb);
	glb->fdfiles[1] = open(glb->outfile, 0x601, 0644);
	i = 0;
	while (glb->cmds[i + 1])
		ft_domiddlecmds(glb, fds, i++);
	dup2(glb->fdfiles[1], 1);
	ft_doexecve(glb, i);
	ft_glbclear(&glb);
	close(glb->fdfiles[0]);
	close(glb->fdfiles[1]);
	sleep(100);
	exit (8);
}
