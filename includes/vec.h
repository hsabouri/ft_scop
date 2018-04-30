/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 12:11:38 by hsabouri          #+#    #+#             */
/*   Updated: 2018/04/30 14:02:22 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	MATH_H
# define MATH_H

# include "types.h"

# define EPSILON 0.000000119f
# define ROTX(SIN, COS) (t_vec4) {1, 0, 0, 0, \
				  0, COS, -SIN, 0,\
				  0, SIN, COS, 0,\
				  0, 0, 0, 1}
# define ROTY(SIN, COS) (t_vec4) {COS, 0, SIN, 0, \
				  0, 1, 0, 0,\
				  -SIN, 0, COS, 0,\
				  0, 0, 0, 1}
# define ROTZ(SIN, COS) (t_vec4) {COS, -SIN, 0, 0, \
				  SIN, COS, 0, 0,\
				  0, 0, 1, 0,\
				  0, 0, 0, 1}

t_vec4		normalize(t_vec4 src);
t_vec4		vec_sub(t_vec4 left, t_vec4 right);
t_vec4		vec_add(t_vec4 left, t_vec4 right);
t_vec4		vec_mult(t_vec4 left, t_vec4 right);
GLfloat		vec_dot(t_vec4 left, t_vec4 right);
t_vec4		vec_rot(t_vec4 vec, t_axis axis, GLfloat amount);

t_vec4	x_axis(t_vec4 vec, GLfloat amount);
t_vec4	y_axis(t_vec4 vec, GLfloat amount);
t_vec4	z_axis(t_vec4 vec, GLfloat amount);

#endif
