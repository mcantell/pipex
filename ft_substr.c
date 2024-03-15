/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcantell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 16:04:59 by mcantell          #+#    #+#             */
/*   Updated: 2024/03/15 16:05:32 by mcantell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*f;
	size_t	t;
	size_t	i;

	t = 0;
	i = 0;
	f = (char *)malloc(sizeof(char) * (len + 1));
	if (!s || !f)
		return (NULL);
	while (s[t])
	{
		if (t >= start && i < len)
		{
			f[i] = s[t];
			i++;
		}
		t++;
	}
	f[i] = '\0';
	return (f);
}
