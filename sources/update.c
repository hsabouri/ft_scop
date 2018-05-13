/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <hsabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 13:22:27 by hsabouri          #+#    #+#             */
/*   Updated: 2018/05/13 19:09:55 by oadib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_scop.h"

static void		clear(t_env *env, t_update *u)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glfwGetFramebufferSize(env->win, &u->width, &u->height);
	glViewport(0, 0, u->width, u->height);
	u->proj_mat = get_proj_mat((float)u->width / (float)u->height,\
		M_PI / 2, -1, 1000.0);
}

static void		uniforms(t_env *env, t_update *u)
{
	glUniformMatrix4fv(env->loc.proj, 1, GL_FALSE,\
		(const GLfloat*)&u->proj_mat);
	glUniformMatrix4fv(env->loc.model, 1, GL_FALSE,\
		(const GLfloat*)&u->model_mat);
	glUniformMatrix4fv(env->loc.view, 1, GL_FALSE,\
		(const GLfloat*)&u->view_mat);
	glUseProgram(env->program);
	glUniform4f(env->loc.state, env->states.colors.x, env->states.colors.y,\
				env->states.colors.z, 1.0);
	glUniform4fv(env->loc.start, 1, (GLfloat*)&u->start);
	glUniform4fv(env->loc.end, 1, (GLfloat*)&u->end);
	glUniform1i(env->loc.texture_mode, env->states.texture_mod);
}

static t_env	*init_values(t_env *env, t_update *u)
{
	u->model_mat = get_rot_mat(Y, env->states.rot.u * ROT_SPEED);
	u->model_mat = mat_mult(get_rot_mat(X, env->states.rot.v * ROT_SPEED),\
		u->model_mat);
	u->model_mat = mat_mult(mat_new(env->states.model.x, env->states.model.y,\
		env->states.model.z, 1.0), u->model_mat);
	u->view_mat = mat_mult(mat_new(env->states.view.x, env->states.view.y,\
		env->states.view.z, 1.0), get_rot_mat(X, M_PI / 9));
	u->start = RED;
	u->end = YELLOW;
	return (env);
}

void			update(t_env *env)
{
	static size_t	frame = 0;
	t_update		u;

	env = key_actions(env);
	clear(env, &u);
	env = init_values(env, &u);
	uniforms(env, &u);
	glDrawArrays(GL_TRIANGLES, 0, env->vertices.size);
	glfwSwapBuffers(env->win);
	glfwPollEvents();
	frame += 1;
}
