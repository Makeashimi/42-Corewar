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
# include <fcntl.h>
# include <stdio.h>

typedef struct		s_champ
{
	int				n_p;
	int				size;
	int				size_nm;
	int				size_cm;
	unsigned char	*name;
	unsigned char	*com;
	unsigned char	*code;
	unsigned char	*adr;
	struct s_champ	*next;
}					t_champ;

typedef struct		s_cor
{
	void			*inst;
	struct s_cor	*next;
	int				count_t;
}					t_cor;

typedef struct		s_data
{
	unsigned char	*arene;
	t_champ			*champ;
	t_cor			*proc;
	int				dump;
	int				verb;
	int				n;
	int				c_n[4];
	int				nb_champ;
}					t_data;

int					parse_shell(t_data *data, int ac, char **av);
int					create_champ(unsigned char tab[], int n, t_data *data, int x);
int					take_champ(char **av, int i, t_data *data);
int					take_nb_champ(char **av, int *i, t_data *data);
int					take_dump(char *av, t_data *data);

void				add_champ(t_champ *new, t_data *data);
t_champ				*new_champ();
t_data				*init_data();
void				init_champ(t_data *data);
void				init_champ_nb(t_data *data);

int					ft_take_champ(unsigned char *tab, int i);
void 				print_tab(const void *addr, size_t size);

int					check_player(t_data *data);
int					ft_take_name_com(t_champ *champ, unsigned char tab[]);

#endif
