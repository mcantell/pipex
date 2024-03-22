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
