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
# include "../../op.h"

# define op_live		1
# define op_ld			2
# define op_st			3
# define op_add			4
# define op_sub			5
# define op_and			6
# define op_or			7
# define op_xor			8
# define op_zjmp		9
# define op_ldi			10
# define op_sti			11
# define op_fork		12
# define op_lld			13
# define op_lldi		14
# define op_lfork		15
# define op_aff			16

typedef struct		s_champ
{
	int				n_p;
	int				size;
	int				size_nm;
	int				size_cm;
	unsigned char	*name;
	unsigned char	*com;
	unsigned char	*code;
	int				adr;
	struct s_champ	*next;
}					t_champ;


typedef struct		s_cor
{
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
	int				verb;
	int				n;
	int				tour;
	int				c_n[4];
	int				nb_champ;
	int				ctd;
	int				nbr_c;
	int				last_l;
}					t_data;

int					parse_shell(t_data *data, int ac, char **av);
int					create_champ(unsigned char tab[], int n, t_data *data, int x);
int					take_champ(char **av, int i, t_data *data);
int					take_nb_champ(char **av, int *i, t_data *data);
int					take_dump(char *av, t_data *data);

int					launch_champ(t_data *data);
void				add_champ(t_champ *new, t_data *data);
t_champ				*new_champ();
t_data				*init_data();
void				init_champ(t_data *data);

int					ft_take_champ(unsigned char *tab, int i);
void 				print_tab(const void *addr, size_t size);

int					check_player(t_data *data);
void				check_to_die(t_data *data);
int					check_nb_live(t_data *data);
void				check_live(t_data *data, t_cor *tmp, t_cor *tmp2);
int					ft_take_name_com(t_champ *champ, unsigned char tab[]);

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


//my_aff
//my_lld
//my_lldi
//my_ldi















#endif