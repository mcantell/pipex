/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcantell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 16:38:36 by mcantell          #+#    #+#             */
/*   Updated: 2024/03/15 20:05:19 by mcantell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	word_count(char *str, char c)
{
	int	count;

	count = 0;
	while (*str == c && *str)
		str++;
	while (*str)
	{
		if (*str != c)
		{
			count++;
			while (*str && *str != c)
				str++;
		}
		else
			str++;
	}
	return (count);
}

int	jump(int i, char *str, char c)
{
	while (*str == c)
		i++;
	return (i);
}

char	**ft_split(char *str, char c)
{
	int			i;
	int			j;
	char		**bazar;
	int			av;

	i = 0;
	j = 0;
	av = 0;
	if (!str)
		return (NULL);
	bazar = (char **)malloc(sizeof(char *) * (word_count(str, c) + 1));
	if (!bazar)
		return (NULL);
	i = jump(i, str, c);
	while (str[i])
	{
		j = i;
		while (str[i] > 32)
			i++;
		bazar[av] = ft_substr(str, j, i - j);
		i = jump(i, str, c);
		av++;
	}
	bazar[av] = NULL;
	return (bazar);
}
