/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */ 
/*   Created: 2018/04/11 11:22:10 by hsabouri          #+#    #+#             */
/*   Updated: 2018/05/09 14:23:54 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_scop.h"

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
