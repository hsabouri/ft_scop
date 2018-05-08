/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */ 
/*   Created: 2018/04/11 11:22:10 by hsabouri          #+#    #+#             */
/*   Updated: 2018/05/08 14:45:02 by hsabouri         ###   ########.fr       */
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

int			main(int ac, char **av)
{
	t_env		env;
	char		*obj_path;
	static char		*tga_path = "assets/licorne.tga";

	if (ac < 2)
		error("usage", "ft_scop file.obj [texture.tga]");
	obj_path = av[1];
	if (ac >= 3)
		tga_path = av[2];
	env = init_env(obj_path, tga_path);
	while (!glfwWindowShouldClose(env.win))
	{
		update(&env);
	}
	glfwDestroyWindow(env.win);
	glfwTerminate();
	return (0);
}
