/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 10:35:42 by hsabouri          #+#    #+#             */
/*   Updated: 2018/04/27 14:48:33 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_scop.h"

size_t		jump(const char *line)
{
	size_t i;

	i = 0;
	while (isspace(line[i]))
		i++;
	return (i);
}

void		add_vertice(const char *line, t_parsed *parsed, size_t linec)
{
	const t_vec4	vertice = parse_vec4(line, linec);

	parsed->vertices.content[parsed->vertices.size] = vertice;
	parsed->vertices.size++;
}

void		add_quad(const char *line, t_parsed *parsed, size_t linec)
{
	const t_quad	quad = parse_quad(line, linec);

	parsed->quads.content[parsed->quads.size] = quad;
	parsed->quads.size++;
}

void		tokens(const char *line, t_parsed *parsed, size_t linec)
{
	if (line[0] == 'v' || line[0] == 'V')
	{
		if (parsed->vertices.size % ALLOC_SIZE == 0 &&\
		!(parsed->vertices.content = (t_vec4 *)realloc(parsed->vertices.content\
		, sizeof(t_vec4) * (parsed->vertices.size / ALLOC_SIZE + ALLOC_SIZE))))
			error("SYSTEM", "Error while reallocating.");
		add_vertice(line + 1, parsed, linec);
	}
	if (line[0] == 'f' || line[0] == 'F')
	{
		if (parsed->quads.size % ALLOC_SIZE == 0 &&\
		!(parsed->quads.content = (t_quad *)realloc(parsed->quads.content,\
		sizeof(t_quads) * (parsed->quads.size / ALLOC_SIZE + ALLOC_SIZE))))
			error("SYSTEM", "Error while reallocating.");
		add_quad(line + 1, parsed, linec);
	}
}

void		parse(char *path)
{
	int			fd;
	t_parsed	parsed;
	char		*line;
	size_t		index;
	size_t		linec;

	if ((fd = open(path, O_RDONLY)) < 0)
		error("FILESYSTEM", "Could not open file.");
	if (!(parsed.quads.content = (t_quad *)malloc(sizeof(t_quad) * ALLOC_SIZE)))
		error("SYSTEM", "Can't allocate memory, verify ALLOC_SIZE.");
	if (!(parsed.vertices.content =\
	(t_vec4 *)malloc(sizeof(t_vec4) * ALLOC_SIZE)))
		error("SYSTEM", "Can't allocate memory, verify ALLOC_SIZE.");
	parsed.quads.size = 0;
	parsed.vertices.size = 0;
	linec = 0;
	while (get_next_line(fd, &line) > 0)
	{
		index = jump(line);
		tokens(line + index, &parsed, linec);
		linec++;
	}
	printf("vertices : %zu | faces : %zu", parsed.vertices.size, parsed.quads.size);
}
