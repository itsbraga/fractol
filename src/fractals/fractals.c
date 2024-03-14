/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 12:15:54 by annabrag          #+#    #+#             */
/*   Updated: 2024/03/14 17:20:13 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

void	draw(t_fdata *fractal)
{
	fractal->i.y = 0;
	while (fractal->i.y < WIN_HEIGHT)
	{
		fractal->i.x = 0;
		while (fractal->i.x < WIN_WIDTH)
		{
			// function that handle pixels
			fractal->i.x++;
		}
		fractal->i.y++;
	}
	mlx_put_image_to_window(fractal->mlx_co, fractal->win, 
		fractal->img.img_ptr, 0, 0);
}

void	mandelbrot(t_fdata *fractal)
{
	init_fractal(fractal);
	mlx_loop(fractal->mlx_co);
}

void	julia(t_fdata *fractal)
{
	init_fractal(fractal);
	mlx_loop(fractal->mlx_co);
}
