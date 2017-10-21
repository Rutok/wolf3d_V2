/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sc_intro.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboste <nboste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 10:29:00 by nboste            #+#    #+#             */
/*   Updated: 2017/10/21 11:47:04 by nboste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SC_INTRO_H
# define SC_INTRO_H

# include "wolf3d.h"

typedef struct	s_scintro
{
	SDL_Texture		*logo;
	SDL_Texture		*enter;
}				t_scintro;

#endif
