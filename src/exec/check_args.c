/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 18:50:28 by annabrag          #+#    #+#             */
/*   Updated: 2024/03/13 14:48:21 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

bool	is_only_double(char *s)
{
	int		i;
	bool	has_decimal;

	i = 0;
	has_decimal = false;
	if (s[i] == '-' && s[i + 1])
		i++;
	while (s[i] && (ft_isdigit(s[i]) || s[i] == '.' || s[i] == ','))
	{
		if (s[i] == '.' || s[i] == ',')
		{
			if (has_decimal == true)
				return (false);
			else
				has_decimal = true;
		}
		i++;
	}
	return (true);
}

bool	have_duplicates(char *s)
{
    int i;
	int	j;

	i = 0;
	while (s[i])
	{
		j = i + 1;
		while (s[j])
		{
			if (s[j] == s[i] && (s[i] < '0' || s[i] > '9'))
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

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
