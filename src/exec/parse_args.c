/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 14:13:58 by annabrag          #+#    #+#             */
/*   Updated: 2024/03/14 14:14:21 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

static double	atod_part2(char *s, int i)
{
	double	second;

	second = 0;
	while (s[i] && (s[i] >= 48 && s[i] <= 57))
	{
		second = second / 10 + (s[i] - 48);
		i++;
	}
	return (second);
}

double	atod(char *s)
{
	int		i;
	int		sign;
	double	first;
	double	second;

	i = 0;
	sign = 1;
	first = 0;
	while (s[i] == 32 || (s[i] >= 9 && s[i] <= 13))
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign *= -1;
		i++;
	}
	while (s[i] && (s[i] >= 48 && s[i] <= 57))
	{
		first = first * 10 + (s[i] - 48);
		i++;
	}
	if (s[i] == '.' || s[i] == ',')
		i++;
	second = atod_part2(s, i);
	return (sign * (first + second));
}
