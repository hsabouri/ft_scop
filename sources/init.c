/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 11:08:53 by hsabouri          #+#    #+#             */
/*   Updated: 2018/04/27 13:00:56 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_scop.h"

void			init_version(void)
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

void	init_buffers(GLuint *vbo) {
	/*
	t_vertex	vertices[6] = {
		{{-0.5f, 0.5f, 0.0f, 1.0f}, {0.0f, 0.0f, 1.0f, 1.0f}},
		{{0.5f, 0.5f, 0.0f, 1.0f}, {1.0f, 0.0f, 0.0f, 1.0f}},
		{{0.0f, -0.5f, 0.0f, 1.0f}, {0.0f, 1.0f, 0.0f, 1.0f}},
		{{-0.5f, -0.5f, 0.0f, 1.0f}, {1.0f, 0.0f, 1.0f, 1.0f}},
		{{0.5f, -0.5f, 0.0f, 1.0f}, {0.0f, 1.0f, 1.0f, 1.0f}},
		{{0.0f, 0.5f, 0.0f, 1.0f}, {1.0f, 1.0f, 0.0f, 1.0f}},
	};
	GLubyte		indices[] = {
		0, 3, 2,
		1, 4, 5
	};
	GLuint			vao;
	GLuint			ibi;
	GLint			err;
	const size_t	offset = sizeof(t_vec4);


	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glGenBuffers(1, vbo);
	glBindBuffer(GL_ARRAY_BUFFER, *vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(t_vertex), 0);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(t_vertex), NULL + offset);

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

	glGenBuffers(1, &ibi);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibi);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	err = glGetError();
	if (err != GL_NO_ERROR)
		error("OPENGL", "Could not create VBO");
	*/
}
