/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 16:15:48 by annabrag          #+#    #+#             */
/*   Updated: 2024/03/08 19:04:30 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/include/libft.h"
# include "../libft/include/ft_printf.h"

# include "../minilibx-linux/mlx.h"
# include "X11/X.h"
# include "X11/keysym.h"
# include <math.h>
# include <stdbool.h>

# define WIDTH 1920
# define HEIGHT 1080

/* Endianness is represented in two ways : Big-endian (BE) and Little-endian (LE)
 * 
 * BE stores the big-end first (reading left->right)
 * LE stores the little-end first (reading right->left)
 * 
 * The byte holding the smallest position is the Least Significant Byte (LSbyte)
 * 					the most significant position is the Most Significant Byte (MSbyte)
 * The bit holding the smallest position is the Least Significant Bit (LSbit)
 * 				   the most significant bit position is the Most Significant Bit (MSbit)
 * 
 * so...
 * BE stores data MSbyte first
 * LE stores data MSbyte last
*/

typedef	struct	s_img
{
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef	struct	s_fractal
{
	void	*win;
	t_img	img;
	char	*kind;
	void	*mlx_co;
}				t_fractal;

typedef struct	s_complex
{
	double	real;
	double	imagin;
}				t_complex;

#endif