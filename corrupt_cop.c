/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corrupt_cop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcantell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 14:51:03 by mcantell          #+#    #+#             */
/*   Updated: 2024/03/16 15:02:27 by mcantell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
//qui di bello ci mettiamo i controlli per gli errori
void	donkye(char **str)
{
	if (str == NULL)
	{
		perror ("corrupt cop stop you: error");
		exit(-1);
	}
}
