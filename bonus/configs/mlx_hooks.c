/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:02:44 by annabrag          #+#    #+#             */
/*   Updated: 2024/03/17 21:08:19 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol_bonus.h"

int key_hook(int keycode, t_data *fractal)
{
	//printf("touche echap: %d\n", keycode);
    if (keycode == XK_Escape)
        handle_close(fractal);
    return (EXIT_SUCCESS);
}

int mouse_hook(int mousecode, t_data *fractal)
{
    if (mousecode == MOUSE_WHEEL_UP)
    {
        ft_printf(BOLD BLUE "You're zooming up.\n");
        fractal->zoom += 0.03;
    }
    else if (mousecode == MOUSE_WHEEL_DOWN)
    {
        ft_printf(BOLD BLUE "You're zooming down.\n");
        fractal->zoom -= 0.03;
    }
    return (EXIT_SUCCESS);
}

void	handle_mlx_hooks(t_data *fractal)
{
	mlx_key_hook(fractal->win, key_hook, fractal);
	mlx_hook(fractal->win, 04, (1L<<2), mouse_hook, fractal);
	mlx_hook(fractal->win, 17, (1L<<17), del_display, fractal);
}
