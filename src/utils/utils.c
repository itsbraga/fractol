/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 23:39:10 by annabrag          #+#    #+#             */
/*   Updated: 2024/03/17 23:46:50 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

void	show_fparams(void)
{
	ft_printf(BOLD "=========================== HELP MENU ");
	ft_printf("===========================");
	ft_printf(RESET "\n\n Here's how to use this program depending on ");
	ft_printf("its fractal set:\n\n");
	ft_printf("%s%s", BOLD PURPLE "Mandelbrot\t", RESET "--> ./fractol \
mandelbrot\n");
	ft_printf("%s%s", BOLD PINK "Julia\t\t", RESET "--> ./fractol julia \
[double] [double]\n\n");
	ft_printf(BOLD "======================= EXAMPLES =======================");
	ft_printf("\n\n");
	ft_printf(ITAL YELLOW "(For Julia sets only)\n");
	ft_printf("Elephant valley\t--> ./fractol julia 0.0 0.3\n");
}

void	*fmemset_struct(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*fractal;

	i = 0;
	fractal = s;
	while (i < n)
	{
		*(fractal + i) = c;
		i++;
	}
	return (fractal);
}
