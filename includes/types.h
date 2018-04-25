/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 16:48:30 by hsabouri          #+#    #+#             */
/*   Updated: 2018/04/25 19:32:43 by hsabouri         ###   ########.fr       */
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

typedef struct	s_vertex
{
	t_vec4	pos;
	t_color	col;
}				t_vertex;

typedef struct	s_tri
{
	int a;
	int b;
	int c;
}				t_tri;

#endif
