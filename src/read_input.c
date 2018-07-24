/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkoval <rkoval@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 14:50:27 by rkoval            #+#    #+#             */
/*   Updated: 2018/07/10 15:20:37 by rkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	ft_read_input(t_data *app)
{
	short int	stage;
	short int	target;

	stage = 1;
	target = 0;
	while (get_next_line(0, &app->line) > 0)
	{
		ft_enqueu(&app->file, NULL, NULL, app->line);
		if (ft_validate_comment(app->line, &target, stage))
			;
		else if (stage == 1 && ft_save_ants(app))
			stage = 2;
		else if (stage == 2 && ft_validate_room(app->line))
			ft_save_room(app, &target);
		else if (ft_validate_tunel(app->line))
		{
			stage = 3;
			ft_save_tunel(app);
		}
		else
			ft_error();
		ft_strdel(&app->line);
	}
}
