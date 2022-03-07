/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoetess <bpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 14:44:04 by bpoetess          #+#    #+#             */
/*   Updated: 2022/03/07 15:32:39 by bpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef MAX_BUFFER
#  define MAX_BUFFER 255
# endif

# include "../pipex_bonus.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

char		*ft_strchr1(char *s, char c);
char		*ft_strjoin1(char const *s1, char const *s2);
char		*ft_gnl_buffer(ssize_t *readc, int fd, char **str_p);

char		*get_next_line_old(char **tail, int fd);
void		ft_cleanfreestring(char **s);
char		*ft_gnl_trim(ssize_t readc, char **tail_p, char **str_p);
char		*ft_newstring(void);
char		*get_next_line(int fd);

#endif