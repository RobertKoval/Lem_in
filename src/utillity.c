/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utillity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkoval <rkoval@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 18:19:19 by rkoval            #+#    #+#             */
/*   Updated: 2018/07/07 18:21:26 by rkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		ft_error(void)
{
	ft_printf("%{red}ERROR%{eoc}\n");
	exit(1);
}

static void	ft_fucking_norme(int *val, const char *po)
{
	if (*val == 0)
		*val = *po - '0';
	else
	{
		*val *= 10;
		*val += *po - '0';
	}
}

int			ft_get_next_int(char **src)
{
	int		val;
	int		minus;
	char	*po;

	val = 0;
	minus = 0;
	if (!src || !*src || !**src)
		ft_error();
	po = *src;
	while (*po && (*po < '0' || *po > '9') && *po != '-')
		po++;
	if (*po == '-')
	{
		minus = 1;
		po++;
	}
	while (*po >= '0' && *po <= '9')
	{
		ft_fucking_norme(&val, po);
		po++;
	}
	*src = po;
	(t_lluint)val > MAX_UINT32 || val < MIN_INT32 ? ft_error() : 0;
	return (minus ? -(val) : val);
}
