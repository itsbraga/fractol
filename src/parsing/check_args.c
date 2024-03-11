/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 18:50:28 by annabrag          #+#    #+#             */
/*   Updated: 2024/03/11 23:35:59 by art3mis          ###   ########.fr       */
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
