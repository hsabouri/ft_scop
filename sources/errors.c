/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 13:58:05 by hsabouri          #+#    #+#             */
/*   Updated: 2018/04/12 16:26:13 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_scop.h"

static void		error_callback(int error, const char* description)
{
	ft_putstr_fd("\x1b[31mOPENGL\x1b[0m: ", STDERR_FILENO);
	ft_putendl_fd(description, STDERR_FILENO);
}

void			set_error_callbacks(void)
{
	glfwSetErrorCallback(error_callback);
}

int				error(const char *error_type, const char *to_display)
{
	ft_putstr_fd("\x1b[31m", STDERR_FILENO);
	ft_putstr_fd(error_type, STDERR_FILENO);
	ft_putstr_fd("\x1b[0m: ", STDERR_FILENO);
	ft_putendl_fd(to_display, STDERR_FILENO);
	return (0);
}
