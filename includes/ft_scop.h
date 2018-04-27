/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scop.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 11:19:46 by hsabouri          #+#    #+#             */
/*   Updated: 2018/04/27 18:52:31 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  FT_SCOP
# define FT_SCOP

# ifdef OSX
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


typedef struct	s_triangles
{
	t_tri		*content;
	size_t		size;
}				t_triangles;

int				error(const char *error_type, const char *to_display);
int				error_line(const size_t line, const char *error_type,\
				const char *to_display);
void			init_version(void);
GLuint			init_program(void);
void			init_buffers(GLuint *vbo);
void			set_error_callbacks(void);
void			set_callbacks(GLFWwindow *win);
t_triangles		triangulate(t_parsed *parsed);
void			assign_color(t_triangles *iba);

#endif
