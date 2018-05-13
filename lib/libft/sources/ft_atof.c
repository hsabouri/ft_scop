/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 13:17:41 by hsabouri          #+#    #+#             */
/*   Updated: 2018/05/13 19:20:43 by oadib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_sign(const char *str)
{
	int		sign;
	size_t	i;

	sign = 1;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
		sign = -1;
	return (sign);
}

static double	first_part(const char *str, double res, int sign)
{
	size_t	i;

	i = 0;
	while (ft_isdigit(str[i]))
	{
		res *= 10;
		res += (str[i] - '0') * sign;
		i++;
	}
	return (res);
}

double			ft_atof(const char *number)
{
	double	res;
	size_t	i;
	int		power;
	int		sign;

	i = 0;
	res = 0;
	sign = ft_sign(number);
	power = 1;
	while (!ft_isdigit(number[i]))
		i++;
	res = first_part(number + i, res, sign);
	while (ft_isdigit(number[i]))
		i++;
	if (number[i] == '.' || number[i] == ',')
	{
		i++;
		while (ft_isdigit(number[i]))
		{
			power *= 10;
			res += ((double)(number[i] - '0') / (double)power) * sign;
			i++;
		}
	}
	return (res);
}
