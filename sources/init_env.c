/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */ 
/*   Created: 2018/04/11 11:22:10 by hsabouri          #+#    #+#             */
/*   Updated: 2018/05/10 10:55:02 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_scop.h"

t_env			*ft_get_env(void)
{
	static t_env	*env = NULL;
	
	if (env == NULL)
		env = (t_env *)malloc(sizeof(t_env));
	return (env);
}

static t_env	*init_gl(t_env *env)
{
	init_buffers(env);
	init_textures(env);
	init_uniforms(env);
	glEnable(GL_DEPTH_TEST);
	glDepthMask(GL_TRUE);
	glDepthFunc(GL_LEQUAL);
	return (env);
}

static int		*init_key_states(void)
{
	int	*res;

	res = (int *)malloc(sizeof(int) * 311);
	bzero(res, sizeof(int) * 311);
	return (res);
}

static t_env	*init_states(t_env *env)
{
	env->states.rot.u = 0;
	env->states.rot.v = 0;
	env->states.view.x = 0;
	env->states.view.y = 0;
	env->states.view.z = -2.0;
	env->states.colors.x = 0.0;
	env->states.colors.y = 0.0;
	env->states.colors.z = 0.0;
	return (env);
}

t_env			*init_env(const char *obj_path, const char *tga_path)
{
	t_env		*env;
	t_parsed	parsed;

	parsed = parse(obj_path);
	env = ft_get_env();
	verify(&parsed);
	env->k_states = init_key_states();
	env = init_states(env);
	env->win = init_window();
	env->program = init_program();
	env->vertices = parsed.vertices;
	if (env->vertices.size == 0)
		error("SCOP", "No data in file.");
	env->indexes = triangulate(&parsed);
	env->vertices = center(&env->vertices);
	env->vertices = reduce(&env->vertices);
	expend(env);
	assign_color(env);
	assign_texture_coords(env);
	env->image = parse_tga(tga_path);
	init_gl(env);
	return (env);
}
