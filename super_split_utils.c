/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   super_split_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcantell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 13:33:27 by mcantell          #+#    #+#             */
/*   Updated: 2024/03/16 15:34:17 by mcantell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
//questo é uno skip oppure un aumento di count 
//mi prendo il valore di partenza cosí che se devo considerare il comando lo fa
//se effettivamente arriva a fine stringa mi riprende il carattere
//se invece ha incontrato solo il carattere c aumenta il count delle parole
void	s_o_c(int count, char *str, int i, char c)
{
	int	j;

	i++;
	j = i;
	while (str[i] != '\0' && str[i] != c)
		i++;
	if (str[i] == '\0')
		i = j;
	else
		count++;
}

//qui mi deve prendere quello che c'é trá gli apici e se non 
char	*string(int i, char *str, char c)
{
	int	c;

	i++;
	c = i;
	while (str[i] && str[i] != c)
		i++;
	if (str[i] == '\0')
		return (ft_substr(str, c - 1, i - c + 1));
	else
		return (ft_substr(str, c, i - c));
}
//mi faccio una funzione per gli spazi che anche quelli non devono mancare

char	*mini_srtring(int i, char *str)
{
	int	b;

	i++;
	b = i;
	while (str[i] && str[i] != ' ')
		i++;
	return (ft_substr(str, b, i - b));
}
