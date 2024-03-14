/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 16:07:06 by annabrag          #+#    #+#             */
/*   Updated: 2024/03/14 17:32:09 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

void	init_img(t_fdata *fractal)
{
	fractal->img.img_ptr = NULL;
	fractal->img.addr = NULL;
	fractal->img.bpp = 0;
	fractal->img.line_len = 0;
	fractal->img.endian = 0;
}

void	init_mlx(t_fdata *fractal)
{
	char	*title;

	title = ft_strjoin("Fract-ol ➔ ", fractal->kind);
	init_img(fractal);
	fractal->mlx_co = mlx_init();
	if (!fractal->mlx_co)
	{
		ft_printf(BOLD RED "MiniLibX connection failed!\n");
		exit(1);
	}
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
	fractal->max_iter = 0.0;
	fractal->zoom = 0.0;
	fractal->i.x = 0;
	fractal->i.y = 0;
}
