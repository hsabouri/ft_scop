/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   post_process2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 16:46:47 by hsabouri          #+#    #+#             */
/*   Updated: 2018/05/11 23:06:28 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_scop.h"
#include "vec.h"

t_vertices	center(t_vertices *src)
{
	const t_vec4	center = find_center(src);
	t_vec4			*current;
	size_t			iterator;

	iterator = 0;
	while (iterator < src->size)
	{
		current = src->content + iterator;
		*current = vec_trans(*current, -center.x, -center.y, -center.z);
		iterator++;
	}
	return (*src);
}

t_env		expend(t_env *env)
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
		new_verts.content[i * 3 + 0].tex.u = 0;
		new_verts.content[i * 3 + 0].tex.v = 0;
		indexes[i].a = i * 3 + 0;
		new_verts.content[i * 3 + 1] = vertices[indexes[i].b];
		new_verts.content[i * 3 + 1].tex.u = 0.5;
		new_verts.content[i * 3 + 1].tex.v = 1;
		indexes[i].b = i * 3 + 1;
		new_verts.content[i * 3 + 2] = vertices[indexes[i].c];
		new_verts.content[i * 3 + 2].tex.u = 1;
		new_verts.content[i * 3 + 2].tex.v = 0;
		indexes[i].c = i * 3 + 2;
		i++;
	}
	free(env->vertices.content);
	env->vertices = new_verts;
	return (*env);
}

GLfloat		find_longest(t_vertices *vertices)
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

t_env		assign_texture_coords(t_env *env)
{
	size_t	i;
	t_vec4	*vertices;

	i = 0;
	vertices = env->vertices.content;
	while (i < env->vertices.size)
	{
		vertices[i].tex.u = vertices[i].x / 1.1 + 0.5;
		vertices[i].tex.v = vertices[i].y / 1.1 + 0.5;
		i++;
	}
	return (*env);
}
