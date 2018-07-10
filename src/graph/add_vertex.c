/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_vertex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkoval <rkoval@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 18:21:12 by rkoval            #+#    #+#             */
/*   Updated: 2018/07/10 14:00:37 by rkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

t_vertex	*ft_init_vertex(short int *target, char *line)
{
	t_vertex	*vertex;
	char		*po;

	po = line;
	if (!(vertex = malloc(sizeof(t_vertex))))
		ft_error();
	*vertex = (t_vertex){.target = *target, .dist = MAX_UINT64, .visited = 0,
			.locked = 0, .ant = 0, .id = 0};
	vertex->name = get_next_word(&po);
	vertex->coor[0] = ft_get_next_int(&po);
	vertex->coor[1] = ft_get_next_int(&po);
	*target = 0;
	return (vertex);
}
