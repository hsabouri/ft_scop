/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 10:35:42 by hsabouri          #+#    #+#             */
/*   Updated: 2018/04/24 17:42:16 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_scop.h"

size_t		jump(char *line)
{
	size_t i;

	i = 0;
	while (ft_isspace(line[i]))
		i++;
	return (i);
}

void		each_line(int fd, t_parsed *parsed)
{
	char *line;

	while (get_next_line(fd, &line) > 0)
	{
		// Add tokens etc...
	}
}

void		parse(char *path)
{
	int			fd;
	struct stat info;
	t_parsed parsed;

	if (stat(path, &info))
		error("FILESYSTEM", "Could not access file.");
	if ((fd = open(path, O_RDONLY)) < 0)
		error("FILESYSTEM", "Could not open file.");
	if ((parsed.vertices.content =
	(t_vertex *)malloc(sizeof(t_vertex) * ALLOC_SIZE)) == NULL)
	{
		error("SYSTEM", "Can't allocate memory, verify ALLOC_SIZE");
		exit(EXIT_FAILURE);
	}
	parsed.vertices.global = 0;
	parsed.vertices.group = 0;
	parsed.vertices.obj = 0;
	if ((parsed.tris.content =
	(t_tri *)malloc(sizeof(t_tri) * ALLOC_SIZE)) == NULL)
	{
		error("SYSTEM", "Can't allocate memory, verify ALLOC_SIZE");
		exit(EXIT_FAILURE);
	}
	parsed.tris.size = 0;
	each_line(fd, &parsed);
}
