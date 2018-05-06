/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */ 
/*   Created: 2018/04/11 11:22:10 by hsabouri          #+#    #+#             */
/*   Updated: 2018/05/06 16:20:54 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_scop.h"

void	update(t_env *env)
{
	static size_t	frame = 0;
	t_mat4			proj_mat;
	const t_mat4	model_mat = get_rot_mat(Y, frame * (M_PI / 128));
	const t_mat4	view_mat = mat_mult(mat_new(0.0, 0.0, -2.0, 1.0), get_rot_mat(X, M_PI / 9));
	const t_color	start = RED;
	const t_color	end = YELLOW;
	int				width;
	int				height;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glfwGetFramebufferSize(env->win, &width, &height);
	glViewport(0, 0, width, height);
	printf("{%d, %d}\n", width, height);
	proj_mat = get_proj_mat((float)width / (float)height, M_PI / 2, 0.0001, 1000.0);
	glUseProgram(env->program);
	glUniformMatrix4fv(env->loc.proj, 1, GL_FALSE, (const GLfloat*) &proj_mat);
	glUniformMatrix4fv(env->loc.model, 1, GL_FALSE, (const GLfloat*) &model_mat);
	glUniformMatrix4fv(env->loc.view, 1, GL_FALSE, (const GLfloat*) &view_mat);
	glUniform4f(env->loc.state, 0, 0, 0.5, 0);
	glUniform4fv(env->loc.start, 1, (GLfloat*) &start);
	glUniform4fv(env->loc.end, 1, (GLfloat*) &end);
	glDrawArrays(GL_TRIANGLES, 0, env->vertices.size);
	glfwSwapBuffers(env->win);
	glfwPollEvents();
	GLuint err = glGetError();
	if (err != GL_NO_ERROR)
	{
		ft_putnbr_fd(err, STDERR_FILENO);
		ft_putendl_fd("", STDERR_FILENO);
	}
	frame += 1;
}

GLFWwindow	*init(void)
{
	GLFWwindow	*win;

	srand(time(NULL));
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
	env.vertices = center(&env.vertices);
	env.vertices = reduce(&env.vertices);
	env = expend(&env);
	env = assign_color(&env);
	env = assign_texture_coords(&env);
	init_buffers(&env);
	init_textures(&env);
	init_uniforms(&env);
	glEnable(GL_DEPTH_TEST);
	glDepthMask(GL_TRUE);
	glDepthFunc(GL_LEQUAL);
	printf("Displaying...\n");
	while (!glfwWindowShouldClose(env.win))
	{
		update(&env);
	}
	glfwDestroyWindow(env.win);
	glfwTerminate();
	return (0);
}
