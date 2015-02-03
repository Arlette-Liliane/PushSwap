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

#ifndef PILE_H
# define PILE_H

typedef struct		pile
{
	int				donnee;
	struct pile		*previous;
}					Pile;
