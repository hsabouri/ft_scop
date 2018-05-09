/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <hsabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 13:22:27 by hsabouri          #+#    #+#             */
/*   Updated: 2018/05/09 14:26:06 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_scop.h"

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

static void	clear(t_env *env, t_update *u)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glfwGetFramebufferSize(env->win, &u->width, &u->height);
	glViewport(0, 0, u->width, u->height);
	u->proj_mat = get_proj_mat((float)u->width / (float)u->height,\
							   M_PI / 2, 0.0001, 1000.0);
}

static void	uniforms(t_env *env, t_update *u)
{
	glUniformMatrix4fv(env->loc.proj, 1, GL_FALSE, (const GLfloat*) &u->proj_mat);
	glUniformMatrix4fv(env->loc.model, 1, GL_FALSE, (const GLfloat*) &u->model_mat);
	glUniformMatrix4fv(env->loc.view, 1, GL_FALSE, (const GLfloat*) &u->view_mat);
	glUseProgram(env->program);
	glUniform4f(env->loc.state, 0, 0, 0.5, 0);
	glUniform4fv(env->loc.start, 1, (GLfloat*) &u->start);
	glUniform4fv(env->loc.end, 1, (GLfloat*) &u->end);
}

void	update(t_env *env)
{
	static size_t	frame = 0;
	t_update		u;

	clear(env, &u);
	u.model_mat = get_rot_mat(Y, frame * (M_PI / 512));
	u.view_mat = mat_mult(mat_new(0.0, 0.0, -2.0, 1.0), get_rot_mat(X, M_PI / 9));
	u.start = RED;
	u.end = YELLOW;
	uniforms(env, &u);
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
