/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 11:22:10 by hsabouri          #+#    #+#             */
/*   Updated: 2018/04/24 11:05:35 by hsabouri         ###   ########.fr       */
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

int main(int ac, char **av)
{
	if (ac >= 2)
		parse(av[1]);
	/*
	GLFWwindow	*win;
	GLuint		vbo;
	GLuint		program;

	if (!glfwInit())
		error("GLFW", "Failed to initilize.");
	set_error_callbacks();
	init_version();
	win = glfwCreateWindow(640, 480, "ft_scop", NULL, NULL);
	if (!win) error("GLFW", "Failed to initilize window.");
	set_callbacks(win);
	glfwMakeContextCurrent(win);
	glfwSwapInterval(1);
	program = init_program();
	init_buffers(&vbo);
	while (!glfwWindowShouldClose(win))
	{
		update(win, program);
	}
	glfwDestroyWindow(win);
	glfwTerminate();
	*/
	return (0);
}
