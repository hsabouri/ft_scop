/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <hsabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 19:19:42 by hsabouri          #+#    #+#             */
/*   Updated: 2018/05/10 15:55:12 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_scop.h"

void			key_callback(GLFWwindow *win, int key, int scancode, int act,\
int mods)
{
	t_env	*env;

	(void)win;
	(void)scancode;
	(void)mods;
	env = ft_get_env();
	if (key == GLFW_KEY_ESCAPE)
		exit(EXIT_SUCCESS);
	if (key >= 38 && key <= 348 && act == GLFW_PRESS)
		env->k_states[key - 38] = 1;
	if (key >= 38 && key <= 348 && act == GLFW_RELEASE)
		env->k_states[key - 38] = 0;
}

static t_env	*key_derivate_actions(t_env *env)
{
	if (env->states.color_mov == 0 && env->states.colors.z > 0.05)
		env->states.colors.z -= 0.05;
	else if (env->states.color_mov == 0 && env->states.colors.z < 0.05)
		env->states.colors.z = 0.0;
	else if (env->states.color_mov == 1 && env->states.colors.z < 0.95)
		env->states.colors.z += 0.05;
	else if (env->states.color_mov == 1 && env->states.colors.z < 0.05)
		env->states.colors.z = 1.0;
	return (env);
}

static t_env	*key_actions2(t_env *env)
{
	if (env->k_states[GLFW_KEY_Z - 38])
		env->states.texture_mod = 1;
	if (env->k_states[GLFW_KEY_X - 38])
		env->states.texture_mod = 2;
	if (env->k_states[GLFW_KEY_Y - 38])
		env->states.texture_mod = 3;
	if (env->k_states[GLFW_KEY_R - 38])
		env->states.texture_mod = 0;
	if (env->k_states[GLFW_KEY_LEFT - 38])
		env->states.model.x -= 0.05;
	if (env->k_states[GLFW_KEY_RIGHT - 38])
		env->states.model.x += 0.05;
	if (env->k_states[GLFW_KEY_UP - 38])
		env->states.model.y += 0.05;
	if (env->k_states[GLFW_KEY_DOWN - 38])
		env->states.model.y -= 0.05;
	return (env);
}

t_env			*key_actions(t_env *env)
{
	if (env->k_states[GLFW_KEY_A - 38])
		env->states.rot.u -= 1.0;
	if (env->k_states[GLFW_KEY_D - 38])
		env->states.rot.u += 1.0;
	if (env->k_states[GLFW_KEY_W - 38])
		env->states.rot.v -= 1.0;
	if (env->k_states[GLFW_KEY_S - 38])
		env->states.rot.v += 1.0;
	if (env->k_states[GLFW_KEY_Q - 38])
		env->states.model.z += 0.05;
	if (env->k_states[GLFW_KEY_E - 38])
		env->states.model.z -= 0.05;
	if (env->k_states[GLFW_KEY_1 - 38])
	{
		env->states.color_mov = (env->states.color_mov) ? 0 : 1;
		env->k_states[GLFW_KEY_1 - 38] = 0;
	}
	if (env->k_states[GLFW_KEY_LEFT_BRACKET - 38])
		env->states.colors.y -= (env->states.colors.y > 0.05) ? 0.05 : 0.0;
	if (env->k_states[GLFW_KEY_RIGHT_BRACKET - 38])
		env->states.colors.y += (env->states.colors.y < 0.95) ? 0.05 : 0.0;
	env = key_actions2(env);
	return (key_derivate_actions(env));
}
