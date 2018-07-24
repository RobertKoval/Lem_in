/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkoval <rkoval@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 14:51:36 by rkoval            #+#    #+#             */
/*   Updated: 2018/07/10 15:21:13 by rkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_vertex	*ft_get_start_vertex(t_data *app)
{
	t_qnode *po;

	po = app->graph.front;
	while (po)
	{
		if (po->val.vertex->target == 1)
			return (po->val.vertex);
		po = po->next;
	}
	ft_error();
	return (NULL);
}

t_vertex	*ft_get_end_vertex(t_data *app)
{
	t_qnode *po;

	po = app->graph.front;
	while (po)
	{
		if (po->val.vertex->target == 2)
			return (po->val.vertex);
		po = po->next;
	}
	ft_error();
	return (NULL);
}

static void	ft_clean_all(t_queue *paths)
{
	t_qnode *po;
	t_qnode *to;

	po = paths->front;
	while (po)
	{
		to = po->next;
		ft_remove_queue(po->val.queue, 0);
		po = to;
	}
	po = paths->front;
	while (po)
	{
		ft_dequeu(paths, 0);
		po = paths->front;
	}
}

int			main(void)
{
	t_data	app;

	app = (t_data){.ants = 0, .end = 0, .start = 0};
	ft_read_input(&app);
	ft_validate_vertexes(&app);
	ft_bfs(ft_get_start_vertex(&app));
	while (!ft_doubled_path(&app.paths) &&
			ft_restore_the_path(ft_get_end_vertex(&app), &app))
	{
		ft_reset_graph(&app);
		ft_bfs(ft_get_start_vertex(&app));
	}
	if (!app.paths.rear)
		ft_error();
	app.all_ants = ft_init_ants_list(&app);
	ft_move_ants(&app, &app.paths);
	ft_remove_defined_queue(&app.file, 1);
	ft_remove_ant_list(&app);
	ft_clean_all(&app.paths);
	ft_remove_graph(&app.graph);
	return (0);
}
