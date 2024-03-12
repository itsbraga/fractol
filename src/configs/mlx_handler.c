/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:29:29 by annabrag          #+#    #+#             */
/*   Updated: 2024/03/12 18:15:00 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

void    destroy_win(t_fdata *fractal)
{
    mlx_destroy_window(fractal->mlx_co, fractal->win);
	free(fractal->mlx_co);
    fractal->mlx_co = NULL;
    ft_printf(BOLD GREEN "Window successfully destroyed.\n");
	exit(1);
}

void    destroy_img(t_fdata *fractal)
{
    mlx_destroy_image(fractal->mlx_co, fractal->img.img_ptr);
    mlx_destroy_window(fractal->mlx_co, fractal->win);
	free(fractal->mlx_co);
    fractal->mlx_co = NULL;
    ft_printf(BOLD GREEN "Image and window successfully destroyed.\n");
	exit(1);
}

void    handle_close(t_fdata *fractal)
{
    mlx_destroy_image(fractal->mlx_co, fractal->img.img_ptr);
    mlx_destroy_window(fractal->mlx_co, fractal->win);
    mlx_destroy_display(fractal->mlx_co);
    free(fractal->mlx_co);
    fractal->mlx_co = NULL;
    ft_printf(BOLD GREEN "Exited the program cleanly with the ESC key\n");
	exit(1);
}

int close_with_esc_key(int keycode, t_fdata *fractal)
{
    // printf("touche echap: %d\n", keycode);
    if (keycode == 65307)
        handle_close(fractal);
    return (EXIT_SUCCESS);
}
