/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   super_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcantell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 13:09:53 by mcantell          #+#    #+#             */
/*   Updated: 2024/03/22 11:22:15 by mcantell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
//ho giá una funzione potentissima di skip quindi mi tengo quella
//se c'é qualcosa che non va é perche questa parte é differente
// oltre a vedere cosa c'é tra le virgolette ti salta anche gli spazi
//e si va a carcare anche le flag dopo il comando
//quindi argomanto con le flag

int	super_count(char *str)
{
	int	i;
	int	count;

	count = 0;
	i = jump(0, str, ' ');
	while (str[i])
	{
		if (str[i] == '\'')
			s_o_c(&count, str, &i, '\'');
		else if (str[i] == '\"')
			s_o_c(&count, str, &i, '\"');
		else if (str[i] != ' ')
		{
			count++;
			while (str[i] != '\0' && str[i] != ' ')
				i++;
		}
		else
			i++;
	}
	return (count);
}

char	**su_split(char *str)
{
	char	**su;
	int		i;
	int		j;

	su = (char **)malloc(sizeof(char *) * (super_count(str) + 1));
	donkye(su);
	j = 0;
	i = jump(0, str, ' ');
	while (super_count(str) != j)
	{
		if (str[i] == '\'')
			su[j] = string(&i, str, '\'');
		else if (str[i] == '\"')
			su[j] = string(&i, str, '\"');
		else if (str[i] != ' ')
			su[j] = mini_string(&i, str);
		else
			i++;
		i = jump(i, str, ' ');
		j++;
	}
	su[j] = NULL;
	return (su);
}
