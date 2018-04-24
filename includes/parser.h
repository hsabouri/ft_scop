/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 19:18:33 by hsabouri          #+#    #+#             */
/*   Updated: 2018/04/24 17:39:31 by hsabouri         ###   ########.fr       */
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

# define ALLOC_SIZE 2048

typedef struct	s_vertices
{
	t_vertex		*content;
	unsigned int	global;
	unsigned int	group;
	unsigned int	obj;
}				t_vertices;

typedef struct	s_tex_coord
{
	t_tex2			*content;
	unsigned int	global;
	unsigned int	group;
	unsigned int	obj;
}				t_tex_coord;

typedef struct	s_normals
{
	t_vec4			*content;
	unsigned int	global;
	unsigned int	group;
	unsigned int	obj;
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
}				t_parsed;

void			parse(char *path);

#endif
