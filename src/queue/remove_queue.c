/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_queue.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkoval <rkoval@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 15:45:16 by rkoval            #+#    #+#             */
/*   Updated: 2018/07/10 15:21:44 by rkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

int		ft_dequeu(t_queue *queue, int x)
{
	t_qnode *n;

	if (queue->front == NULL)
		return (0);
	n = queue->front;
	queue->front = n->next;
	if (x == 1)
		ft_strdel(&n->val.str);
	free(n);
	if (queue->front == NULL)
		queue->rear = NULL;
	return (1);
}

void	ft_remove_queue(t_queue *queue, int x)
{
	t_qnode *n;

	n = queue->front;
	while (n)
	{
		ft_dequeu(queue, x);
		n = queue->front;
	}
	free(queue);
}

void	ft_remove_defined_queue(t_queue *queue, int x)
{
	t_qnode *n;

	n = queue->front;
	while (n)
	{
		ft_dequeu(queue, x);
		n = queue->front;
	}
}
