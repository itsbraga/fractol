/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:55:00 by annabrag          #+#    #+#             */
/*   Updated: 2024/03/12 17:57:29 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

void    pixel_put(t_img *img, t_fdata *fractal, int color)
{
	char	*dest;

	dest = img->addr + (fractal->y * img->line_length + fractal->x 
            * (img->bits_per_pixel / 8));
	*(unsigned int *)dest = color;
}
