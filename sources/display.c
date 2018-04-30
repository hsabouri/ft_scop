/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 10:35:42 by hsabouri          #+#    #+#             */
/*   Updated: 2018/04/30 13:58:47 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include <stdio.h>

void	display_vec(t_vec4 vec)
{
	const GLfloat	*vec_t = (GLfloat *)&vec;
	size_t			i;
	size_t			j;

	i = 0;
	while (i < 4)
	{
		printf("| ");
		j = 0;
		while (j < 4)
		{
			printf("%5.2f, ", vec_t[i * 4 + j]);
			j++;
		}
		printf(" |\n");
		i++;
	}
}
