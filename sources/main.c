/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */ 
/*   Created: 2018/04/11 11:22:10 by hsabouri          #+#    #+#             */
/*   Updated: 2018/05/03 11:01:05 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_scop.h"

void	update(t_env *env)
{
	int width;
	int height;

	glfwGetFramebufferSize(env->win, &width, &height);
	glViewport(0, 0, width, height);
	glClear(GL_COLOR_BUFFER_BIT);
	glUseProgram(env->program);
	glDrawArrays(GL_TRIANGLES, 0, env->vertices.size);
	glfwSwapBuffers(env->win);
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
	glfwMakeContextCurrent(win);
    gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
	glfwSwapInterval(1);
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
	env.program = init_program();
	env.vertices = parsed.vertices;
	env.indexes = triangulate(&parsed);
	env.vertices = scale(&env.vertices, 0.2);
	env.vertices = center(&env.vertices);
	env.vertices = translate(&env.vertices, 0, 0, -0.5);
	env = expend(&env);
	env = assign_color(&env);
	init_buffers(&env);
	while (!glfwWindowShouldClose(env.win))
	{
		update(&env);
	}
	glfwDestroyWindow(env.win);
	glfwTerminate();
	return (0);
}
