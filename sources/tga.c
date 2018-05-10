/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tga.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 11:22:10 by hsabouri          #+#    #+#             */
/*   Updated: 2018/05/09 22:01:52 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tga.h"

static void		verif_header(unsigned char *mem)
{
	if (mem[IS_COLOR_MAP] != 0)
		error("TGA", "Can't read tga with color map.");
	if (mem[IMAGE_TYPE] != 2)
		error("TGA", "TGA format needs to be uncompressed true-color.");
	if (mem[BPP] != 32 && mem[BPP] != 24)
		error("TGA", "Bits per pixel needs to be 32 or 24.");
}

static t_abgr	*tga_expend(unsigned char *src, unsigned int width,\
unsigned int height, unsigned int bpp)
{
	size_t	i;
	size_t	k;
	t_abgr	*res;

	i = 0;
	k = 0;
	res = (t_abgr *)malloc(sizeof(t_abgr) * width * height);
	while (i < width * height)
	{
		res[i].b = src[((k % height) * width + k / height) + 0];
		res[i].g = src[((k % height) * width + k / height) + 1];
		res[i].r = src[((k % height) * width + k / height) + 2];
		if (bpp == 32)
			res[i].a = src[((k % height) * width + k / height) + 3];
		else
			res[i].a = 255;
		k += 3;
		if (bpp == 32)
			k++;
		i++;
	}
	free(src);
	return (res);
}

t_img			parse_tga(const char *path)
{
	const int		fd = open(path, O_RDONLY);
	unsigned char	header[18];
	struct stat		info;
	unsigned char	*raw;
	t_img			res;

	if (!fd || access(path, F_OK) == -1)
		error("TGA", "Can't open tga file.");
	if (read(fd, header, 18) < 18)
		error("TGA", "Can't even fit header !");
	verif_header(header);
	stat(path, &info);
	raw = (unsigned char *)malloc(sizeof(unsigned char) * (info.st_size - 18));
	read(fd, raw, info.st_size - 18);
	res.content = tga_expend(raw,\
	((short *)header)[WIDTH], ((short *)header)[HEIGHT], header[BPP]);
	return ((t_img) {
		((short *)header)[HEIGHT],
		((short *)header)[WIDTH],
		res.content
	});
}
