/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 16:15:48 by annabrag          #+#    #+#             */
/*   Updated: 2024/03/14 17:22:08 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H

/******************************************************************************\
 * LIBRAIRIES
\******************************************************************************/

# include "../../libft/include/libft.h"
# include "../../libft/include/ft_printf.h"
# include "defines_bonus.h"

# include "../../mlx/mlx.h"

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

typedef struct	s_index
{
	int		x;
	int		y;
}				t_index;

typedef	struct	s_fdata
{
	void	*mlx_co;
	void	*win;
	t_img	img;
	char	*kind;
	double	max_iter;
	double	zoom;
	t_index	i;
}				t_fdata;

/******************************************************************************\
 * FUNCTIONS
\******************************************************************************/

void		init_mlx(t_fdata *fractal);
void		init_img(t_fdata *fractal);
void    	del_win(t_fdata *fractal);
void    	del_img(t_fdata *fractal);
void		del_display(t_fdata *fractal);
int			key_hook(int keycode, t_fdata *fractal);
int			mouse_hook(int keycode, t_fdata *fractal);
void		put_pixel_in_img(t_img *img, t_fdata *fractal, int color);

double		scale(double old_max, double new_max, double n, double new_min);

t_complex	z_square(t_complex z);
t_complex	sum(t_complex z, t_complex c);

double		atod(char *s);

void		init_fractal(t_fdata *fractal);
void		draw(t_fdata *fractal);
void		init_complex(t_complex nbr);

#endif