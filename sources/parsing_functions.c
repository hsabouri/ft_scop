/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 13:27:39 by hsabouri          #+#    #+#             */
/*   Updated: 2018/04/30 13:45:48 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_scop.h"
#include "vec.h"

t_vec4	parse_vec4(const char *line, size_t linec)
{
	char	*line_c;
	char	*current;
	t_vec4	res;
	GLfloat	*res_c;
	int		count;

	line_c = strdup(line);
	res = vec_new(0, 0, 0, 0);
	res_c = (GLfloat *)&res;
	current = strtok(line_c, " ");
	count = 0;
	while (current && count < 4)
	{
		res_c[count] = atof(current);
		count++;
		current = strtok(NULL, " ");
	}
	if (count < 3)
		error_line(linec, "PARSER", "Vertice has not enough coordinates.");
	if (count == 3)
		res.w = 1.0;
	free(line_c);
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
	while (current && count < 5)
	{
		res_c[count] = atoi(current) - 1;
		if (res_c[count] < 0)
			error_line(linec, "PARSER", "Face has invalid index.");
		count++;
		current = strtok(NULL, " ");
	}
	if (count < 3)
		error_line(linec, "PARSER", "Face has not enough indexes.");
	if (count == 3)
		res.d = -1;
	free(line_c);
	return (res);
}
