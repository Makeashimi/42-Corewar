/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thedupuy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 17:45:56 by thedupuy          #+#    #+#             */
/*   Updated: 2018/01/18 17:45:58 by thedupuy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_WAR
# define CORE_WAR

# include "../../libft/libft.h"


typedef struct		s_cor
{
	int				ntoe; //number_tours_of_execution;
	t_op			op_tab;
	struct s_cor	*next;
}					t_cor;

typedef struct		s_data
{
	t_cor			*proc1;
	t_cor			*proc2;
	t_cor			*proc3;
	t_cor			*proc4;
	int				alive_1;
	int				alive_2;
	int				alive_3;
	int				alive_4;
	void			arene[4096];
	int				ctd; //cycle_to_die//
	int				cy; //cycle//
}					t_data;
