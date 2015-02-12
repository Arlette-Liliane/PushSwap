/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemebiku <aemebiku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 14:20:05 by aemebiku          #+#    #+#             */
/*   Updated: 2015/02/03 14:33:08 by aemebiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PILE_STRUCT_H
# define PILE_STRUCT_H

typedef struct		pile
{
	int				val;
	struct pile		*next;
    struct pile 	*prev;
}					Pile;

typedef struct		list
{
	Pile 			*first;
	Pile 			*last;
}					dblist;

#endif
