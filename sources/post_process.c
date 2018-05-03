/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   post_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 16:46:47 by hsabouri          #+#    #+#             */
/*   Updated: 2018/05/03 12:08:00 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_scop.h"
#include "vec.h"

static size_t	sizeit(t_quads quads)
{
	size_t	res;
	size_t	iterator;

	res = 0;
	iterator = 0;
	while (iterator < quads.size)
	{
		if (quads.content[iterator].d >= 0)
			res += 2;
		else
			res += 1;
		iterator++;
	}
	return (res);
}

t_tris		triangulate(t_parsed *parsed)
{
	size_t		iterator;
	t_tris	res;

	if (!(res.content = (t_tri *)malloc(sizeof(t_tri) * sizeit(parsed->quads))))
		error("SYSTEM", "Can't allocate memory.");
	iterator = 0;
	res.size = 0;
	while (iterator < parsed->quads.size)
	{
		res.content[res.size].a = parsed->quads.content[iterator].a;
		res.content[res.size].b = parsed->quads.content[iterator].b;
		res.content[res.size].c = parsed->quads.content[iterator].c;
		res.size++;
		if (parsed->quads.content[iterator].d >= 0)
		{
			res.content[res.size].a = parsed->quads.content[iterator].a;
			res.content[res.size].b = parsed->quads.content[iterator].c;
			res.content[res.size].c = parsed->quads.content[iterator].d;
			res.size++;
		}
		iterator += 1;
	}
	return (res);
}

t_env		assign_color(t_env *env)
{
	size_t			i;
	t_color			start;
	t_color			end;
	t_color			current;
	t_vec4			*vertices;

	i = 0;
	start = (t_color) {1.0, 0.0, 0.239, 1.0};
	end = (t_color) {0.0, 1.0, 1.0, 1.0};
	vertices = env->vertices.content;
	while (i < env->indexes.size)
	{
		current = get_color(start, end, i, env->indexes.size);
		vertices[env->indexes.content[i].a].color = current;
		vertices[env->indexes.content[i].b].color = current;
		vertices[env->indexes.content[i].c].color = current;
		i++;
	}
	return (*env);
}

t_vertices		scale(t_vertices *src, GLfloat amount)
{
	t_vec4			*current;
	size_t			iterator;

	iterator = 0;
	while (iterator < src->size)
	{
		current = src->content + iterator;
		*current = vec_uniform_scale(*current, amount);
		iterator++;
	}
	return (*src);
}

t_vertices		center(t_vertices *src)
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

t_vertices		rotate(t_vertices *src, t_axis axis, GLfloat amount)
{
	t_vec4			*current;
	size_t			iterator;

	iterator = 0;
	while (iterator < src->size)
	{
		current = src->content + iterator;
		*current = vec_rot(*current, axis, amount);
		iterator++;
	}
	return (*src);
}

t_vertices		translate(t_vertices *src, GLfloat x, GLfloat y, GLfloat z)
{
	t_vec4			*current;
	size_t			iterator;

	iterator = 0;
	while (iterator < src->size)
	{
		current = src->content + iterator;
		*current = vec_trans(*current, x, y, z);
		iterator++;
	}
	return (*src);
}
