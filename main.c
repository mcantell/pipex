/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcantell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 20:07:48 by mcantell          #+#    #+#             */
/*   Updated: 2024/03/22 11:31:10 by mcantell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
//usi la seconda cella di fd perché ti vai a prendere lo standard imput
//dentro il controllo ti fai un bel fork che é l'unico punto in cui usi fork
//nel wait e' null perche' lo status non ci interessa
//mettiamo zero sempre nel wait per dirgli che e' andato a buon fine
void	dwarf(char *comand, char *path)
{
	int		fd[2];
	pid_t	pid;

	sergent(fd, &pid);
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		execve(name(comand, path), su_split(comand), NULL);
		perror("command error");
		exit(-1);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		waitpid(pid, NULL, 0);
	}
}

int	main(int ac, char **av, char **envp)
{
	int		i;
	char	*comand;

	i = 1;
	if (ac == 5)
	{
		in_out(av[ac - 1]);
		dup2(in(av[i]), STDIN_FILENO);
		i = 2;
		dwarf(av[i++], path(envp));
		dup2(in_out(av[ac - 1]), STDOUT_FILENO);
		comand = av[3];
		execve(name(comand, path(envp)), su_split(comand), NULL);
		perror("last command error");
		exit(-1);
	}
	write (1, "not enough arguments", 20);
	return (0);
}
