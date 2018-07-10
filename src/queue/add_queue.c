/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_queue.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkoval <rkoval@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 15:38:34 by rkoval            #+#    #+#             */
/*   Updated: 2018/07/10 15:16:07 by rkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

t_queue	*ft_init_queue(void)
{
	t_queue *node;

	if (!(node = malloc(sizeof(t_queue))))
		ft_error();
	*node = (t_queue){.front = NULL, .rear = NULL};
	return (node);
}

void	ft_preenqueu(t_queue *queue, t_vertex *vertex, t_queue *qq)
{
	t_qnode *n;

	if (!(n = malloc(sizeof(t_qnode))))
		ft_error();
	if (vertex)
		*n = (t_qnode){.val.vertex = vertex};
	else
		*n = (t_qnode){.val.queue = qq};
	if (queue->front == NULL)
	{
		queue->front = n;
		queue->rear = n;
	}
	else
	{
		n->next = queue->front;
		queue->front = n;
	}
}

void	ft_enqueu(t_queue *queue, t_vertex *vertex, t_queue *qq, char *str)
{
	t_qnode *n;

	if (!(n = malloc(sizeof(t_qnode))))
		ft_error();
	if (vertex)
		*n = (t_qnode){.val.vertex = vertex};
	else if (str)
		*n = (t_qnode){.val.str = ft_strdup(str)};
	else
		*n = (t_qnode){.val.queue = qq};
	if (queue->front == NULL)
	{
		queue->front = n;
		queue->rear = n;
	}
	else
	{
		queue->rear->next = n;
		queue->rear = n;
	}
}

void	ft_print_queue(t_queue *queue)
{
	t_qnode *n;

	if (!queue)
		return ;
	n = queue->front;
	while (n)
	{
		ft_printf("%s\n", n->val.str);
		n = n->next;
	}
	ft_printf("\n");
}
