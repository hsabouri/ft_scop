/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 16:46:47 by hsabouri          #+#    #+#             */
/*   Updated: 2018/05/04 22:02:52 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_scop.h"

float			btof(unsigned char n)
{
	const static float	step = 1.0/255.0;

	return (step * n);
}

t_color			get_color(t_color start, t_color end, int pos, int max)
{
	t_color	step;
	t_color res;

	step.r = (end.r - start.r) / (float)max;
	step.g = (end.g - start.g) / (float)max;
	step.b = (end.b - start.b) / (float)max;
	step.a = (end.a - start.a) / (float)max;
	res = start;
	res.r += step.r * pos;
	res.g += step.g * pos;
	res.b += step.b * pos;
	res.a += step.a * pos;
	return (res);
}

t_env			assign_color(t_env *env)
{
	size_t			i;
	size_t			random;
	t_color			current;
	t_vec4			*vertices;

	i = 0;
	vertices = env->vertices.content;
	while (i < env->indexes.size)
	{
		random = rand();
		current = get_color(RED, YELLOW, random, RAND_MAX);
		vertices[env->indexes.content[i].a].color = current;
		vertices[env->indexes.content[i].b].color = current;
		vertices[env->indexes.content[i].c].color = current;
		i++;
	}
	return (*env);
}
