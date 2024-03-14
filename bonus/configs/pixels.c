/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:55:00 by annabrag          #+#    #+#             */
/*   Updated: 2024/03/14 17:22:18 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol_bonus.h"

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

void	handle_pixels(t_img *img, t_fdata *fractal, int color);
