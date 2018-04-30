/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 16:48:30 by hsabouri          #+#    #+#             */
/*   Updated: 2018/04/30 13:42:37 by hsabouri         ###   ########.fr       */
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
# define MATX 0
# define MATY 5
# define MATZ 10
# define MATW 15

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

typedef struct	s_vec4
{
	GLfloat x;
	GLfloat x1;
	GLfloat x2;
	GLfloat x3;

	GLfloat y0;
	GLfloat y;
	GLfloat y2;
	GLfloat y3;

	GLfloat z0;
	GLfloat z1;
	GLfloat z;
	GLfloat z3;

	GLfloat w0;
	GLfloat w1;
	GLfloat w2;
	GLfloat w;
}				t_vec4;

typedef struct	s_color
{
	GLfloat r;
	GLfloat g;
	GLfloat b;
	GLfloat a;
}				t_color;

typedef struct	s_colors
{
	t_color	*content;
	size_t	size;
}				t_colors;

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
