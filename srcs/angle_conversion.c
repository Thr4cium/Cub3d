/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angle_conversion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrondi <magrondi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:15:09 by magrondi          #+#    #+#             */
/*   Updated: 2024/12/13 16:30:26 by magrondi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

float	radians_to_degrees(float radians)
{
	return (radians * (180.0 / PI));
}

float	degrees_to_radians(float degrees)
{
	return (degrees * (PI / 180.0));
}
