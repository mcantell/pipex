/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcantell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 20:09:08 by mcantell          #+#    #+#             */
/*   Updated: 2024/03/22 11:29:09 by mcantell         ###   ########.fr       */
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
		if (ft_strcmp(envp[i], "PATH=") == 0)
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

	c = ft_split((char *)comand, ' ');
	trace = ft_split((char *)path, ':');
	i = 0;
	while (trace[i] != NULL)
	{
		if (access(ft_strjoin(ft_strjoin(trace[i], "/"), c[0]), X_OK))
			return (ft_strjoin(ft_strjoin(trace[i], "/"), c[0]));
		i++;
	}
	perror("command not found");
	exit(-1);
}
