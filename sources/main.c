/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 11:22:10 by hsabouri          #+#    #+#             */
/*   Updated: 2018/04/29 12:32:53 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_scop.h"

void	update(GLFWwindow *win, GLuint program)
{
	int width;
	int height;

	glfwGetFramebufferSize(win, &width, &height);
	glViewport(0, 0, width, height);
	glClear(GL_COLOR_BUFFER_BIT);
	glUseProgram(program);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_BYTE, NULL + 0);
	glfwSwapBuffers(win);
	glfwPollEvents();

	GLuint err = glGetError();
	if (err != GL_NO_ERROR)
	{
		ft_putnbr_fd(err, STDERR_FILENO);
		ft_putendl_fd("", STDERR_FILENO);
	}
}

GLFWwindow	*init(void)
{
	GLFWwindow	*win;

	if (!glfwInit())
		error("GLFW", "Failed to initialize glfw");
	init_version();
	win = glfwCreateWindow(640, 480, "ft_scop", NULL, NULL);
	if (!win)
		error("GLFW", "Failed to initilize window.");
	return (win);
}

int			main(int ac, char **av)
{
	t_parsed	parsed;
	t_tris		iba;
	t_vertices	vbo;
	t_colors	cbo;
	GLFWwindow	*win;
	GLuint		program;

	if (ac >= 2)
		parsed = parse(av[1]);
	else
		error("usage", "ft_scop file.obj");
	verify(&parsed);
	iba = triangulate(&parsed);
	cbo = assign_color(&iba);
	vbo = center(&(parsed.vertices));
	vbo = scale(&(parsed.vertices), 0.5f);
	vbo = rotate(&(parsed.vertices), Z, M_PI / 2.5);
	vbo = rotate(&(parsed.vertices), Y, M_PI / 4);
	set_error_callbacks();
	win = init();
	set_callbacks(win);
	glfwMakeContextCurrent(win);
	glfwSwapInterval(1);
	program = init_program();
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	init_buffers(vbo, cbo, iba);
	while (!glfwWindowShouldClose(win))
	{
		update(win, program);
	}
	glfwDestroyWindow(win);
	glfwTerminate();
	return (0);
}
