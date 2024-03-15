/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcantell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:45:29 by mcantell          #+#    #+#             */
/*   Updated: 2024/03/15 16:18:33 by mcantell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <sys/wait.h>
# include "get_next_line.h"

char	*ft_strnstr(const char *s1, const char *s2, int n);
int		*strlen(char *s);
int		*ft_strcmp(char *s1, char *s2);
char	*ft_strjoin(char *s, char *s2);
char	*ft_strlcpy(char *s1, char *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
#endif