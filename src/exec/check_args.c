/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 18:50:28 by annabrag          #+#    #+#             */
/*   Updated: 2024/03/12 19:02:12 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

// adapter pour le projet (check nb apres , ou .)
// grosso modo, les doublons de symboles autres que chiffres
static bool	is_only_double(char *s)
{
	int	i;

	i = 0;
    if (s[i] == '-')
        i++;
	while (s[i] && ft_isdigit(s[i]))
		i++;
	if (s[i] && !(s[i] == '.' || s[i] == ','))
		return (false);
	return (true);
}

static bool have_duplicates(char *s)
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
	int		j;
	double	second;

	j = 1;
	second = 0;
	while (s[i] && (s[i] >= 48 && s[i] <= 57))
	{
		j /= 10;
		second = second * 10 + (s[i] - 48) * j;
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
	while (s[i] && s[i] == 32 || (s[i] >= 9 && s[i] <= 13))
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
