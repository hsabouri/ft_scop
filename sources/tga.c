/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tga.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 11:22:10 by hsabouri          #+#    #+#             */
/*   Updated: 2018/05/06 16:35:03 by hsabouri         ###   ########.fr       */
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

static t_color	*tga_expend(char *src, size_t size, unsigned int bpp)
{
	size_t	i;
	size_t	k;
	t_color	*res;

	i = 0;
	k = 0;
	res = (t_color *)malloc(sizeof(t_color) * size);
	while (i < size)
	{
		res[i].r = (float)src[k + 0] / 255.0;
		res[i].g = (float)src[k + 1] / 255.0;
		res[i].b = (float)src[k + 2] / 255.0;
		if (bpp == 32)
			res[i].a = (float)src[k + 3] / 255.0;
		else
			res[i].a = 1.0;
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
	char			*raw;
	t_img			res;

	if (fd < 0)
		error("TGA", "Can't open tga file.");
	if (read(fd, header, 18) < 18)
		error("TGA", "Can't even fit header !");
	verif_header(header);
	stat(path, &info);
	raw = (char *)malloc(sizeof(char) * (info.st_size - 18));
	read(fd, (void *)raw, info.st_size - 18);
	res.content = tga_expend(raw,\
	((short *)header)[WIDTH] * ((short *)header)[HEIGHT], header[BPP]);
	return ((t_img) {
		((short *)header)[HEIGHT],
		((short *)header)[WIDTH],
		res.content
	});
}
