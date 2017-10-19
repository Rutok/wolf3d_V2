/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboste <nboste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 07:21:59 by nboste            #+#    #+#             */
/*   Updated: 2017/10/19 07:37:19 by nboste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "wolf3d.h"

typedef enum	e_sceneid
{
	sc_intro,
	sc_basic,
	sc_basic2,
	sc_gameover,
	sc_quit
}				t_sceneid;

t_scene			*init_sc_intro(void);

t_scene			*init_sc_basic(void);

t_scene			*init_sc_basic2(void);

t_scene			*init_sc_gameover(void);

t_scene			*init_sc_quit(void);

#endif
