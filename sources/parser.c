/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 10:35:42 by hsabouri          #+#    #+#             */
/*   Updated: 2018/04/25 19:32:41 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_scop.h"

size_t		jump(const char *line)
{
	size_t i;

	i = 0;
	while (ft_isspace(line[i]))
		i++;
	return (i);
}

unsigned int get_id(void	*vstruct, size_t offset)
{
	const unsigned int *	vstruct_c = (unsigned int *)vstruct;
	unsigned int			i;
	unsigned int			res;

	i = 0;
	res = vstruct_c[0];
	while (++i && i < offset)
		res += vstruct_c[i];
	return (res);
}

int			object_tokens(char *line, t_parsed *parsed)
{
	const unsigned int	vid = get_id((void *)&parsed->vertices, parsed->offset);

	if (line[0] == 'v' || line[0] == 'V')
	{
		((unsigned int *)&(parsed->vertices))[parsed->offset] += 1;
		if (vid % ALLOC_SIZE == 0 && !(parsed->vertices.content =\
		(t_vertex *)realloc(parsed->vertices.content, sizeof(t_vertex) *\
		(vid / ALLOC_SIZE) + 1)))
			error("SYSTEM", "Can't realloc, verify ALLOC_SIZE");
		parsed->vertices.content[vid].pos = parse_vec4(line + 1);
		return (1);
	}
	if (line[0] == 'f' || line[0] == 'F')
	{
		if (parsed->tris.size % ALLOC_SIZE == 0 && !(parsed->tris.content =\
		(t_tri *)realloc(parsed->tris.content, sizeof(t_tris) *\
		(parsed->tris.size / ALLOC_SIZE) + 1)))
			error("SYSTEM", "Can't realloc, verify ALLOC_SIZE");
		parsed->tris.content = parse_tri(line, parsed);
		parsed->tris.size += 1;
		return (1);
	}
	return (0);
}

int			hierarchy_token(char *line, t_parsed *parsed)
{
	if (line[0] == 'g' || line[0] == 'G')
	{
		parsed->offset = 1;
		parsed->vertices.global += parsed->vertices.group +\
								   parsed->vertices.obj;
		parsed->vertices.group = 0;
		parsed->vertices.obj = 0;
		return (1);
	}
	if (line[0] == 'o' || line[0] == 'O')
	{
		parsed->offset = 2;
		parsed->vertices.group += parsed->vertices.obj;
		parsed->vertices.obj = 0;
		return (1);
	}
	return (0);
}

void		each_line(int fd, t_parsed *parsed)
{
	char	*line;
	size_t	i;
	int		res;

	while (get_next_line(fd, &line) > 0)
	{
		i = jump(line);
		if (line[0] != '#')
			res = object_tokens(line + i, parsed);
		else
			res = 1;
		if (res == 0)
			res = hierarchy_token(line + i, parsed);
	}
}

void		parse(char *path)
{
	int			fd;
	struct stat info;
	t_parsed parsed;

	parsed.offset = 0;
	if ((fd = open(path, O_RDONLY)) < 0)
		error("FILESYSTEM", "Could not open file.");
	if ((parsed.vertices.content =
	(t_vertex *)malloc(sizeof(t_vertex) * ALLOC_SIZE)) == NULL)
		error("SYSTEM", "Can't allocate memory, verify ALLOC_SIZE");
	parsed.vertices.global = 0;
	parsed.vertices.group = 0;
	parsed.vertices.obj = 0;
	if ((parsed.tris.content =
	(t_tri *)malloc(sizeof(t_tri) * ALLOC_SIZE)) == NULL)
		error("SYSTEM", "Can't allocate memory, verify ALLOC_SIZE");
	parsed.tris.size = 0;
	each_line(fd, &parsed);
}
