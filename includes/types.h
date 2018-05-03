/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 16:48:30 by hsabouri          #+#    #+#             */
/*   Updated: 2018/05/03 18:09:41 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  TYPES
# define TYPES

# ifdef OSX
#  include <OpenGL/gl3.h>
#  define GLFW_INCLUDE_NONE
# endif
# include <GLFW/glfw3.h>

# define MATSIZE 16

typedef enum	e_axis
{
	X,
	Y,
	Z
}				t_axis;

typedef struct	s_tex2
{
	GLfloat u;
	GLfloat v;
}				t_tex2;

typedef struct	s_mat4
{
	GLfloat x;
	GLfloat y0;
	GLfloat z0;
	GLfloat w0;
	GLfloat x1;
	GLfloat y;
	GLfloat z1;
	GLfloat w1;
	GLfloat x2;
	GLfloat y2;
	GLfloat z;
	GLfloat w2;
	GLfloat x3;
	GLfloat y3;
	GLfloat z3;
	GLfloat w;
}				t_mat4;

typedef struct	s_color
{
	GLfloat r;
	GLfloat g;
	GLfloat b;
	GLfloat a;
}				t_color;

typedef struct	s_vec4
{
	GLfloat x;
	GLfloat y;
	GLfloat z;
	GLfloat w;
	t_color	color;
}				t_vec4;

typedef struct	s_quad
{
	int a;
	int b;
	int c;
	int d;
}				t_quad;

typedef struct	s_tri
{
	GLuint	a;
	GLuint	b;
	GLuint	c;
}				t_tri;

typedef struct	s_vertices
{
	t_vec4		*content;
	size_t		size;
}				t_vertices;

typedef struct	s_tris
{
	t_tri		*content;
	size_t		size;
}				t_tris;

#endif
