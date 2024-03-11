/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 22:31:55 by art3mis           #+#    #+#             */
/*   Updated: 2024/03/11 23:20:48 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

void    destroy_win(t_fdata *fractal)
{
    mlx_destroy_window(fractal->mlx_co, fractal->win);
	free(fractal->mlx_co);
    fractal->mlx_co = NULL;
    ft_printf(BOLD GREEN "Window successfully destroyed.\n");
	exit(1);
}

void    destroy_img(t_fdata *fractal)
{
    mlx_destroy_image(fractal->mlx_co, fractal->img.img_ptr);
    mlx_destroy_window(fractal->mlx_co, fractal->win);
	free(fractal->mlx_co);
    fractal->mlx_co = NULL;
    ft_printf(BOLD GREEN"Image and window successfully destroyed.\n");
	exit(1);
}
