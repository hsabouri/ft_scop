/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scop.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 11:19:46 by hsabouri          #+#    #+#             */
/*   Updated: 2018/05/14 11:29:55 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SCOP_H
# define FT_SCOP_H
# ifdef __APPLE__
#  include <OpenGL/gl3.h>
#  define GLFW_INCLUDE_NONE
# else
#  include <glad/glad.h>
# endif
# include <GLFW/glfw3.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include "parser.h"
# include "types.h"
# include "vec.h"
# include "tga.h"
# include <math.h>
# include <time.h>
# include <stdlib.h>
# define YELLOW (t_color) {btof(244), btof(202), btof(78), 1.0}
# define RED (t_color) {btof(224), btof(26), btof(59), 1.0}
# define BLUE (t_color) {btof(88), btof(4), btof(255), 1.0}
# define BLACK (t_color) {0.0, 0.0, 0.0, 1.0}
# define WHITE (t_color) {1.0, 1.0, 1.0, 1.0}
# define COLOR(a, b, c) (t_color) {btof(a), btof(b), btof(c), 1.0}
# define ROT_SPEED M_PI/128

# ifdef __APPLE__
#  define GLADloadproc void*
#  define gladLoadGLLoader(addr) (void)addr
# endif

typedef struct	s_update
{
	t_mat4		proj_mat;
	t_mat4		view_mat;
	t_mat4		model_mat;
	t_color		start;
	t_color		end;
	int			width;
	int			height;
}				t_update;

typedef struct	s_loc
{
	GLuint		view;
	GLuint		model;
	GLuint		proj;
	GLuint		start;
	GLuint		end;
	GLuint		state;
	GLuint		texture_mode;
}				t_loc;

typedef struct	s_states
{
	t_vec2		rot;
	t_vec4		view;
	t_vec4		model;
	t_vec4		colors;
	int			color_mov;
	int			texture_mod;
}				t_states;

typedef struct	s_env
{
	GLuint		vao_id;
	GLuint		vb_id;
	GLuint		ib_id;
	t_loc		loc;
	t_vertices	vertices;
	t_tris		indexes;
	GLFWwindow	*win;
	GLuint		program;
	t_img		image;
	GLuint		texture;
	int			*k_states;
	t_states	states;
}				t_env;

t_env			*ft_get_env(void);
t_env			*init_env(const char *obj_path, const char *tga_path);
GLFWwindow		*init_window(void);
void			update(t_env *env);
void			key_callback(GLFWwindow *win, int key, int scancode,\
				int act, int mods);
t_env			*key_actions(t_env *env);
int				error(const char *error_type, const char *to_display);
int				error_line(const size_t line, const char *error_type,\
				const char *to_display);
GLuint			init_program(void);
t_env			*init_buffers(t_env *env);
t_env			*init_textures(t_env *env);
t_env			*init_uniforms(t_env *env);
void			set_error_callbacks(void);
void			set_callbacks(GLFWwindow *win);
t_tris			triangulate(t_parsed *parsed);
t_vertices		normalize_all(t_vertices *src);
t_vec4			find_center(t_vertices *buf);
t_env			assign_color(t_env *env);
t_env			assign_texture_coords(t_env *env);
t_vertices		center(t_vertices *src);
t_vertices		translate(t_vertices *src, GLfloat x, GLfloat y, GLfloat z);
t_vertices		scale(t_vertices *src, GLfloat amount);
t_vertices		rotate(t_vertices *src, t_axis axis, GLfloat amount);
t_vertices		reduce(t_vertices *vertices);
t_env			expend(t_env *env);
t_color			get_color(t_color start, t_color end, int pos, int max);
t_mat4			get_proj_mat(GLfloat ratio, GLfloat alpha, GLfloat near,\
				GLfloat far);

float			btof(unsigned char n);

#endif
