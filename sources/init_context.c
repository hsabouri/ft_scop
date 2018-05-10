/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_context.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 11:08:53 by hsabouri          #+#    #+#             */
/*   Updated: 2018/05/09 20:56:41 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_scop.h"

#ifdef __APPLE__

typedef void*	GLADloadproc;
void	gladLoadGLLoader(GLADloadproc addr)
{
	(void)addr;
}

#endif

static void		init_version(void)
{
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

GLFWwindow		*init_window(void)
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
	glfwSetInputMode(win, GLFW_STICKY_KEYS, 1);
	glfwSetKeyCallback(win, key_callback);
	set_error_callbacks();
	set_callbacks(win);
 	return (win);
}
