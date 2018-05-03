/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_basic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 10:37:02 by hsabouri          #+#    #+#             */
/*   Updated: 2018/05/03 18:41:34 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_scop.h"

typedef union	u_mem_rape
{
	GLint	tmp;
	GLfloat	side;
}				t_mem_rape;

t_mat4	mat_new(GLfloat x, GLfloat y, GLfloat z, GLfloat w)
{
	return ((t_mat4){1, 0, 0, 0,
			 		 0, 1, 0, 0,
			 		 0, 0, 1, 0,
			 		 x, y, z, w});
}

t_vec4	vec_new(GLfloat x, GLfloat y, GLfloat z, GLfloat w)
{
	return ((t_vec4) {x, y, z, w, (t_color) {0, 0, 0, 1}});
}

GLfloat	ft_sqrt(GLfloat src)
{
	t_mem_rape		res;
	const GLint		magic = -0x4C000;
	const GLfloat	half = 0.5f;

	res.side = src;
	res.tmp = (1 << 29) + (res.tmp >> 1) - (1 << 22) + magic;
	res.side = half * (res.side + src / res.side);
	res.side = half * (res.side + src / res.side);
	res.side = half * (res.side + src / res.side);
	return (res.side);
}

t_vec4	normalize(t_vec4 src)
{
	t_vec4	res;
	GLfloat	norme;
	
	res.x = src.x * src.w;
	res.y = src.y * src.w;
	res.z = src.z * src.w;
	norme = ft_sqrt(res.x * res.x + res.y * res.y + res.z * res.z);
	res.x = res.x / norme;
	res.y = res.y / norme;
	res.z = res.z / norme;
	res.w = norme;
	return (res);
}

t_vec4	vec_uniform_scale(t_vec4 vec, GLfloat amount)
{
	return (vec_mult(vec, MAT_UNIT(amount)));
}

t_mat4	get_rot_mat(t_axis axis, GLfloat amount)
{
	const GLfloat	sin_t = sin(amount);
	const GLfloat	cos_t = cos(amount);

	if (axis == X)
		return (ROTX(sin_t, cos_t));
	else if (axis == Y)
		return (ROTY(sin_t, cos_t));
	else
		return (ROTZ(sin_t, cos_t));

}

t_mat4	get_proj_mat(GLfloat ratio, GLfloat fovy, GLfloat near, GLfloat far)
{
	const GLfloat	yscale = 1 / (fovy / 2);
	const GLfloat	xscale = yscale / ratio;
	const GLfloat	frustum = far - near;

	return ((t_mat4) {\
		xscale, 0.0, 0.0, 0.0,\
		0.0, yscale, 0.0, 0.0,\
		0.0, 0.0, -((far + near) / frustum), -1.0,\
		0.0, 0.0, -((2 * near * far) / frustum), 0.0});
}
