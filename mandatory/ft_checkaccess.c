/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkaccess.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoetess <bpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 03:36:19 by mikhail           #+#    #+#             */
/*   Updated: 2022/03/07 16:05:52 by bpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_checkcmdraw(char *cmd)
{
	if (!ft_strchr(cmd, '/'))
		return (1);
	if (access(cmd, X_OK) == -1)
		return (0);
	return (1);
}

int	ft_freesplitstr(char ***s)
{
	size_t	i;

	i = 0;
	while (s && *s && (*s)[i])
		ft_cleanfreestring(&((*s)[i++]));
	if (*s)
		free(*s);
	return (0);
}

int	ft_checkcmd(char **paths, char *cmd)
{
	int		i;
	char	*s;
	char	**cmd_split;

	i = 0;
	cmd_split = ft_split(cmd, ' ');
	if (ft_strchr(cmd, ' ') && cmd_split && *cmd_split)
		cmd = *cmd_split;
	while (paths[i])
	{
		s = ft_strdup(paths[i]);
		s = ft_stradd(&s, "/");
		s = ft_stradd(&s, cmd);
		if (access(s, X_OK) != -1)
		{
			ft_freesplitstr(&cmd_split);
			ft_cleanfreestring(&s);
			return (i + 1);
		}
		ft_cleanfreestring(&s);
		i++;
	}
	ft_freesplitstr(&cmd_split);
	return (0);
}

static int	ft_checkcmds(char **paths, char **cmds)
{
	int	i;

	i = 0;
	while (cmds[i])
	{
		if (!ft_checkcmdraw(cmds[i++]) && !ft_checkcmd(paths, cmds[i]))
		{
			write(2, "No access to a command\n", 23);
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_checkaccess(t_global *glb)
{
	char	*s;

	s = 0;
	if (glb->infile)
	{
		s = ft_strdup("./");
		s = ft_stradd(&s, glb->infile);
	}
	if (s && access(s, R_OK) == -1)
	{
		if (access(s, R_OK) == -1)
			write(2, "No access to the input file\n", 29);
		ft_cleanfreestring(&s);
		ft_glbclear(&glb);
		exit(3);
	}
	ft_cleanfreestring(&s);
	if (!ft_checkcmds(glb->paths, glb->cmds))
	{
		ft_glbclear(&glb);
		exit(3);
	}
	return (1);
}
