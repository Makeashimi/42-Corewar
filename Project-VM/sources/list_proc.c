#include "corewar.h"

t_cor	*new_proc(t_champ *champ)
{
	t_cor	*proc;

	if ((proc = (t_cor *)malloc(sizeof(t_cor))) == NULL)
		return (NULL);
	proc->player = champ->n_p;
	proc->reg[0] = champ->n_p;
	proc->carry = 0;
	proc->live = 0;
	proc->ptr = champ->adr;
	proc->count_t = 0;
	proc->next = NULL;
	return (proc);
}

int		add_proc(t_cor *proc, t_data *data)
{
	t_cor *tmp;

	if (proc == NULL)
		return (-1);
	if (data->proc == NULL)
	{
		data->proc = proc;
		return (1);
	}
	else
	{
		tmp = data->proc;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = proc;
		return (1);
	}
}

void	print_proc(t_cor *proc)
{
	ft_printf("player -> %d\n", proc->player);
	ft_printf("reg [1] = %d\n", proc->reg[0]);
	ft_printf("reg [2] = %d\n", proc->reg[1]);
	ft_printf("reg [3] = %d\n", proc->reg[2]);
	ft_printf("reg [4] = %d\n", proc->reg[3]);
	ft_printf("reg [5] = %d\n", proc->reg[4]);
	ft_printf("reg [6] = %d\n", proc->reg[5]);
	ft_printf("reg [7] = %d\n", proc->reg[6]);
	ft_printf("reg [8] = %d\n", proc->reg[7]);
	ft_printf("reg [9] = %d\n", proc->reg[8]);
	ft_printf("reg [10] = %d\n", proc->reg[9]);
	ft_printf("reg [11] = %d\n", proc->reg[10]);
	ft_printf("reg [12] = %d\n", proc->reg[11]);
	ft_printf("reg [13] = %d\n", proc->reg[12]);
	ft_printf("reg [14] = %d\n", proc->reg[13]);
	ft_printf("reg [15] = %d\n", proc->reg[14]);
	ft_printf("reg [16] = %d\n", proc->reg[15]);
	ft_printf("carry = %d\n", proc->carry);
	ft_printf("live = %d\n", proc->live);
	ft_printf("nombre de tours = %d\n", proc->count_t);
	proc->ptr = proc->ptr + 0xFFE;
	ft_printf("pointeur = %#x\n", *proc->ptr);
	ft_putchar('\n');
}