/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corrupt_cop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcantell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 14:51:03 by mcantell          #+#    #+#             */
/*   Updated: 2024/03/21 17:19:33 by mcantell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
//qui di bello ci mettiamo i controlli per gli errori
//usi pipe proprio per vedere se va in errore o meno
void	donkye(char **str)
{
	if (str == NULL)
	{
		perror ("corrupt cop stop you: error");
		exit(-1);
	}
}

void	sergent(int *fd, pid_t *pid)
{
	if (pipe(fd) == -1)
	{
		perror("corrupt cop stop you: pipe error");
		exit(-1);
	}
	*pid = fork();
	if (*pid == -1)
	{
		perror("corrupt cop stop you: fork error");
		exit(-1);
	}
}

//metto 0777 perche su sistemi linux mac i permessi lavorano su un sistema
//ottale (in base 8, quindi da 0 a 7) e facendo cosi specifichi 
//che tutti possano avere tutti i peressi per poter lavorare sul file
int	in_out(char *outfile)
{
	int	fd;

	fd = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
	{
		perror("error open file");
		exit(-1);
	}
	return (fd);
}

//adesso facciamo un controllo solo per l'infile
int	in(char *infile)
{
	int	fd;

	fd = open(infile, O_RDONLY);
	if (fd == -1)
	{
		perror ("infile error");
		exit(-1);
	}
	return (fd);
}
