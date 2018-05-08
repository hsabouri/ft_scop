/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */ 
/*   Created: 2018/04/11 11:22:10 by hsabouri          #+#    #+#             */
/*   Updated: 2018/05/08 14:44:48 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_scop.h"

static t_env	init_gl(t_env *env)
{
	init_buffers(env);
	init_textures(env);
	init_uniforms(env);
	glEnable(GL_DEPTH_TEST);
	glDepthMask(GL_TRUE);
	glDepthFunc(GL_LEQUAL);
}

t_env			init_env(const char *obj_path, const char *tga_path)
{
	t_env		env;
	t_parsed	parsed;

	parsed = parse(obj_path);
	verify(&parsed);
	env.win = init_window();
	env.program = init_program();
	env.vertices = parsed.vertices;
	if (env.vertices.size == 0)
		error("SCOP", "No data in file.");
	env.indexes = triangulate(&parsed);
	env.vertices = center(&env.vertices);
	env.vertices = reduce(&env.vertices);
	env = expend(&env);
	env = assign_color(&env);
	env = assign_texture_coords(&env);
	init_gl(&env);
	return (env);
}
