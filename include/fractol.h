/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 16:15:48 by annabrag          #+#    #+#             */
/*   Updated: 2024/03/17 23:59:21 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

/******************************************************************************\
 * LIBRAIRIES
\******************************************************************************/

# include "../libft/include/libft.h"
# include "../libft/include/ft_printf.h"
# include "defines.h"

# include "../mlx/mlx.h"

# include "X11/X.h"
# include "X11/keysym.h"
# include <math.h>
# include <stdbool.h>

/******************************************************************************\
 * STRUCTS
\******************************************************************************/

/* Endianness : Big-endian (BE) + Little-endian (LE)
 * 
 * BE stores the big-end first (reading left->right)
 * LE stores the little-end first (reading right->left)
 * 
 * Least Significant Byte (LSbyte) : smallest position
 * Most Significant Byte (MSbyte) : most significant position
 * 
 * so...
 * BE stores data MSbyte first
 * LE stores data MSbyte last
*/

typedef	struct	s_img
{
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}				t_img;

typedef struct	s_complex
{
	double	real;
	double	imagin;
}				t_complex;

typedef struct s_index
{
	int		x;
	int		y;
}			t_index;

typedef	struct	s_data
{
	void	*mlx_co;
	void	*win;
	t_img	img;
	char	*kind;
	double	max_iter;
	double	zoom;
	t_index	i;
	double	j_real;
	double	j_imagin;
	double	esc_val;
}				t_data;

/******************************************************************************\
 * FUNCTIONS
\******************************************************************************/

double		atod(char *s);
bool		global_check_successful(char **argv);
void		*fmemset_struct(void *s, int c, size_t n);
void		show_fparams(void);

void		init_mlx(t_data *fractal);
void		init_img(t_data *fractal);
void		init_complex(t_complex nbr);
void		init_fractal(t_data *fractal);
void		init_data(t_data *fractal);

void		handle_mlx_hooks(t_data *fractal);
int			put_pixels_in_img(t_img *img, t_data *fractal, int x, int color);
void		handle_pixels(t_data *fractal);
double		scale(double n, double new_min, double new_max, double old_max);

void    	del_win(t_data *fractal);
void    	del_img(t_data *fractal);
int			del_display(t_data *fractal);

t_complex	z_sqrt(t_complex z);
t_complex	sum(t_complex z, t_complex c);

void		create_cplan(t_data *fractal, t_complex *z, t_complex *c);
void		draw(t_data *fractal);
void		mandelbrot(t_data *fractal);
void		julia(char **argv, t_data *fractal);

#endif