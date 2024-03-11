/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 16:07:06 by annabrag          #+#    #+#             */
/*   Updated: 2024/03/11 23:23:56 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

void	init_img(t_fdata *fractal)
{
	fractal->img.img_ptr = NULL;
	fractal->img.addr = NULL;
	fractal->img.bits_per_pixel = 0;
	fractal->img.line_length = 0;
	fractal->img.endian = 0;
}

void	init_mlx(t_fdata *fractal)
{

	init_img(fractal);
	fractal->mlx_co = mlx_init();
	if (!fractal->mlx_co)
	{
		ft_printf(BOLD RED "MinilibX connection failed!\n");
		exit(1);
	}
	fractal->win = mlx_new_window(fractal->mlx_co, WIDTH, HEIGHT, 
					fractal->kind);
	if (!fractal->win)
		destroy_win(fractal);
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_co, WIDTH, HEIGHT);
	if (!fractal->img.img_ptr)
		destroy_img(fractal);
	fractal->img.addr = mlx_get_data_addr(fractal->img.img_ptr,
			&fractal->img.bits_per_pixel,
			&fractal->img.line_length,
			&fractal->img.endian);
}

void	init_complex(t_complex nbr)
{
	nbr.real = 0.0;
	nbr.imagin = 0.0;
}

void	init_fractal(t_fdata *fractal)
{
	fractal->mlx_co = NULL;
	fractal->win = NULL;
	fractal->kind = NULL;
	fractal->zoom = 0.0;
}
