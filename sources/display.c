/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 10:35:42 by hsabouri          #+#    #+#             */
/*   Updated: 2018/05/03 10:16:14 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include <stdio.h>

void	display_color(t_color color)
{
	printf("%ff, %ff, %ff, %ff }\n", color.r, color.g, color.b, color.a);
}

void	display_vec(t_vec4 vec)
{
	printf("{ %ff, %ff, %ff, %ff, ", vec.x, vec.y, vec.z, vec.w);
	display_color(vec.color);
}
