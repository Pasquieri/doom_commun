/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putPixel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyfelbac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 13:52:59 by cyfelbac          #+#    #+#             */
/*   Updated: 2019/04/26 16:57:54 by cyfelbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../editor.h"

void	put_pixel_to_img(t_img *img, int width, t_point point, int color)
{
	img->data[point.y * width + point.x] = color;
}
