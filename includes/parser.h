/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 19:18:33 by hsabouri          #+#    #+#             */
/*   Updated: 2018/04/25 19:16:26 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	 PARSER_H
# define PARSER_H

# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <get_next_line.h>
# include "libft.h"
# include "types.h"

# define ALLOC_SIZE 1

typedef struct	s_vertices
{
	unsigned int	global;
	unsigned int	group;
	unsigned int	obj;
	t_vertex		*content;
}				t_vertices;

typedef struct	s_tex_coord
{
	unsigned int	global;
	unsigned int	group;
	unsigned int	obj;
	t_tex2			*content;
}				t_tex_coord;

typedef struct	s_normals
{
	unsigned int	global;
	unsigned int	group;
	unsigned int	obj;
	t_vec4			*content;
}				t_normals;

typedef struct	s_tris
{
	t_tri	*content;
	size_t	size;
}				t_tris;

typedef struct	s_parsed
{
	t_tris		tris;
	t_vertices	vertices;
	size_t		offset;
}				t_parsed;

void			parse(char *path);
t_tri			*parse_tri(const char *line, t_parsed *parsed);
t_vec4			parse_vec4(const char *line);
size_t			jump(const char *line);

#endif
