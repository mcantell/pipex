/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcantell <mcantell@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 20:09:08 by mcantell          #+#    #+#             */
/*   Updated: 2024/06/04 12:43:02 by mcantell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
//per vedere se esiste un path dobbiamo banalmente cercare se esiste PATH=
char	*path(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (strncmp(envp[i], "PATH=", 5) == 0)
			return (envp[i]);
		i++;
	}
	perror("path not found");
	exit(-1);
}
//qui invece ti vaui a cercare il comando tra i vari path
//ti fai uno strjoin nello strjoin cosí effettivamente ti cerchi e trovi
//quasi con un brute force se esiste e con access come funzione che ti vede
//se é eseguibile
//metti i due puntini perché su bash trovi appunto il path diviso tra due punti
//usi c[0] perché é lí che c'é il comando da cercare e non ci interessa

char	*name(char *comand, char *path)
{
	char	**c;
	char	**trace;
	int		i;
	char	*strj;

	c = ft_split((char *)comand, ' ');
	trace = ft_split((char *)path + 5, ':');
	i = 0;
	while (trace[i] != NULL)
	{
		strj = strjoin2(ft_strjoin(trace[i], "/"), c[0]);
		if (!(access(strj, R_OK)))
		{
			ft_free (c);
			ft_free (trace);
			return (strj);
		}
		i++;
		free (strj);
	}
	ft_free (c);
	ft_free (trace);
	return (comand);
}
