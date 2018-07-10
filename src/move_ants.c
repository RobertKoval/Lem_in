/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkoval <rkoval@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 11:04:50 by rkoval            #+#    #+#             */
/*   Updated: 2018/07/10 15:19:41 by rkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void	ft_move(t_ant *ants)
{
	t_ant *a;

	a = ants;
	while (a)
	{
		if (a->room && a->room->val.vertex->target != 2)
		{
			a->room->val.vertex->ant = 0;
			a->room = a->room->next;
		}
		a = a->next;
	}
}

static int	ft_not_all(t_ant *ants)
{
	t_ant *a;

	a = ants;
	while (a)
	{
		if (!a->finished)
			return (1);
		a = a->next;
	}
	return (0);
}

static void	ft_m2(t_ant *ap, t_qnode *v, t_queue *paths)
{
	while (ap)
	{
		v = paths->front;
		if (ap->room == NULL)
		{
			while (v)
			{
				if (!v->val.queue->front->val.vertex->ant ||
					v->val.queue->front->val.vertex->target == 2)
				{
					ap->room = v->val.queue->front;
					v->val.queue->front->val.vertex->ant = 1;
					break ;
				}
				v = v->next;
			}
		}
		ap = ap->next;
	}
}

void		ft_move_ants(t_data *data, t_queue *paths)
{
	t_ant	*ants;
	t_ant	*ap;
	t_qnode	*v;

	v = NULL;
	ants = data->all_ants;
	if (!paths->front)
		ft_error();
	ft_print_queue(&data->file);
	while (ft_not_all(ants))
	{
		ap = ants;
		ft_m2(ap, v, paths);
		ft_print_ants(ants);
		ft_move(ants);
	}
	ft_print_ants(ants);
}
