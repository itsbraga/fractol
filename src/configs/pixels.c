/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:55:00 by annabrag          #+#    #+#             */
/*   Updated: 2024/03/14 17:36:51 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

void    put_pixels_in_img(t_img *img, t_fdata *fractal, int color)
{
	char	*res;

	if (fractal->i.x < 0 || fractal->i.x >= img->line_len || fractal->i.y < 0
		|| fractal->i.y >= WIN_HEIGHT)
		return ;
	res = img->addr + (fractal->i.y * img->line_len + fractal->i.x 
            * (img->bpp / 8));
	*(unsigned int *)res = color;
}

void	handle_julia(t_fdata *fractal, t_complex *z, t_complex *c)
{
	if (!ft_strncmp(fractal->kind, "julia", 5))
	{
		z->real = scale(fractal->i.x, -2, 2, WIN_WIDTH) * fractal->zoom;
		z->imagin = scale(fractal->i.y, 2, -2, WIN_HEIGHT) * fractal->zoom;
		c->real = fractal->j_real;
		c->imagin = fractal->j_imagin;
	}
	else
	{
		z->real = 0.0;
		z->imagin = 0.0;
		c->real = scale(fractal->i.x, -2, 2, WIN_WIDTH) * fractal->zoom;
		c->imagin = scale(fractal->i.y, 2, -2, WIN_HEIGHT) * fractal->zoom;
	}
}

void	handle_pixels(t_fdata *fractal, int color)
{
	int			i;
	t_complex	z;
	t_complex	c;
	
	i = 0;
	while (i < fractal->max_iter)
	{
		z = sum(z_sqrt(z), c);
		if ((z.real * z.real) + (z.imagin * z.imagin));
	}
}
