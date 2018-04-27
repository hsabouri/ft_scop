/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   post_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 16:46:47 by hsabouri          #+#    #+#             */
/*   Updated: 2018/04/27 18:55:16 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_scop.h"

static size_t	sizeit(t_quads quads)
{
	size_t	res;
	size_t	iterathor;

	res = 0;
	iterathor = 0;
	while (iterathor < quads.size)
	{
		if (quads.content[iterathor].d >= 0)
			res += 2;
		else
			res += 1;
		iterathor++;
	}
	return (res);
}

t_triangles		triangulate(t_parsed *parsed)
{
	size_t		iterator;
	t_triangles	res;

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

static t_color	get_color(t_color start, t_color end, int pos, int max)
{
	t_color	iter;
	t_color	res;

	iter.r = (end.r - start.r) / max;
	iter.g = (end.g - start.g) / max;
	iter.b = (end.b - start.b) / max;
	iter.a = (end.a - start.a) / max;
	res = start;
	res.r += iter.r * pos;
	res.g += iter.g * pos;
	res.b += iter.b * pos;
	res.a += iter.a * pos;
	return (res);
}

void			assign_color(t_triangles *iba)
{
	size_t	iterator;
	t_color	start;
	t_color	end;

	iterator = 0;
	start = (t_color) {1.0, 0.92157, 0.24313, 1.0};
	end = (t_color) {1.0, 0.29412, 0.24313, 1.0};
	while (iterator < iba->size)
	{
		iba->content[iterator].col = get_color(start, end, iterator, iba->size);
		iterator++;
	}
}
