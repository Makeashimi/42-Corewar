/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 17:45:56 by thedupuy          #+#    #+#             */
/*   Updated: 2018/03/07 17:02:25 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "../../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include "../../op.h"

typedef struct		s_champ
{
	int				n_p;
	int				size;
	unsigned char	name[PROG_NAME_LENGTH + 1];
	unsigned char	com[COMMENT_LENGTH + 1];
	unsigned char	*code;
	int				adr;
	struct s_champ	*next;
}					t_champ;

typedef struct		s_cor
{
	int				ver[3];
	int				player;
	int				inst;
	int				pc;
	int				pc2;
	int				reg[16];
	int				param[5];
	int				live;
	int				carry;
	int				ptr;
	int				count_t;
	struct s_cor	*next;
}					t_cor;

typedef struct		s_data
{
	int				(*f2[4])(struct s_data *, t_cor *);
	void			(*f[16])(struct s_data *, t_cor *);
	unsigned char	*arene;
	t_champ			*champ;
	t_cor			*proc;
	int				dump;
	int				vis;
	int				n;
	int				tour;
	int				c_n[4];
	int				nb_champ;
	int				ctd;
	int				nbr_c;
	int				last_l;
	int				nb_champ2;
}					t_data;

void				ft_carry(t_cor *proc, int i);
int					parse_shell(t_data *data, int ac, char **av, int i);
int					create_champ(unsigned char tab[], int n,
					t_data *data, int x);
int					take_champ(char **av, int i, t_data *data);
int					take_nb_champ(char **av, int *i, t_data *data, int ac);
int					take_opt(char **av, t_data *data, int *i, int ac);

int					launch_champ(t_data *data);
void				add_champ(t_champ *new, t_data *data);
t_champ				*new_champ();
t_data				*init_data();
void				init_champ(t_data *data);

int					push_er(char *s);
void				print_tab(const void *addr, size_t size, size_t i);

int					check_player(t_data *data);
void				check_to_die(t_data *data);
int					check_nb_live(t_data *data);
void				check_live(t_data *data, t_cor *tmp, t_cor *tmp2);
int					ft_take_name_com(t_champ *c, unsigned char tab[], int n);

int					ft_count(t_cor *proc, int p);
int					check_reg(t_data *data, t_cor *ptr, int p);

int					add_proc(t_cor *proc, t_data *data);
t_cor				*new_proc(t_champ *champ);
void				print_proc(t_cor *proc, t_data *data);
void				init_instruction(t_data *data);

void				check_inst(t_cor *proc, t_data *data);
void				battle(t_data *data);

void				my_add(t_data *data, t_cor *proc);
void				my_aff(t_data *data, t_cor *proc);
void				my_and(t_data *data, t_cor *proc);
void				my_fork(t_data *data, t_cor *proc);
void				my_zjmp(t_data *data, t_cor *proc);
void				my_ld(t_data *data, t_cor *proc);
void				my_lfork(t_data *data, t_cor *proc);
void				my_live(t_data *data, t_cor *proc);
void				my_lld(t_data *data, t_cor *proc);
void				my_lldi(t_data *data, t_cor *proc);
void				my_or(t_data *data, t_cor *proc);
void				my_st(t_data *data, t_cor *proc);
void				my_sti(t_data *data, t_cor *proc);
void				my_sub(t_data *data, t_cor *proc);
void				my_xor(t_data *data, t_cor *proc);
void				my_ldi(t_data *data, t_cor *proc);

void				cal_ocp(t_cor *proc, t_data *data);
int					rev_end(int val, char size);

int					take_ind(t_data *data, t_cor *proc);
int					take_dir(t_data *data, t_cor *proc);
int					take_dir_short(t_data *data, t_cor *proc);
int					take_reg(t_data *data, t_cor *proc);

void				print_mem(const void *addr, size_t size, size_t i);

#endif
