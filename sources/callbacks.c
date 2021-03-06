/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   callbacks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 14:18:19 by hsabouri          #+#    #+#             */
/*   Updated: 2018/05/13 18:49:05 by oadib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_scop.h"

static void	close_callback(GLFWwindow *win)
{
	(void)win;
	ft_putendl("closing");
}

void		set_callbacks(GLFWwindow *win)
{
	glfwSetWindowCloseCallback(win, close_callback);
}
