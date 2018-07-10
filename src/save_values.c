/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_values.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkoval <rkoval@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 18:12:36 by rkoval            #+#    #+#             */
/*   Updated: 2018/07/09 21:53:32 by rkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		ft_save_room(t_data *app, short int *target)
{
	t_vertex *vertex;

	if (*target == 1 && !app->start)
		app->start = 1;
	else if (*target == 2 && !app->end)
		app->end = 1;
	else if ((app->start || app->end) && *target)
		ft_error();
	vertex = ft_init_vertex(target, app->line);
	if (app->graph.front)
		vertex->id = app->graph.rear->val.vertex->id + 1;
	else
		vertex->id = 1;
	ft_enqueu(&app->graph, vertex, NULL, NULL);
}

static void	tuneling(t_vertex *a, t_vertex *b)
{
	t_edge *o;
	t_edge *t;

	if (!(o = malloc(sizeof(t_edge))))
		ft_error();
	*o = (t_edge){.next = a->edges, .vertex = b};
	a->edges = o;
	if (!(t = malloc(sizeof(t_edge))))
		ft_error();
	*t = (t_edge){.next = b->edges, .vertex = a};
	b->edges = t;
}

int			ft_existed_edge(t_vertex *from, t_vertex *to)
{
	t_edge *e;

	if (!from || !to)
		ft_error();
	e = from->edges;
	while (e)
	{
		if (e->vertex->id == to->id)
			return (1);
		e = e->next;
	}
	return (0);
}

int			ft_add_edge(t_queue *graph, char *fn, char *tn)
{
	t_qnode *f;
	t_qnode *t;

	f = graph->front;
	t = graph->front;
	while (f && f->val.vertex && (ft_strcmp(f->val.vertex->name, fn) != 0))
		f = f->next;
	while (t && t->val.vertex && (ft_strcmp(t->val.vertex->name, tn) != 0))
		t = t->next;
	if (f && t && ft_existed_edge(f->val.vertex, t->val.vertex))
		;
	else if (t && f && t->val.vertex && f->val.vertex &&
			f->val.vertex->id != t->val.vertex->id)
		tuneling(f->val.vertex, t->val.vertex);
	else
		ft_error();
	return (1);
}

void		ft_save_tunel(t_data *app)
{
	char **names;

	names = ft_strsplit(app->line, '-');
	if (ft_strcmp(names[0], names[1]) == 0)
		ft_error();
	ft_add_edge(&app->graph, names[0], names[1]);
	free(names[0]);
	free(names[1]);
	free(names);
}
