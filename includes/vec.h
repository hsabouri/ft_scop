/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 12:11:38 by hsabouri          #+#    #+#             */
/*   Updated: 2018/04/28 16:05:28 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	MATH_H
# define MATH_H

# include "types.h"

# define EPSILON 0.000000119f

t_vec4		normalize(t_vec4 src);
t_vec4		vec_sub(t_vec4 left, t_vec4 right);
t_vec4		vec_add(t_vec4 left, t_vec4 right);
t_vec4		vec_mult(t_vec4 src, GLfloat scalar);
GLfloat		vec_dot(t_vec4 left, t_vec4 right);

#endif
