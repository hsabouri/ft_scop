/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 13:51:20 by hsabouri          #+#    #+#             */
/*   Updated: 2018/04/30 12:11:33 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "vec.h"
#include <math.h>

t_vec4	vec_new(void)
{
	return ((t_vec4){1, 0, 0, 0,
			 0, 1, 0, 0,
			 0, 0, 1, 0,
			 0, 0, 0, 1});
}

t_vec4	vec_add(t_vec4 left, t_vec4 right)
{
	t_vec4	res;
	GLfloat	*res_t;
	GLfloat	*left_t;
	GLfloat	*right_t;
	size_t	i;

	i = 0;
	res_t = (GLfloat *)&res;
	left_t = (GLfloat *)&left;
	right_t = (GLfloat *)&right;
	while (i < MATSIZE)
	{
		res_t[i] = left_t[i] + right_t[i];
		i++;
	}
	return (res);
}

t_vec4	vec_sub(t_vec4 left, t_vec4 right)
{
	t_vec4	res;
	GLfloat	*res_t;
	GLfloat	*left_t;
	GLfloat	*right_t;
	size_t	i;

	i = 0;
	res_t = (GLfloat *)&res;
	left_t = (GLfloat *)&left;
	right_t = (GLfloat *)&right;
	while (i < MATSIZE)
	{
		res_t[i] = left_t[i] - right_t[i];
		i++;
	}
	return (res);
}

t_vec4	vec_mult(t_vec4 l, t_vec4 r)
{
	t_vec4	d;

	d.x = l.x * r.x +   l.x1 * r.y0 + l.x2 * r.z0 + l.x3 * r.w0;
	d.x1 = l.x * r.x1 + l.x1 * r.y +  l.x2 * r.z1 + l.x3 * r.w1;
	d.x2 = l.x * r.x2 + l.x1 * r.y2 + l.x2 * r.z +  l.x3 * r.w2;
	d.x3 = l.x * r.x3 + l.x1 * r.y3 + l.x2 * r.z3 + l.y3 * r.w;
	d.y0 = l.y0 * r.x +  l.y * r.y0 + l.y2 * r.z0 + l.y3 * r.w0;
	d.y = l.y0 * r.x1 +  l.y * r.y +  l.y2 * r.z1 + l.y3 * r.w1;
	d.y2 = l.y0 * r.x2 + l.y * r.y2 + l.y2 * r.z +  l.y3 * r.w2;
	d.y3 = l.y0 * r.x3 + l.y * r.y3 + l.y2 * r.z3 + l.z3 * r.w;
	d.z0 = l.z0 * r.x +  l.z1 * r.y0 + l.z * r.z0 + l.z3 * r.w0;
	d.z1 = l.z0 * r.x1 + l.z1 * r.y +  l.z * r.z1 + l.z3 * r.w1;
	d.z = l.z0 * r.x2 +  l.z1 * r.y2 + l.z * r.z +  l.z3 * r.w2;
	d.z3 = l.z0 * r.x3 + l.z1 * r.y3 + l.z * r.z3 + l.z3 * r.w;
	d.w0 = l.w0 * r.x +  l.w1 * r.y0 + l.w2 * r.z0 + l.w * r.w0;
	d.w1 = l.w0 * r.x1 + l.w1 * r.y +  l.w2 * r.z1 + l.w * r.w1;
	d.w2 = l.w0 * r.x2 + l.w1 * r.y2 + l.w2 * r.z +  l.w * r.w2;
	d.w = l.w0 * r.x3 +  l.w1 * r.y3 + l.w2 * r.z3 + l.w * r.w;
	return (d);
}

t_vec4	vec_rot(t_vec4 vec, t_axis axis, GLfloat amount)
{
	const GLfloat	sin_t = sin(amount);
	const GLfloat	cos_t = cos(amount);

	if (axis == X)
		return (vec_mult(vec, ROTX(sin_t, cos_t)));
	else if (axis == Y)
		return (vec_mult(vec, ROTY(sin_t, cos_t)));
	else
		return (vec_mult(vec, ROTZ(sin_t, cos_t)));
}
