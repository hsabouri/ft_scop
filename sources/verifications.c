/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifications.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 15:28:33 by hsabouri          #+#    #+#             */
/*   Updated: 2018/04/27 17:48:38 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_scop.h"

void	verify(t_parsed *parsed)
{
	size_t	iterator;
	size_t	index;
	int		*current;

	iterator = 0;
	while (iterator < parsed->quads.size)
	{
		current = (int *)(parsed->quads.content + iterator);
		index = 0;
		while (index < 4)
		{
			if ((current[index] < 0 ||\
			(size_t)current[index] >= parsed->vertices.size) &&\
			current[index] != -1)
				error("VERIFICATION", "Face has an invalid vertice.");
			index++;
		}
		iterator++;
	}
}
