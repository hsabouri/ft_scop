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

void	update(t_env *env)
{
	int width;
	int height;

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, env->vb_id);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, NULL);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, env->ib_id);

	glfwGetFramebufferSize(env->win, &width, &height);
	glViewport(0, 0, width, height);
	glClear(GL_COLOR_BUFFER_BIT);
	glUseProgram(env->program);
	glDrawElements(GL_TRIANGLES, env->indexes.size, GL_UNSIGNED_INT, NULL + 0);
	glfwSwapBuffers(env->win);
	glfwPollEvents();

	glDisableVertexAttribArray(0);
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
	t_env		env;

	if (ac >= 2)
		parsed = parse(av[1]);
	else
		error("usage", "ft_scop file.obj");
	verify(&parsed);
	set_error_callbacks();
	env.win = init();
	set_callbacks(env.win);
	glfwMakeContextCurrent(env.win);
	glfwSwapInterval(1);
	env.program = init_program();
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	env.indexes = triangulate(&parsed);
	env.colors = assign_color(&env.indexes);
	env.vertices = parsed.vertices;
	env.vertices = scale(&env.vertices, 0.2);
	env.vertices = center(&env.vertices);
	env.vertices = rotate(&env.vertices, Z, M_PI / 4);
	env.vertices = rotate(&env.vertices, Y, M_PI / 4);
	env.vertices = translate(&env.vertices, 0, 0, -0.5);
	for (size_t i = 0; i < env.vertices.size; i++) {
		display_vec(env.vertices.content[i]);
	}
	init_buffers(&env);
	while (!glfwWindowShouldClose(env.win))
	{
		update(&env);
	}
	glfwDestroyWindow(env.win);
	glfwTerminate();
	return (0);
}
