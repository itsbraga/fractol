/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 05:12:58 by annabrag          #+#    #+#             */
/*   Updated: 2024/03/17 23:49:40 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	create_cplan(t_data *fractal, t_complex *z, t_complex *c)
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

int	main(int argc, char **argv)
{
	t_data	fractal;
	
	if (argc <= 1)
		exit(1);
	fmemset_struct(&fractal, 0, sizeof(t_data));
	ft_strlowcase(argv[1]);
	if (argc == 3)
	{
		ft_printf(BOLD YELLOW "Error: missing param for Julia set.\n");
		return (EXIT_FAILURE);
	}
	if (argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10))
		mandelbrot(&fractal);
	if (argc == 4 && !ft_strncmp(argv[1], "julia", 5))
	{
		if (!global_check_successful(argv))
			exit(1);
		julia(argv, &fractal);
	}
	return (EXIT_SUCCESS);
}

// int	main(int argc, char **argv)
// {
// 	t_data	fractal;
	
// 	if (argc <= 1)
// 	{
// 		show_fparams();
// 		// fonction qui affiche la liste des paramètres disponibles
// 		// et quitte proprement
// 	}
// 	fmemset_struct(&fractal, 0, sizeof(t_data));
// 	fmemset_struct(&fractal.i, 0, sizeof(t_index));
// 	ft_strlowcase(argv[1]);
// 	if (argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10))
// 		mandelbrot(&fractal);
// 	if (argc == 3)
// 	{
// 		ft_printf(BOLD YELLOW "Error: missing param for Julia set.\n");
// 		return (EXIT_FAILURE);
// 	}
// 	if (argc == 4 && !ft_strncmp(argv[1], "julia", 5))
// 	{
// 		if (!global_check_successful(argv))
// 			exit(1);
// 		julia(argv, &fractal);
// 	}
// 	return (EXIT_SUCCESS);
// }
