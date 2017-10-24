/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboste <nboste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 12:36:26 by nboste            #+#    #+#             */
/*   Updated: 2017/10/23 22:22:39 by nboste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_H
# define TEXTURE_H

# include <SDL.h>

typedef struct	s_texture
{
	SDL_Surface		**surfaces;
	int				nb;
}				t_texture;

t_texture	load_textures(void);

#endif
