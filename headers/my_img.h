/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_img.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrondi <magrondi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 00:30:40 by magrondi          #+#    #+#             */
/*   Updated: 2025/01/24 00:31:15 by magrondi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_IMG_H
# define MY_IMG_H

typedef struct s_my_img
{
	void	*ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_my_img;

#endif