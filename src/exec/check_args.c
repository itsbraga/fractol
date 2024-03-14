/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 18:50:28 by annabrag          #+#    #+#             */
/*   Updated: 2024/03/14 14:19:28 by annabrag         ###   ########.fr       */
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

bool	global_check_successful(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (!is_only_double(argv[i]))
		{
			write(STDERR_FILENO, "Error: Invalid argument.\n", 6);
			return (false);
		}
		i++;
	}
	if (have_duplicates(argv) == true)
		return (write(STDERR_FILENO, "Error: Contains duplicates.\n", 6), false);
	return (true);
}

