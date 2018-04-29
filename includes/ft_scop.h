/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scop.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 11:19:46 by hsabouri          #+#    #+#             */
/*   Updated: 2018/04/29 12:00:58 by hsabouri         ###   ########.fr       */
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
# include "vec.h"
# include <math.h>

int				error(const char *error_type, const char *to_display);
int				error_line(const size_t line, const char *error_type,\
				const char *to_display);
void			init_version(void);
GLuint			init_program(void);
void			init_buffers(GLuint *vbo);
void			set_error_callbacks(void);
void			set_callbacks(GLFWwindow *win);
t_tris			triangulate(t_parsed *parsed);
void			assign_color(t_tris *iba);
t_vertices		normalize_all(t_vertices *src);
t_vec4			find_center(t_vertices *buf);
t_vertices		center(t_vertices *src);
t_color			get_color(t_color start, t_color end, int pos, int max);

#endif
