/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 13:58:05 by hsabouri          #+#    #+#             */
/*   Updated: 2018/04/27 14:44:18 by hsabouri         ###   ########.fr       */
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
	printf("\x1b[31m%s\x1b[0m: %s", error_type, to_display);
	exit(EXIT_FAILURE);
	return (0);
}

int				error_line(const size_t line, const char *error_type, const char *to_display)
{
	printf("\x1b[31m%s\x1b[0m: line %zu - %s\n", error_type, line, to_display);
	exit(EXIT_FAILURE);
	return (0);
}
