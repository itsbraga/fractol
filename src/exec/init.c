/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 16:07:06 by annabrag          #+#    #+#             */
/*   Updated: 2024/03/08 19:14:56 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

void	init_img(t_fractal *fractal)
{
	fractal->img.img_ptr = NULL;
	fractal->img.addr = NULL;
	fractal->img.bits_per_pixel = 0;
	fractal->img.line_length = 0;
	fractal->img.endian = 0;
}

void	init_mlx(t_fractal *fractal)
{

	init_img(fractal);
	fractal->mlx_co = mlx_init();
	if (!fractal->mlx_co)
		exit(1);
	fractal->win = mlx_new_window(fractal->mlx_co, WIDTH, HEIGHT, fractal->kind);
	if (!fractal->win)
	{
		mlx_destroy_window(fractal->mlx_co, fractal->win);
		free();
		exit(1);
	}
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_co, WIDTH, HEIGHT);
	if (!fractal->img.img_ptr)
	{
		mlx_destroy_image(fractal->mlx_co, fractal->img.img_ptr);
		exit(1);
	}
	fractal->img.addr = mlx_get_data_addr(fractal->img.img_ptr,
			&fractal->img.bits_per_pixel,
			&fractal->img.line_length,
			&fractal->img.endian);
//	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
//	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
//	mlx_loop(mlx);
}

//	ft_init_data(fractal);
//	ft_init_events(fractal);

void	init_complex(t_complex nbr)
{
	nbr.real = 0.0;
	nbr.imagin = 0.0;
}

void	init_fractal(t_fractal *fractal)
{
	fractal->mlx_co = NULL;
	fractal->win = NULL;
	fractal->kind = NULL;
}
