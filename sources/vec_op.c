/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 13:51:20 by hsabouri          #+#    #+#             */
/*   Updated: 2018/04/29 12:30:16 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "vec.h"
#include <math.h>

t_vec4	vec_add(t_vec4 left, t_vec4 right)
{
	t_vec4	res;

	res.x = left.x * left.w + right.x * right.w;
	res.y = left.y * left.w + right.y * right.w;
	res.z = left.z * left.w + right.z * right.w;
	res.w = 1;
	return (normalize(res));
}

t_vec4	vec_sub(t_vec4 left, t_vec4 right)
{
	t_vec4	res;

	res.x = left.x * left.w - right.x * right.w;
	res.y = left.y * left.w - right.y * right.w;
	res.z = left.z * left.w - right.z * right.w;
	res.w = 1;
	return (normalize(res));
}

t_vec4	vec_mult(t_vec4 src, GLfloat scalar)
{
	t_vec4	res;

	res = src;
	if (scalar > EPSILON)
		res.w = res.w * scalar;
	else
	{
		res.w = res.w * (-scalar);
		res.x = -res.x;
		res.y = -res.y;
		res.z = -res.z;
	}
	return (res);
}

GLfloat	vec_dot(t_vec4 left, t_vec4 right)
{
	return (left.x * left.w * right.x * right.w +
			left.y * left.w * right.y * right.w +
			left.z * left.w * right.z * right.w);
}

t_vec4	vec_rot(t_vec4 vec, t_axis axis, GLfloat amount)
{
	if (axis == X)
		return (x_axis(vec, amount));
	else if (axis == Y)
		return (y_axis(vec, amount));
	else
		return (z_axis(vec, amount));
}
