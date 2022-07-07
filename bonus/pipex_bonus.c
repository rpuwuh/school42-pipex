/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoetess <bpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:37:21 by bpoetess          #+#    #+#             */
/*   Updated: 2022/07/07 05:14:35 by bpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include <unistd.h>

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
		write(fds[1], s2, ft_strlen(s2));
		ft_cleanfreestring(&s2);
		exit(0);
	}
	dup2(fds[0], 0);
	close(fds[0]);
	close(fds[1]);
	wait(0);
	printf("");
}

void	ft_heredoc(t_global *glb, char *lim, int *fds)
{
	char	*s1;
	char	*s2;

	s1 = 0;
	s2 = 0;
	lim = ft_strdup (lim);
	lim = ft_stradd (&lim, "\n");
	while (1)
	{
		s1 = get_next_line(0);
		if (!s1 || !ft_strcmp(s1, lim))
			break ;
		s2 = ft_stradd(&s2, s1);
		ft_cleanfreestring(&s1);
	}
	ft_cleanfreestring(&s1);
	ft_cleanfreestring(&lim);
	ft_heredocprocess(glb, fds, s2);
}

int	ft_choosebehaviour(int argc, char **argv, char **env, t_global **glb)
{
	if (argc < 4)
		exit (0);
	if (ft_strncmp(argv[1], "here_doc", ft_strlen("here_doc")))
	{
		*glb = ft_initialize(argc, argv, env);
		ft_checkaccess(*glb);
		(*glb)->fdfiles[0] = open((*glb)->infile, O_RDONLY);
		dup2((*glb)->fdfiles[0], 0);
		close((*glb)->fdfiles[0]);
		(*glb)->fdfiles[1] = open((*glb)->outfile, 0x601, 0644);
		return (0);
	}
	else
	{
		*glb = ft_initialize(argc - 1, argv + 1, env);
		ft_cleanfreestring(&(*glb)->infile);
		ft_checkaccess(*glb);
		(*glb)->fdfiles[1] = open((*glb)->outfile, 0x209, 0644);
		return (1);
	}
}

int	main(int argc, char **argv, char **env)
{
	t_global	*glb;
	int			i;
	int			fds[2];

	glb = 0;
	fds[0] = 0;
	fds[1] = 1;
	if (ft_choosebehaviour(argc, argv, env, &glb))
		ft_heredoc(glb, argv[2], fds);
	i = 0;
	while (glb->cmds[i + 1])
		ft_domiddlecmds(glb, fds, i++);
	dup2(glb->fdfiles[1], 1);
	ft_doexecve(glb, i);
	ft_glbclear(&glb);
	close(glb->fdfiles[0]);
	close(glb->fdfiles[1]);
	exit (0);
}
