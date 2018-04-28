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

void			assign_color(t_tris *iba)
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

t_vertices		normalize_all(t_vertices *src)
{
	size_t	iterator;

	iterator = 0;
	while (iterator < src->size)
	{
		src->content[iterator] = normalize(src->content[iterator]);
		iterator++;
	}
	return (*src);
}

t_vertices		center(t_vertices *src)
{
	const t_vec4	center = find_center(src);
	t_vec4			*current;
	size_t			iterathor;

	iterathor = 0;
	while (iterathor < src->size)
	{
		current = src->content + iterathor;
		*current = vec_sub(*current, center);
		iterathor++;
	}
	return (*src);
}
