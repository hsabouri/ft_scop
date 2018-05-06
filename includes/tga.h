/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tga.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 11:22:10 by hsabouri          #+#    #+#             */
/*   Updated: 2018/05/05 16:00:40 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TGA_H
# define TGA_H
# include "types.h"
# include <fcntl.h>
# include <sys/stat.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_cmap
{
	unsigned short	fid;
	unsigned short	size;
	unsigned char	bpp;
}				t_cmap;

typedef struct	s_img_spec
{
	unsigned short	x_origin;
	unsigned short	y_origin;
	unsigned short	width;
	unsigned short	height;
	unsigned char	bpp;
	unsigned char	des;
}				t_img_spec;

typedef struct	s_footer
{
	unsigned int	eoff;
	unsigned int	daoff;
	char			sig[16];
	char			undef;
	char			eof;
}				t_footer;

typedef struct	s_tga
{
	unsigned char	id_length;
	unsigned char	color_map;
	unsigned char	img_type;
	t_cmap			cmap;
	t_img_spec		img_spec;
	t_color			*content;
	t_footer		footer;
}				t_tga;

typedef struct	s_img
{
	unsigned int	width;
	unsigned int	height;
	t_color			*content;
}				t_img;

int				error(const char *error_type, const char *to_display);
t_img			parse_tga(const char *path);

#endif
