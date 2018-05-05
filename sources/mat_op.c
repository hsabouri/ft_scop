/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 10:37:02 by hsabouri          #+#    #+#             */
/*   Updated: 2018/05/05 11:40:55 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_scop.h"

t_mat4	get_proj_mat(GLfloat ratio, GLfloat fovy, GLfloat near, GLfloat far)
{
	const GLfloat	yscale = 1 / (fovy / 2);
	const GLfloat	xscale = yscale / ratio;
	const GLfloat	frustum = far - near;

	return ((t_mat4) {\
		xscale, 0.0, 0.0, 0.0,\
		0.0, yscale, 0.0, 0.0,\
		0.0, 0.0, -((far + near) / frustum), -1.0,\
		0.0, 0.0, -((2 * near * far) / frustum) - 1, 0.0});
}

t_mat4	mat_mult(t_mat4 l, t_mat4 r)
{
	t_mat4 res;

	res.x =  l.x * r.x +  l.x1 * r.y0 + l.x2 * r.z0 + l.x3 * r.w0;
	res.x1 = l.x * r.x1 + l.x1 * r.y +  l.x2 * r.z1 + l.x3 * r.w1;
	res.x2 = l.x * r.x2 + l.x1 * r.y2 + l.x2 * r.z +  l.x3 * r.w2;
	res.x3 = l.x * r.x3 + l.x1 * r.y3 + l.x2 * r.z3 + l.x3 * r.w;
	res.y0 = l.y0 * r.x +  l.y * r.y0 + l.y2 * r.z0 + l.y3 * r.w0;
	res.y =  l.y0 * r.x1 + l.y * r.y +  l.y2 * r.z1 + l.y3 * r.w1;
	res.y2 = l.y0 * r.x2 + l.y * r.y2 + l.y2 * r.z +  l.y3 * r.w2;
	res.y3 = l.y0 * r.x3 + l.y * r.y3 + l.y2 * r.z3 + l.y3 * r.w;
	res.z0 = l.z0 * r.x +  l.z1 * r.y0 + l.z * r.z0 + l.z3 * r.w0;
	res.z1 = l.z0 * r.x1 + l.z1 * r.y +  l.z * r.z1 + l.z3 * r.w1;
	res.z =  l.z0 * r.x2 + l.z1 * r.y2 + l.z * r.z +  l.z3 * r.w2;
	res.z3 = l.z0 * r.x3 + l.z1 * r.y3 + l.z * r.z3 + l.z3 * r.w;
	res.w0 = l.w0 * r.x +  l.w1 * r.y0 + l.w2 * r.z0 + l.w * r.w0;
	res.w1 = l.w0 * r.x1 + l.w1 * r.y +  l.w2 * r.z1 + l.w * r.w1;
	res.w2 = l.w0 * r.x2 + l.w1 * r.y2 + l.w2 * r.z +  l.w * r.w2;
	res.w =  l.w0 * r.x3 + l.w1 * r.y3 + l.w2 * r.z3 + l.w * r.w;
	return (res);
}
