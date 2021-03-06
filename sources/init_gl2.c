/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_gl2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 11:22:10 by hsabouri          #+#    #+#             */
/*   Updated: 2018/05/13 19:04:48 by oadib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_scop.h"

t_env	*init_uniforms(t_env *env)
{
	GLint err;

	env->loc.proj = glGetUniformLocation(env->program, "Proj");
	env->loc.view = glGetUniformLocation(env->program, "View");
	env->loc.model = glGetUniformLocation(env->program, "Model");
	env->loc.start = glGetUniformLocation(env->program, "Start");
	env->loc.end = glGetUniformLocation(env->program, "End");
	env->loc.state = glGetUniformLocation(env->program, "State");
	env->loc.texture_mode = glGetUniformLocation(env->program, "TextureMode");
	err = glGetError();
	if (err != GL_NO_ERROR)
	{
		printf("error : %d\n", err);
		error("OPENGL", "Could not access uniforms.");
	}
	return (env);
}

t_env	*init_textures(t_env *env)
{
	GLint err;

	glGenTextures(1, &env->texture);
	glBindTexture(GL_TEXTURE_2D, env->texture);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, env->image.height,\
		env->image.width, 0, GL_RGBA, GL_UNSIGNED_BYTE, env->image.content);
	glGenerateMipmap(GL_TEXTURE_2D);
	err = glGetError();
	if (err != GL_NO_ERROR)
	{
		printf("error : %d\n", err);
		error("OPENGL", "Could not access load texture.");
	}
	return (env);
}
