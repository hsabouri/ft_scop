/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 19:18:33 by hsabouri          #+#    #+#             */
/*   Updated: 2018/04/27 14:38:41 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	 PARSER_H
# define PARSER_H

# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <get_next_line.h>
# include <ctype.h>
# include "libft.h"
# include "types.h"

# define ALLOC_SIZE 1

typedef struct	s_vertices
{
	t_vec4		*content;
	size_t		size;
}				t_vertices;

typedef struct	s_quads
{
	t_quad		*content;
	size_t		size;
}				t_quads;

typedef struct	s_parsed
{
	t_quads		quads;
	t_vertices	vertices;
}				t_parsed;

void			parse(char *path);
t_vec4			parse_vec4(const char *line, size_t	linec);
t_quad			parse_quad(const char *line, size_t	linec);

#endif
