/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 16:48:30 by hsabouri          #+#    #+#             */
/*   Updated: 2018/04/27 14:38:43 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  TYPES
# define TYPES

# ifdef OSX
#  include <OpenGL/gl3.h>
#  define GLFW_INCLUDE_NONE
# endif
# include <GLFW/glfw3.h>

typedef struct	s_tex2
{
	GLfloat u;
	GLfloat v;
}				t_tex2;

typedef struct	s_vec4
{
	GLfloat x;
	GLfloat y;
	GLfloat z;
	GLfloat w;
}				t_vec4;

typedef struct	s_color
{
	GLfloat r;
	GLfloat g;
	GLfloat b;
	GLfloat a;
}				t_color;

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
	t_color	col;
}				t_tri;

typedef struct	s_tris
{
	t_tri		*tris;
	size_t		size;
}				t_tris;

#endif
