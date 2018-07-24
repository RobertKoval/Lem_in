/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkoval <rkoval@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 15:04:18 by rkoval            #+#    #+#             */
/*   Updated: 2018/07/10 11:53:12 by rkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	ft_reset_graph(t_data *app)
{
	t_qnode *v;

	v = app->graph.front;
	while (v)
	{
		v->val.vertex->predecessor = NULL;
		v->val.vertex->dist = MAX_UINT64;
		v->val.vertex->visited = 0;
		v = v->next;
	}
}

int		ft_restore_the_path(t_vertex *end, t_data *app)
{
	t_queue		*path;
	t_vertex	*po;

	if (end->predecessor == NULL)
		return (0);
	path = ft_init_queue();
	po = end->predecessor;
	while (po)
	{
		if (po->target == 1)
		{
			ft_enqueu(path, end, NULL, NULL);
			break ;
		}
		ft_preenqueu(path, po, NULL);
		po->locked = 1;
		po = po->predecessor;
	}
	if (path->front)
	{
		ft_enqueu(&app->paths, NULL, path, NULL);
		return (1);
	}
	return (0);
}

void	ft_bfs(t_vertex *start)
{
	t_queue		queue;
	t_vertex	*tmp;
	t_edge		*e;

	queue = (t_queue){.front = NULL};
	ft_enqueu(&queue, start, NULL, NULL);
	while (queue.front)
	{
		tmp = queue.front->val.vertex;
		tmp ? 0 : ft_error();
		ft_dequeu(&queue, 0);
		e = tmp->edges;
		while (e)
		{
			if ((!e->vertex->locked && !e->vertex->visited))
			{
				e->vertex->visited = 1;
				e->vertex->predecessor = tmp;
				ft_enqueu(&queue, e->vertex, NULL, NULL);
			}
			e = e->next;
		}
	}
}

int		ft_doubled_path(t_queue *paths)
{
	t_qnode *path;
	t_qnode *p2;

	path = paths->front;
	while (path)
	{
		p2 = path->next;
		while (p2)
		{
			if (path->val.queue->front->val.vertex->id ==
				p2->val.queue->front->val.vertex->id)
			{
				ft_dequeu(paths, 0);
				return (1);
			}
			p2 = p2->next;
		}
		path = path->next;
	}
	return (0);
}
