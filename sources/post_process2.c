/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   post_process2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 16:46:47 by hsabouri          #+#    #+#             */
/*   Updated: 2018/05/02 16:48:44 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_scop.h"
#include "vec.h"

t_env	expend(t_env *env)
{
	t_vertices		new_verts;
	const t_vec4	*vertices = env->vertices.content;
	t_tri			*indexes;
	size_t			i;
	
	new_verts.size = env->indexes.size * 3;
	new_verts.content = (t_vec4 *)malloc(sizeof(t_vec4) * new_verts.size);
	indexes = env->indexes.content;
	i = 0;
	while (i < env->indexes.size)
	{
		new_verts.content[i * 3 + 0] = vertices[indexes[i].a];
		indexes[i].a = i * 3 + 0;
		new_verts.content[i * 3 + 1] = vertices[indexes[i].b];
		indexes[i].b = i * 3 + 1;
		new_verts.content[i * 3 + 2] = vertices[indexes[i].c];
		indexes[i].c = i * 3 + 2;
		i++;
	}
	free(env->vertices.content);
	env->vertices = new_verts;
	return (*env);
}
