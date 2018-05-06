/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tga.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 11:22:10 by hsabouri          #+#    #+#             */
/*   Updated: 2018/05/05 15:34:55 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tga.h"

static void	verif_header(t_tga img)
{
	if (img.color_map != 0)
		error("TGA", "Can't read tga with color map.");
	if (img.img_type != 2)
		error("TGA", "TGA format needs to be uncompressed true-color.");
	if (img.img_spec.bpp != 32)
		error("TGA", "Bits per pixel needs to be 32.");
}

t_img		parse_tga(const char *path)
{
	const int	fd = open(path, O_RDONLY);
	char		header[18];
	struct stat	info;
	t_tga		res;

	if (fd < 0)
		error("TGA", "Can't open tga file.");
	if (read(fd, header, 18) < 18)
		error("TGA", "Can't even fit header !");
	res = ((t_tga *)header)[0];
	verif_header(res);
	stat(path, &info);
	res.content = (t_color *)malloc(sizeof(char) * (info.st_size - 18));
	read(fd, (void *)res.content, info.st_size - 18);
	return ((t_img) {(int)res.img_spec.width, (int)res.img_spec.height, res.content});
}
