/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 13:27:39 by hsabouri          #+#    #+#             */
/*   Updated: 2018/04/28 10:43:58 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_scop.h"

t_vec4	parse_vec4(const char *line, size_t linec)
{
	char	*line_c;
	char	*current;
	t_vec4	res;
	GLfloat	*res_c;
	int		count;

	line_c = strdup(line);
	res_c = (GLfloat *)&res;
	current = strtok(line_c, " ");
	count = 0;
	while (current)
	{
		res_c[count] = atof(current);
		count++;
		current = strtok(NULL, " ");
	}
	if (count > 4)
		error_line(linec, "PARSER", "Vertice has too much coordinates.");
	if (count < 3)
		error_line(linec, "PARSER", "Vertice has not enough coordinates.");
	if (count == 3)
		res.w = 1.0;
	return (res);
}

t_quad	parse_quad(const char *line, size_t linec)
{
	char	*line_c;
	char	*current;
	t_quad	res;
	int		*res_c;
	int		count;

	line_c = strdup(line);
	res_c = (int *)&res;
	current = strtok(line_c, " ");
	count = 0;
	while (current)
	{
		res_c[count] = atoi(current) - 1;
		if (res_c[count] < 0)
			error_line(linec, "PARSER", "Face has invalid index.");
		count++;
		current = strtok(NULL, " ");
	}
	if (count < 3)
		error_line(linec, "PARSER", "Face has not enough indexes.");
	if (count > 4)
		error_line(linec, "PARSER", "Only quads and triangles are supported.");
	if (count == 3)
		res.d = -1;
	return (res);
}
