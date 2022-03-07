/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processes_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoetess <bpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 09:42:28 by bpoetess          #+#    #+#             */
/*   Updated: 2022/03/07 15:31:33 by bpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_processerr(t_global *glb, char **s, char ***split)
{
	int	i;

	i = 0;
	ft_glbclear(&glb);
	while (*split && (*split)[i])
	{
		free((*split)[i]);
	}
	if (*split)
		free(*split);
	if (*s)
		free(*s);
	exit(4);
}

void	ft_doexecve(t_global *glb, int i)
{
	char	**args_splitted;
	char	*s;

	args_splitted = ft_split(glb->cmds[i], ' ');
	if (!args_splitted)
		ft_processerr(glb, &s, &args_splitted);
	s = ft_strdup(glb->paths[ft_checkcmd(glb->paths, glb->cmds[i]) - 1]);
	s = ft_stradd(&s, "/");
	s = ft_stradd(&s, *args_splitted);
	if (!glb->cmds[i + 1])
		ft_glbclear(&glb);
	if (!s || !args_splitted || !*args_splitted)
		ft_processerr(glb, &s, &args_splitted);
	execve(s, args_splitted, 0);
}

void	ft_domiddlecmds(t_global *glb, int *fds, int i)
{
	pid_t	parent;

	i = pipe(fds);
	parent = fork();
	if (i < 0 || parent < 0)
		ft_processerr(glb, 0, 0);
	if (!parent)
	{
		dup2(fds[1], 1);
		close(fds[0]);
		ft_doexecve(glb, i);
		exit(5);
	}
	dup2(fds[0], 0);
	close(fds[1]);
}
