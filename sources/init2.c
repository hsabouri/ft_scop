/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */ 
/*   Created: 2018/04/11 11:22:10 by hsabouri          #+#    #+#             */
/*   Updated: 2018/05/03 17:52:35 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_scop.h"

t_env	*init_uniforms(t_env *env)
{
	const GLuint proj_loc = glGetUniformLocation(env->program, "Proj");
	const GLuint view_loc = glGetUniformLocation(env->program, "View");
	const GLuint model_loc = glGetUniformLocation(env->program, "Model");

	env->proj_loc = proj_loc;
	env->view_loc = view_loc;
	env->model_loc = model_loc;
	return (env);
}
