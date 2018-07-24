/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_values.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkoval <rkoval@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 18:09:31 by rkoval            #+#    #+#             */
/*   Updated: 2018/07/10 15:04:17 by rkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		ft_validate_comment(const char *str, short int *target, short int s)
{
	if (!str)
		return (0);
	if (str[0] == '#')
	{
		if (ft_strcmp(str, "##start") == 0)
			s == 2 ? *target = 1 : ft_error();
		else if (ft_strcmp(str, "##end") == 0)
			s == 2 ? *target = 2 : ft_error();
		return (1);
	}
	return (0);
}

int		ft_validate_room(const char *str)
{
	int	i;
	int	spaces;

	i = 0;
	spaces = 0;
	if (!str || str[0] == 'L' || str[0] == '#' || str[0] == '\0')
		return (0);
	while (str[i] != ' ' && str[i])
		i++;
	while (str[i])
	{
		if (str[i] == ' ' && str[i + 1])
			spaces++;
		else if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	if (spaces != 2)
		return (0);
	return (1);
}

int		ft_validate_tunel(const char *str)
{
	int i;
	int line;

	line = 0;
	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '-')
			line++;
		else if (str[i] <= 32)
			return (0);
		i++;
	}
	if (line == 1)
		return (1);
	return (0);
}

void	ft_validate_edges(t_vertex *v)
{
	t_edge *po;
	t_edge *t;

	if (!v)
		ft_error();
	po = v->edges;
	while (po)
	{
		t = po->next;
		while (t)
		{
			if (ft_strcmp(po->vertex->name, t->vertex->name) == 0)
				ft_error();
			t = t->next;
		}
		po = po->next;
	}
}

void	ft_validate_vertexes(t_data *app)
{
	t_qnode *po;
	t_qnode *t;

	if (!app->graph.front)
		ft_error();
	po = app->graph.front;
	while (po)
	{
		ft_validate_edges(po->val.vertex);
		t = po->next;
		while (t)
		{
			if (ft_strcmp(po->val.vertex->name, t->val.vertex->name) == 0 ||
				(po->val.vertex->coor[0] == t->val.vertex->coor[0] &&
				po->val.vertex->coor[1] == t->val.vertex->coor[1]))
				ft_error();
			t = t->next;
		}
		po = po->next;
	}
}
