/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrondi <magrondi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 22:51:49 by magrondi          #+#    #+#             */
/*   Updated: 2025/01/27 05:39:02 by magrondi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

# ifndef FOV
#  define FOV 60
# endif

# ifndef FILE_MAX_HEIGHT
#  define FILE_MAX_HEIGHT 250
# endif

# ifndef FILE_MAX_WIDTH
#  define FILE_MAX_WIDTH 250
# endif

# ifndef GREEN
#  define GREEN 0x0000FF00
# endif

# ifndef BONUS
#  define BONUS 0
# endif

# ifndef SCREEN_WIDTH
#  define SCREEN_WIDTH 1280
# endif

# ifndef SCREEN_HEIGHT
#  define SCREEN_HEIGHT 1024
# endif

# ifndef MINIMAP_RANGE
#  define MINIMAP_RANGE 5
# endif

# ifndef MLX_CROSS_CODE
#  define MLX_CROSS_CODE 17
# endif

# ifndef MV_SPEED
#  define MV_SPEED 0.21
# endif

# ifndef ROT_SPEED
#  define ROT_SPEED 0.09
# endif

# ifndef NORTH_ANGLE
#  define NORTH_ANGLE 270
# endif

# ifndef WEST_ANGLE
#  define WEST_ANGLE 180
# endif

# ifndef SOUTH_ANGLE
#  define SOUTH_ANGLE 90
# endif

# ifndef EAST_ANGLE
#  define EAST_ANGLE 0
# endif

# ifndef ONE_DEGREE_IN_RADIANS
#  define ONE_DEGREE_IN_RADIANS 0.0174533
# endif

# ifndef WHITE_COLOR
#  define WHITE_COLOR 0x00FFFFFF
# endif

# ifndef GRAY_COLOR
#  define GRAY_COLOR 0x00A9A9A9
# endif

#endif