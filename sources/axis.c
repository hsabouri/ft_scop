/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   axis.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/29 12:07:51 by hsabouri          #+#    #+#             */
/*   Updated: 2018/05/13 18:48:40 by oadib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include <math.h>

t_vec4	z_axis(t_vec4 vec, GLfloat amount)
{
	const GLfloat	sin_t = sin(amount);
	const GLfloat	cos_t = cos(amount);
	t_vec4			res;

	res = vec;
	res.x = vec.x * cos_t - vec.y * sin_t;
	res.y = vec.x * sin_t + vec.y * cos_t;
	return (res);
}

t_vec4	y_axis(t_vec4 vec, GLfloat amount)
{
	const GLfloat	sin_t = sin(amount);
	const GLfloat	cos_t = cos(amount);
	t_vec4			res;

	res = vec;
	res.x = vec.x * cos_t + vec.z * sin_t;
	res.z = -vec.x * sin_t + vec.z * cos_t;
	return (res);
}

t_vec4	x_axis(t_vec4 vec, GLfloat amount)
{
	const GLfloat	sin_t = sin(amount);
	const GLfloat	cos_t = cos(amount);
	t_vec4			res;

	res = vec;
	res.y = vec.y * cos_t - vec.z * sin_t;
	res.z = vec.y * sin_t + vec.z * cos_t;
	return (res);
}
