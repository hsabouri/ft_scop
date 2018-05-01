/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 13:51:20 by hsabouri          #+#    #+#             */
/*   Updated: 2018/04/30 14:01:58 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "vec.h"
#include <math.h>

t_vec4	vec_add(t_vec4 left, t_vec4 right)
{
	t_vec4 res;

	res = left;
	res.x = left.x + right.x;
	res.y = left.y + right.y;
	res.z = left.z + right.z;
	res.w = left.w + right.w;
	return (res);
}

t_vec4	vec_sub(t_vec4 left, t_mat4 right)
{
	t_vec4 res;

	res = left;
	res.x = left.x + right.x;
	res.y = left.y + right.y;
	res.z = left.z + right.z;
	res.w = left.w + right.w;
	return (res);
}

t_vec4	vec_mult(t_vec4 l, t_mat4 r)
{
	t_vec4	d;

	d.x = l.x * r.x + l.y * r.x1 + l.z * r.x2 + l.w * r.x3;
	d.y = l.x * r.y0 + l.y * r.y + l.z * r.y2 + l.w * r.y3;
	d.z = l.x * r.z0 + l.y * r.z1 + l.z * r.z + l.w * r.z3;
	d.w = l.x * r.w0 + l.y * r.w1 + l.z * r.w2 + l.w * r.w;
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

t_vec4	vec_trans(t_vec4 vec, GLfloat x, GLfloat y, GLfloat z)
{
	const t_mat4	translation_matrice = mat_new(x, y, z, 1);

	return (vec_mult(vec, translation_matrice));
}
