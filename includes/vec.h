/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 12:11:38 by hsabouri          #+#    #+#             */
/*   Updated: 2018/05/13 19:19:26 by oadib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_H
# define VEC_H
# include "types.h"
# define EPSILON 0.000000119f
# define ROTX(SIN, COS) (t_mat4){\
	1, 0, 0, 0,\
	0, COS, SIN, 0,\
	0, -SIN, COS, 0,\
	0, 0, 0, 1}
# define ROTY(SIN, COS) (t_mat4){\
	COS, 0, -SIN, 0,\
	0, 1, 0, 0,\
	SIN, 0, COS, 0,\
	0, 0, 0, 1}
# define ROTZ(SIN, COS) (t_mat4){\
	COS, SIN, 0, 0, \
	-SIN, COS, 0, 0,\
	0, 0, 1, 0,\
	0, 0, 0, 1}
# define MAT_UNIT(s) (t_mat4){s, 0, 0, 0, 0, s, 0, 0, 0, 0, s, 0, 0, 0, 0, 1}

typedef union	u_mem_rape
{
	GLint	tmp;
	GLfloat	side;
}				t_mem_rape;

t_vec4			normalize(t_vec4 src);
t_vec4			vec_new(GLfloat x, GLfloat y, GLfloat z, GLfloat w);
t_mat4			mat_new(GLfloat x, GLfloat y, GLfloat z, GLfloat w);
t_vec4			vec_sub(t_vec4 left, t_mat4 right);
t_vec4			vec_add(t_vec4 left, t_vec4 right);
t_vec4			vec_mult(t_vec4 left, t_mat4 right);
t_vec4			vec_rot(t_vec4 vec, t_axis axis, GLfloat amount);
t_vec4			vec_trans(t_vec4 vec, GLfloat x, GLfloat y, GLfloat z);
t_vec4			vec_uniform_scale(t_vec4 vec, GLfloat amount);

t_vec4			x_axis(t_vec4 vec, GLfloat amount);
t_vec4			y_axis(t_vec4 vec, GLfloat amount);
t_vec4			z_axis(t_vec4 vec, GLfloat amount);

t_mat4			get_rot_mat(t_axis axis, GLfloat amount);
t_mat4			mat_mult(t_mat4 l, t_mat4 r);

void			display_vec(t_vec4 vec);

#endif
