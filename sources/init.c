/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 11:08:53 by hsabouri          #+#    #+#             */
/*   Updated: 2018/05/06 16:13:44 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_scop.h"

void		init_version(void)
{
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

char		*get_shader_str(const char *path)
{
	int			fd;
	struct stat	info;
	GLchar		*str;

	if (stat(path, &info))
		error("FILESYSTEM", "Could not access file.");
	if ((fd = open(path, O_RDONLY)) < 0)
		error("FILESYSTEM", "Could not open file.");
	if ((str = ft_strnew(info.st_size)) == NULL)
		error("MALLOC", "Could not allocate memory.");
	if (read(fd, str, info.st_size) <= 0)
		error("FILESYSTEM", "Could not read file or empty file.");
	return (str);
}

GLuint	init_shader(const char *path, GLenum type)
{
	GLint	err;
	GLuint	shader_id;
	GLchar	*shader_str;

	shader_str = get_shader_str(path);
	if ((shader_id = glCreateShader(type)) == 0)
		error("OPENGL", "Could not create shader.");
	glShaderSource(shader_id, 1, (const GLchar *const *)&shader_str, NULL);
	glCompileShader(shader_id);
	free(shader_str);
	glGetShaderiv(shader_id, GL_COMPILE_STATUS, &err);
	if (err != GL_TRUE)
	{
		//REMOVE
		GLint logsize = 0;
		glGetShaderiv(shader_id, GL_INFO_LOG_LENGTH, &logsize);
		GLchar *str = (GLchar *)malloc(sizeof(GLchar) * logsize);
		glGetShaderInfoLog(shader_id, logsize, &logsize, str);
		ft_putendl(str);
		error("OPENGL", "Could not compile shader.");
	}
	return (shader_id);
}

GLuint	init_program(void)
{
	GLuint vertex;
	GLuint fragment;
	GLuint program;

	vertex = init_shader("./shaders/test.glslv", GL_VERTEX_SHADER);
	fragment = init_shader("./shaders/test.glslf", GL_FRAGMENT_SHADER);
	program = glCreateProgram();
	glAttachShader(program, vertex);
	glAttachShader(program, fragment);
	glLinkProgram(program);
	return (program);
}

t_env	*init_buffers(t_env *env)
{
	GLint	err;
	GLint	col_loc;
	GLint	pos_loc;
	GLint	tex_loc;

	glGenVertexArrays(1, &env->vao_id);
	glBindVertexArray(env->vao_id);
	glGenBuffers(1, &env->vb_id);
	glBindBuffer(GL_ARRAY_BUFFER, env->vb_id);
	glBufferData(GL_ARRAY_BUFFER, sizeof(t_vec4) * env->vertices.size,\
		env->vertices.content, GL_STATIC_DRAW);
	pos_loc = glGetAttribLocation(env->program, "vPos");
	col_loc = glGetAttribLocation(env->program, "vCol");
	tex_loc = glGetAttribLocation(env->program, "vTex");
	printf("pos: %d - col: %d\n", pos_loc, col_loc);
    glEnableVertexAttribArray(pos_loc);
    glVertexAttribPointer(pos_loc, 4, GL_FLOAT, GL_FALSE,
                          sizeof(t_vec4), (void*) 0);
    glEnableVertexAttribArray(col_loc);
    glVertexAttribPointer(col_loc, 4, GL_FLOAT, GL_FALSE,
                          sizeof(t_vec4), (void*) (sizeof(GLfloat) * 4));
    glEnableVertexAttribArray(tex_loc);
    glVertexAttribPointer(tex_loc, 2, GL_FLOAT, GL_FALSE,
                          sizeof(t_vec4), (void*) (sizeof(GLfloat) * 8));
	err = glGetError();
	if (err != GL_NO_ERROR)
	{
		printf("error : %d\n", err);
		error("OPENGL", "Could not allocate memory.");
	}
	return (env);
}
