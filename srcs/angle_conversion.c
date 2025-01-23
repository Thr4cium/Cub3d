/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angle_conversion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrondi <magrondi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:15:09 by magrondi          #+#    #+#             */
/*   Updated: 2025/01/24 00:35:07 by magrondi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

float	radians_to_degrees(float radians)
{
	return (radians * (180.0 / M_PI));
}

float	degrees_to_radians(float degrees)
{
	return (degrees * (M_PI / 180.0));
}
