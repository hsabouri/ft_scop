/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 19:18:33 by hsabouri          #+#    #+#             */
/*   Updated: 2018/05/13 18:45:22 by oadib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
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

t_parsed		parse(const char *path);
void			verify(t_parsed *parsed);
t_vec4			parse_vec4(const char *line, size_t	linec);
t_quad			parse_quad(const char *line, size_t	linec);

#endif
