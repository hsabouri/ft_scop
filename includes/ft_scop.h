/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scop.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 11:19:46 by hsabouri          #+#    #+#             */
/*   Updated: 2018/04/24 16:50:39 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  FT_SCOP
# define FT_SCOP

# include <libft.h>
# include <OpenGL/gl3.h>
# define GLFW_INCLUDE_NONE
# include <GLFW/glfw3.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>

# include "parser.h"
# include "types.h"

int				error(const char *error_type, const char *to_display);
void			init_version(void);
GLuint			init_program(void);
void			init_buffers(GLuint *vbo);
void			set_error_callbacks(void);
void			set_callbacks(GLFWwindow *win);

#endif