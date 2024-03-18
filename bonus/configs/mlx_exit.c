/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:29:29 by annabrag          #+#    #+#             */
/*   Updated: 2024/03/17 21:08:19 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol_bonus.h"

void    del_win(t_data *fractal)
{
    mlx_destroy_window(fractal->mlx_co, fractal->win);
	free(fractal->mlx_co);
    fractal->mlx_co = NULL;
    ft_printf(BOLD GREEN "Window successfully destroyed.\n");
	exit(1);
}

void    del_img(t_data *fractal)
{
    mlx_destroy_image(fractal->mlx_co, fractal->img.img_ptr);
    mlx_destroy_window(fractal->mlx_co, fractal->win);
	free(fractal->mlx_co);
    fractal->mlx_co = NULL;
    ft_printf(BOLD GREEN "Image and window successfully destroyed.\n");
	exit(1);
}

void    del_display(t_data *fractal)
{
    mlx_destroy_image(fractal->mlx_co, fractal->img.img_ptr);
    mlx_destroy_window(fractal->mlx_co, fractal->win);
    mlx_destroy_display(fractal->mlx_co);
    free(fractal->mlx_co);
    fractal->mlx_co = NULL;
    ft_printf(BOLD GREEN "Exited the program cleanly with the ESC key.\n");
	exit(1);
}

