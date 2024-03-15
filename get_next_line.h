/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcantell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 17:29:35 by mcantell          #+#    #+#             */
/*   Updated: 2024/03/15 20:04:41 by mcantell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H 
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

char	*checkpoint(char *left_line);
char	*take(char *left_line);
char	*ft_strjoint(char *left_line, char *buf);
char	*ft_strachr(char *left_line, int c);
int		len(char *str);
char	*get_next_line(int fd);
char	*road(int fd, char *left_line);
#endif