/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 12:15:54 by annabrag          #+#    #+#             */
/*   Updated: 2024/03/18 00:00:53 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

void	draw(t_data *fractal)
{
	while (fractal->i.y < WIN_HEIGHT)
	{
		fractal->i.x = 0;
		while (fractal->i.x < WIN_WIDTH)
		{
			handle_pixels(fractal);
			fractal->i.x++;
		}
		fractal->i.y++;
	}
	mlx_put_image_to_window(fractal->mlx_co, fractal->win, 
		fractal->img.img_ptr, 0, 0);
}
