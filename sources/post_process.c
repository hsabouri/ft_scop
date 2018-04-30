/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   post_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 16:46:47 by hsabouri          #+#    #+#             */
/*   Updated: 2018/04/28 16:55:51 by hsabouri         ###   ########.fr       */
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

t_colors		assign_color(t_tris *iba)
{
	size_t		iterator;
	t_color		start;
	t_color		end;
	t_colors	res;

	iterator = 0;
	start = (t_color) {1.0, 0.92157, 0.24313, 1.0};
	end = (t_color) {1.0, 0.29412, 0.24313, 1.0};
	if (!(res.content = (t_color *)malloc(sizeof(t_color) * iba->size)))
		error("SYSTEM", "Can't allocate memory for colors");
	res.size = iba->size;
	while (iterator < res.size)
	{
		res.content[iterator] = get_color(start, end, iterator, iba->size);
		iterator++;
	}
	return (res);
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
		*current = vec_sub(*current, center);
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
