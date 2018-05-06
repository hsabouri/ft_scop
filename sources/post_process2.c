/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   post_process2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 16:46:47 by hsabouri          #+#    #+#             */
/*   Updated: 2018/05/05 16:57:28 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_scop.h"
#include "vec.h"

t_env	expend(t_env *env)
{
	t_vertices		new_verts;
	const t_vec4	*vertices = env->vertices.content;
	t_tri			*indexes;
	size_t			i;
	
	new_verts.size = env->indexes.size * 3;
	new_verts.content = (t_vec4 *)malloc(sizeof(t_vec4) * new_verts.size);
	indexes = env->indexes.content;
	i = 0;
	while (i < env->indexes.size)
	{
		new_verts.content[i * 3 + 0] = vertices[indexes[i].a];
		indexes[i].a = i * 3 + 0;
		new_verts.content[i * 3 + 1] = vertices[indexes[i].b];
		indexes[i].b = i * 3 + 1;
		new_verts.content[i * 3 + 2] = vertices[indexes[i].c];
		indexes[i].c = i * 3 + 2;
		i++;
	}
	free(env->vertices.content);
	env->vertices = new_verts;
	return (*env);
}

GLfloat	find_longest(t_vertices *vertices)
{
	const t_vec4	*verts_t = vertices->content;
	GLfloat			longest;
	GLfloat			current;
	size_t			i;

	i = 0;
	longest = 0.0;
	while (i < vertices->size)
	{
		current = ft_sqrt(verts_t[i].x * verts_t[i].x\
						+ verts_t[i].y * verts_t[i].y\
						+ verts_t[i].z * verts_t[i].z);
		if (longest < current)
			longest = current;
		i++;
	}
	return (longest);
}

t_vertices	reduce(t_vertices *vertices)
{
	const GLfloat	longest = find_longest(vertices);
	size_t			i;

	i = 0;
	while (i < vertices->size)
	{
		vertices->content[i].x /= longest;
		vertices->content[i].y /= longest;
		vertices->content[i].z /= longest;
		i++;
	}
	return (*vertices);
}
