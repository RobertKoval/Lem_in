/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_ants.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkoval <rkoval@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 17:01:46 by rkoval            #+#    #+#             */
/*   Updated: 2018/07/10 13:54:24 by rkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		ft_save_ants(t_data *app)
{
	long long int	a;
	int				i;

	i = 0;
	if (!app->line || app->line[0] < '1' || app->line[0] > '9')
		return (0);
	while (app->line[i] != '\0')
	{
		if (app->line[i] < '0' || app->line[i] > '9')
			return (0);
		i++;
	}
	a = ft_llatoi(app->line);
	if (a <= MAX_UINT32)
		app->ants = (unsigned int)a;
	return (1);
}

t_ant	*ft_init_ants_list(t_data *data)
{
	t_ant	*ants;
	t_ant	*po;
	t_uint	i;

	i = 1;
	if (!(ants = malloc(sizeof(t_ant))))
		ft_error();
	*ants = (t_ant){.ant = i++};
	po = ants;
	while (i < data->ants + 1)
	{
		if (!(po->next = malloc(sizeof(t_ant))))
			ft_error();
		po = po->next;
		*po = (t_ant){.ant = i};
		i++;
	}
	return (ants);
}

void	ft_remove_ant_list(t_data *data)
{
	t_ant *po;
	t_ant *to;

	po = data->all_ants;
	while (po)
	{
		to = po->next;
		free(po);
		po = to;
	}
	data->all_ants = NULL;
}

void	ft_print_ants(t_ant *ants)
{
	t_ant	*a;
	int		i;

	i = 0;
	a = ants;
	while (a)
	{
		if (!a->room)
			break ;
		else if (!a->finished)
		{
			if (i > 0)
				ft_printf(" ");
			ft_printf("L%d-%s", a->ant, a->room->val.vertex->name);
			if (a->room->val.vertex->target == 2)
				a->finished = 1;
			i++;
		}
		a = a->next;
	}
	if (i > 0)
		ft_printf("\n");
}
