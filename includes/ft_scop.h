/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scop.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 11:19:46 by hsabouri          #+#    #+#             */
/*   Updated: 2018/05/02 18:30:55 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  FT_SCOP
# define FT_SCOP

# ifdef __APPLE__
#  include <OpenGL/gl3.h>
#  define GLFW_INCLUDE_NONE
# endif
# include <GLFW/glfw3.h>

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>

# include "parser.h"
# include "types.h"
# include "vec.h"
# include <math.h>

typedef struct	s_env
{
	GLuint		vao_id;
	GLuint		vb_id;
	GLuint		ib_id;
	t_vertices	vertices;
	t_tris		indexes;
	GLFWwindow	*win;
	GLuint		program;
}				t_env;

int			error(const char *error_type, const char *to_display);
int			error_line(const size_t line, const char *error_type,\
			const char *to_display);
void		init_version(void);
GLuint		init_program(void);
t_env		*init_buffers(t_env *env);
void		set_error_callbacks(void);
void		set_callbacks(GLFWwindow *win);
t_tris		triangulate(t_parsed *parsed);
t_vertices	normalize_all(t_vertices *src);
t_vec4		find_center(t_vertices *buf);
t_env		assign_color(t_env *env);
t_vertices	center(t_vertices *src);
t_vertices	translate(t_vertices *src, GLfloat x, GLfloat y, GLfloat z);
t_vertices	scale(t_vertices *src, GLfloat amount);
t_vertices	rotate(t_vertices *src, t_axis axis, GLfloat amount);
t_env		expend(t_env *env);
t_color		get_color(t_color start, t_color end, int pos, int max);

#endif
