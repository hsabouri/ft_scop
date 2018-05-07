/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tga.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 11:22:10 by hsabouri          #+#    #+#             */
/*   Updated: 2018/05/06 15:50:12 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TGA_H
# define TGA_H
# include "types.h"
# include <fcntl.h>
# include <sys/stat.h>
# include <unistd.h>
# include <stdlib.h>

# define ID_LENGTH 0
# define IS_COLOR_MAP 1
# define IMAGE_TYPE 2
# define BPP 16
# define WIDTH 6
# define HEIGHT 7

typedef struct	s_img
{
	unsigned int	width;
	unsigned int	height;
	t_abgr			*content;
}				t_img;

int				error(const char *error_type, const char *to_display);
t_img			parse_tga(const char *path);

#endif
