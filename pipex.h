/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcantell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:45:29 by mcantell          #+#    #+#             */
/*   Updated: 2024/03/22 11:29:15 by mcantell         ###   ########.fr       */
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

char	*ft_strnstr(const char *s1, const char *s2, int n);
int		ft_strlen(const char *s);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strjoin(char *s, char *s2);
char	*ft_strlcpy(char *s1, char *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		super_count(char *str);
int		jump(int i, char *str, char c);
void	s_o_c(int *count, char *str, int *i, char c);
void	donkye(char **str);
char	*string(int *i, char *str, char c);
char	*mini_string(int *i, char *str);
char	**su_split(char *str);
void	sergent(int *fd, pid_t *pid);
char	**ft_split(char const *s, char c);
char	*name(char *comand, char *path);
int		in_out(char *outfile);
char	*path(char **envp);
void	dwarf(char *comand, char *path);
int		in(char *infile);

#endif