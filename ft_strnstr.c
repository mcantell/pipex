/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcantell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:34:06 by mcantell          #+#    #+#             */
/*   Updated: 2024/03/15 15:50:44 by mcantell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strnstr(const char *s1, const char *s2, int n)
{
	int	s2len;
	int	i;
	int	j;

	s2len = ft_strlen(s2);
	if (s1 == s2 || s2len == 0)
		return ((char *)s1);
	i = 0;
	while (i < n && s1[i] != '\0')
	{
		j = 0;
		while (s1[i + j] != '\0' && s2[j] != '\0'
			&& (i + j) < n && s1[i + j] == s2[j])
		{
			j++;
			if ((j == n && j == s2len) || j == s2len)
				return ((char *)(s1 + i));
		}
		i++;
	}
	return (0);
}
