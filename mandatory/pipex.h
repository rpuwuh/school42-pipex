/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoetess <bpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:37:26 by bpoetess          #+#    #+#             */
/*   Updated: 2022/03/07 15:28:45 by bpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_global
{
	char	**paths;
	char	*infile;
	char	*outfile;
	char	**cmds;
	int		fdfiles[2];
}	t_global;

char		*ft_strchr(char *s, char c);
size_t		ft_strlen(const char *s);

char		**ft_getpaths(char **env);

char		*ft_strdup(const char *s1);
void		ft_cleanfreestring(char **s);

void		ft_error(int errcode);

t_global	*ft_initialize(int argc, char **argv, char **env);
void		ft_glbclear(t_global **glb);

char		*ft_substr(char const *s, unsigned int start, size_t len);

char		**ft_split(char const *s, char c);

char		*ft_stradd(char	**dest, char *src);

char		*ft_strjoin(char const *s1, char const *s2);

int			ft_checkaccess(t_global *glb);
int			ft_checkcmd(char **paths, char *cmd);

int			ft_strcmp(const char *s1, const char *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);

void		ft_processerr(t_global *glb, char **s, char ***split);
void		ft_doexecve(t_global *glb, int i);
void		ft_domiddlecmds(t_global *glb, int *fds, int i);

#endif