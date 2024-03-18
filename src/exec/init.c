/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 16:07:06 by annabrag          #+#    #+#             */
/*   Updated: 2024/03/18 00:00:02 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

void	init_mlx(t_data *fractal)
{
	char	*title;

	fmemset_struct(&fractal->img, 0, sizeof(t_img));
	fractal->mlx_co = mlx_init();
	if (!fractal->mlx_co)
	{
		ft_printf(BOLD RED "MiniLibX connection failed!\n");
		exit(1);
	}
	title = ft_strjoin("Ana's fract-ol: ", fractal->kind);
	fractal->win = mlx_new_window(fractal->mlx_co, WIN_WIDTH, WIN_HEIGHT, 
					title);
	if (!fractal->win)
		del_win(fractal);
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_co, WIN_WIDTH, WIN_HEIGHT);
	if (!fractal->img.img_ptr)
		del_img(fractal);
	fractal->img.addr = mlx_get_data_addr(fractal->img.img_ptr,
						&fractal->img.bpp,
						&fractal->img.line_len,
						&fractal->img.endian);
	init_data(fractal);
	handle_mlx_hooks(fractal);
}

void	init_data(t_data *fractal)
{
	fractal->max_iter = 100;
	fractal->zoom = 1.0;
	fractal->esc_val = 4.0;
}

void	mandelbrot(t_data *fractal)
{
	t_complex	z;
	t_complex	c;
	
	fractal->kind = "mandelbrot";
	init_mlx(fractal);
	fmemset_struct(&z, 0, sizeof(t_complex));
	fmemset_struct(&c, 0, sizeof(t_complex));
	draw(fractal);
	mlx_loop(fractal->mlx_co);
}

void	julia(char **argv, t_data *fractal)
{
	t_complex	z;
	t_complex	c;
	
	fractal->kind = "julia";
	init_mlx(fractal);
	fmemset_struct(&z, 0, sizeof(t_complex));
	fmemset_struct(&c, 0, sizeof(t_complex));
	fractal->j_real = atod(argv[2]);
	fractal->j_imagin = atod(argv[3]);
	draw(fractal);
	mlx_loop(fractal->mlx_co);
}
