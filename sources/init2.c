/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */ 
/*   Created: 2018/04/11 11:22:10 by hsabouri          #+#    #+#             */
/*   Updated: 2018/05/05 10:45:40 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_scop.h"

t_env	*init_uniforms(t_env *env)
{
	GLint err;
	env->proj_loc = glGetUniformLocation(env->program, "Proj");
	env->view_loc = glGetUniformLocation(env->program, "View");
	env->model_loc = glGetUniformLocation(env->program, "Model");
	env->start_loc = glGetUniformLocation(env->program, "Start");
	env->end_loc = glGetUniformLocation(env->program, "End");
	env->state_loc = glGetUniformLocation(env->program, "State");
	err = glGetError();
	if (err != GL_NO_ERROR)
	{
		printf("error : %d\n", err);
		error("OPENGL", "Could not access uniforms.");
	}
	return (env);
}
