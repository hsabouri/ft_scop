/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 13:46:12 by hsabouri          #+#    #+#             */
/*   Updated: 2018/05/04 19:17:02 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "vec.h"

static t_vec4	compare_sub(t_vec4 dst, t_vec4 current)
{
	if (dst.x > current.x * current.w)
		dst.x = current.x * current.w;
	if (dst.y > current.y * current.w)
		dst.y = current.y * current.w;
	if (dst.z > current.z * current.w)
		dst.z = current.z * current.w;
	return (dst);
}

static t_vec4	compare_over(t_vec4 dst, t_vec4 current)
{
	if (dst.x < current.x * current.w)
		dst.x = current.x * current.w;
	if (dst.y < current.y * current.w)
		dst.y = current.y * current.w;
	if (dst.z < current.z * current.w)
		dst.z = current.z * current.w;
	return (dst);
}

t_vec4			find_center(t_vertices *buf)
{
	size_t	iterator;
	t_vec4	current;
	t_vec4	res;
	t_vec4	top;
	t_vec4	bottom;

	current = buf->content[0];
	top = vec_new(0, 0, 0, 0);
	top.x = current.x * current.w;
	top.y = current.y * current.w;
	top.z = current.z * current.w;
	bottom = top;
	iterator = 1;
	while (iterator < buf->size)
	{
		current = buf->content[iterator];
		top = compare_over(top, current);
		bottom = compare_sub(bottom, current);
		iterator++;
	}
	res = vec_new(0, 0, 0, 0);
	res.x = (top.x + bottom.x) / 2;
	res.y = (top.y + bottom.y) / 2;
	res.z = (top.z + bottom.z) / 2;
	return (res);
}
