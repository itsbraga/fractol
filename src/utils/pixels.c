/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:55:00 by annabrag          #+#    #+#             */
/*   Updated: 2024/03/18 00:07:44 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

int    put_pixels_in_img(t_img *img, t_data *fractal, int n, int color)
{
	char	*buffer;

	(void)n;
	if (fractal->i.x < 0 || fractal->i.x >= img->line_len || fractal->i.y < 0
		|| fractal->i.y >= WIN_HEIGHT)
		return (0);
	buffer = img->addr + (fractal->i.y * img->line_len + fractal->i.x 
            * (img->bpp / 8));
	return (*(unsigned int *)buffer = color);
}

void	handle_pixels(t_data *fractal)
{
	int			it;
	int			color;
	t_complex	z;
	t_complex	c;
	
	it = 0;
	create_cplan(fractal, &z, &c);
	while (it < fractal->max_iter)
	{
		z = sum(z_sqrt(z), c);
		if (((z.real * z.real) + (z.imagin * z.imagin)) > fractal->esc_val)
		{
			color = scale(it, 0xFF5BFF, 0x56F1FF, fractal->max_iter);
			put_pixels_in_img(&fractal->img, fractal, fractal->i.x, color);
			put_pixels_in_img(&fractal->img, fractal, fractal->i.y, color);
			break ;
		}
		it++;
	}
	put_pixels_in_img(&fractal->img, fractal, fractal->i.x, 0x000000);
	put_pixels_in_img(&fractal->img, fractal, fractal->i.y, 0x000000);
}
