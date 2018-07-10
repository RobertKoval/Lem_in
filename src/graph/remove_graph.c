/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_graph.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkoval <rkoval@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 20:28:31 by rkoval            #+#    #+#             */
/*   Updated: 2018/07/10 14:56:44 by rkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

void	ft_remove_edge(t_vertex *v)
{
	t_edge *e;
	t_edge *t;

	if (!v)
		return ;
	e = v->edges;
	v->edges = NULL;
	while (e)
	{
		t = e->next;
		free(e);
		e = t;
	}
}
void	ft_remove_graph(t_queue *graph)
{
	while (graph->front)
	{
		ft_remove_edge(graph->front->val.vertex);
		free(graph->front->val.vertex->name);
		free(graph->front->val.vertex);
		ft_dequeu(graph, 0);
	}
}
