/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 13:16:10 by hsabouri          #+#    #+#             */
/*   Updated: 2018/04/25 19:32:27 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_scop.h"

typedef struct	s_quad
{
	int a;
	int b;
	int c;
	int d;
}				t_quad;

static t_tri	*trify(t_tris *tris, t_quad quad)
{
	t_tri	*first;
	t_tri	*second;

	if (tris->size % ALLOC_SIZE == 0 && !(tris->content =\
	(t_tri *)realloc(tris->content, sizeof(t_tris) *\
	(tris->size / ALLOC_SIZE) + 1)))
		error("SYSTEM", "Can't realloc, verify ALLOC_SIZE");
	first = tris->content + tris->size;
	first->a = quad.a;
	first->b = quad.b;
	first->c = quad.c;
	tris->size++;
	if (quad.d >= 0)
	{
		if (tris->size % ALLOC_SIZE == 0 && !(tris->content =\
		(t_tri *)realloc(tris->content, sizeof(t_tris) *\
		(tris->size / ALLOC_SIZE) + 1)))
			error("SYSTEM", "Can't realloc, verify ALLOC_SIZE");
		first->a = quad.a;
		first->b = quad.c;
		first->c = quad.d;
		tris->size++;
	}
	return (tris->content);
}

t_vec4			parse_vec4(const char *line)
{
	t_vec4			res;
	double			*res_c;
	const char		*cp = strdup(line);
	char			*current;
	size_t			token;

	token = 0;
	res_c = (double *)&res;
	if (!(current = strtok((char *)cp, " ")))
		error("PARSER", "Vertice is empty");
	while (current != NULL)
	{
		if (token <= 3)
			res_c[token] = atof(current);
		else
			break ;
		token++;
		current = strtok(NULL, " ");
	}
	if (token < 2)
		error("PARSER", "Vertice must have at least 3 coordinates");
	if (token < 3)
		res.w = 0;
	return (res);
}

t_tri			*parse_tri(const char *line, t_parsed *parsed)
{
	t_quad			quad;
	double			*res_c;
	const char		*cp = strdup(line);
	char			*current;
	size_t			token;

	token = 0;
	res_c = (double *)&quad;
	if (!(current = strtok((char *)cp, " ")))
		error("PARSER", "Vertice is empty");
	while (current != NULL)
	{
		if (token <= 3)
			res_c[token] = atof(current);
		else
			break ;
		token++;
		current = strtok(NULL, " ");
	}
	if (token < 2)
		error("PARSER", "Vertice must have at least 3 coordinates");
	quad.d = -1;
	if (token < 3)
		quad.d = 0;
	return (trify(&parsed->tris, quad));
}
